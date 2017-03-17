/*
 * File:	generator.cpp
 *
 * Description:	This file contains the public and member function
 *		definitions for the code generator for Simple C.
 *
 *		Extra functionality:
 *		- putting all the global declarations at the end
 */

/*
start with negation, not, +,-, *, call, string,
before finishing string and call for printf, can test using

int ZERO;
ZERO = 48;
int a;
a = 2 + 3;
putchar(a+ZERO);



./scc < file.c > file.s
gcc -m32 file.s file-lib.c
./a.out

*/

# include <sstream>
# include <iostream>
# include <string>
# include "generator.h"
# include "machine.h"
# include "label.h"
# include "Type.h"


using namespace std;

static unsigned maxargs;
int temp_offset;		//how much offset needs to move for temps allocated

static Label *labelPointer;
static Label *retlbl;

unsigned Label::counter = 0;

typedef std::vector<string> Strings;
Strings strs;

/*
 * Function:	operator <<
 *
 * Description:	Convenience function for writing the operand of an
 *		expression.
 */

ostream &operator <<(ostream &ostr, Expression *expr)
{
    return ostr << expr->_operand;
}

ostream &operator <<(ostream &ostr, const Label &lbl)
{
    return ostr << ".L" << lbl.number;
}

string getTemp()
{
    stringstream ss;
    temp_offset -= 4;
    ss << temp_offset << "(%ebp)";
    return ss.str();
}

void Expression::generate(bool &indirect)
{
    indirect = false;
    generate();
}

void Expression::generate()
{
    cerr << "have not finished assignment" << endl;
}

/*
 * Function:	Identifier::generate
 *
 * Description:	Generate code for an identifier.  Since there is really no
 *		code to generate, we simply update our operand.
 */

void Identifier::generate()
{
    stringstream ss;


    if (_symbol->_offset != 0)
	ss << _symbol->_offset << "(%ebp)";
    else
	ss << global_prefix << _symbol->name();

    _operand = ss.str();
}


/*
 * Function:	Number::generate
 *
 * Description:	Generate code for a number.  Since there is really no code
 *		to generate, we simply update our operand.
 */

void Number::generate()
{
    stringstream ss;
    ss << "$" << _value;
    _operand = ss.str();
}




/*
 * Function:	Call::generate
 *
 * Description:	Generate code for a function call expression, in which each
 *		argument is simply a variable or an integer literal.
 */

void Call::generate()
{
    unsigned numBytes = 0;


    for (int i = _args.size() - 1; i >= 0; i --) {
	_args[i]->generate();
	cout << "\tpushl\t" << _args[i] << endl;
	numBytes += _args[i]->type().size();
    }

    cout << "\tcall\t" << global_prefix << _id->name() << endl;

    if (numBytes > 0)
    {
	cout << "\taddl\t$" << numBytes << ", %esp" << endl;
    }
    _operand = getTemp();
    cout << "\tmovl\t%eax, " << _operand << endl;
    //add line to save %eax into a temp, which is the call's _operand
}


/*
 * If the stack has to be aligned to a certain size before a function call
 * then we cannot push the arguments in the order we see them.  If we had
 * nested function calls, we cannot guarantee that the stack would be
 * aligned.
 *
 * Instead, we must know the maximum number of arguments so we can compute
 * the size of the frame.  Again, we cannot just move the arguments onto
 * the stack as we see them because of nested function calls.  Rather, we
 * have to generate code for all arguments first and then move the results
 * onto the stack.  This will likely cause a lot of spills.
 *
 * For now, since each argument is going to be either a number of in
 * memory, we just load it into %eax and then move %eax onto the stack.
 */

/*
void Call::generate()
{
    if (_args.size() > maxargs)
	maxargs = _args.size();

    for (int i = _args.size() - 1; i >= 0; i --) {
	_args[i]->generate();
	cout << "\tmovl\t" << _args[i] << ", %eax" << endl;
	cout << "\tmovl\t%eax, " << i * SIZEOF_ARG << "(%esp)" << endl;
    }

    cout << "\tcall\t" << global_prefix << _id->name() << endl;
}
*/



/*
 * Function:	Assignment::generate
 *
 * Description:	Generate code for this assignment statement, in which the
 *		right-hand side is an integer literal and the left-hand
 *		side is an integer scalar variable.  Actually, the way
 *		we've written things, the right-side can be a variable too.
 */

void Assignment::generate()
{
    bool indirect;
    _left->generate(indirect);
    _right->generate();
   

    cout << "\tmovl\t" << _right << ", %eax" << endl;
    if(indirect)
    {
        cout << "\tmovl\t" << _left << ", %ecx" << endl;
        if(_right->type().size() == 1)
        {
            cout << "\tmovb\t%al, (%ecx)" << endl;
        }
        else
        {
            cout << "\tmovl\t%eax, (%ecx)" << endl;
        }
    }
    else
    {
        if(_right->type().size() == 1)
        {
            cout << "\tmovb\t%al, "<< _left << endl;
        }
        else
        {
            cout << "\tmovl\t%eax, "<< _left << endl;
        }
    }


}


/*
 * Function:	Block::generate
 *
 * Description:	Generate code for this block, which simply means we
 *		generate code for each statement within the block.
 */

void Block::generate()
{
    for (unsigned i = 0; i < _stmts.size(); i++)
	_stmts[i]->generate();
}


/*
 * Function:	Function::generate
 *
 * Description:	Generate code for this function, which entails allocating
 *		space for local variables, then emitting our prologue, the
 *		body of the function, and the epilogue.
 */

void Function::generate()
{
    int offset = 0;
    
    Label l;
    labelPointer = &l;
    retlbl = new Label();

    /* Generate our prologue. */

    allocate(offset);
    
    cout << global_prefix << _id->name() << ":" << endl;
    cout << "#FUNCTION PROLOGUE" << endl;
    cout << "\tpushl\t%ebp" << endl;
    cout << "\tmovl\t%esp, %ebp" << endl;
    cout << "\tsubl\t$" << _id->name() << ".size, %esp" << endl;


    /* Generate the body of this function. */

    maxargs = 0;
    temp_offset = offset;
    cout << "#FUNCTION BODY" << endl;
    _body->generate();
    offset = temp_offset;

    offset -= maxargs * SIZEOF_ARG;

    while ((offset - PARAM_OFFSET) % STACK_ALIGNMENT)
	offset --;

    cout << *retlbl << ":" << endl;

    /* Generate our epilogue. */
    cout << "#FUNCTION EPILOGUE" << endl;
    cout << "\tmovl\t%ebp, %esp" << endl;
    cout << "\tpopl\t%ebp" << endl;
    cout << "\tret" << endl;
   

    cout << "\t.globl\t" << global_prefix << _id->name() << endl;
    cout << "\t.set\t" << _id->name() << ".size, " << -offset << endl;

    cout << endl;
}


/*
 * Function:	generateGlobals
 *
 * Description:	Generate code for any global variable declarations.
 */

void generateGlobals(const Symbols &globals)
{
    if (globals.size() > 0)
	cout << "\t.data" << endl;

    for (unsigned i = 0; i < globals.size(); i ++) {
	cout << "\t.comm\t" << global_prefix << globals[i]->name();
	cout << ", " << globals[i]->type().size();
	cout << ", " << globals[i]->type().alignment() << endl;
    }
    
    //print string literals here
    //for loop to loop through vector of strings
    for(unsigned j = 0; j < strs.size(); j++)
    {
        cout << strs[j];
    }
}



void Address::generate()
{
    bool indirect;
    cout << "#ADDRESS" << endl;
    _expr->generate(indirect);
    //_right->generate();

    if(indirect)
    {
        //& → * → p case
        _operand = _expr->_operand; //&*p is just p, so nothing generated
        
    }
    else
    {
        _operand = getTemp();       //get next temp and set it in memory
        cout << "\tleal\t" << _expr << ", %eax" << endl;
        cout << "\tmovl\t%eax, " << this << endl;
    
    }
}

void Dereference::generate(bool &indirect)
{
    indirect = true;
    cout << "#DEREFINDIRECT" << endl;
    _expr->generate();
    _operand = _expr->_operand;
}


void Dereference::generate()
{
    cout << "#DEREF" << endl;
    _expr->generate();
    _operand = getTemp();
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    if(_type.size() == 1)
    {
      cout << "\tmovzbl\t(%eax), %eax" << endl;
      
    }
    else
    {
	cout << "\tmovl\t(%eax), %eax" << endl;
	cout << "\tmovl\t%eax," << this << endl;
    }
    
}

void Negate::generate()
{
    cout << "#NEGATE" << endl;
    _expr->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tnegl\t" << "%eax" << endl;
    //string temp = getTemp();
    cout << "\tmovl\t %eax, " << _operand << endl;
}

void Not::generate()
{
    cout << "#NOT" << endl;
    _expr->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tcmpl\t" << "$0, %eax" << endl;
    cout << "\tsete\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t %eax, " << _operand << endl;
}

void Add::generate()
{
    cout << "#ADD" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\taddl\t" << _right << ", %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl; 
}

void Subtract::generate()
{
    cout << "#SUB" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tsubl\t" << _right << ", %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void Multiply::generate()
{
    cout << "#MULTIPLY" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\timull\t" << _right << ", %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void Remainder::generate()
{
    cout << "#REMAINDER" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tmovl\t" << _right << ", %ecx" << endl;
    cout << "\tcltd" << endl;
    cout << "\tidivl\t" << "%ecx" << endl;
    cout << "\tmovl\t%edx, " << _operand << endl;
}

void Divide::generate()
{	
    cout << "#DIVIDE" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tmovl\t" << _right << ", %ecx" << endl;
    cout << "\tcltd" << endl;
    cout << "\tidivl\t" << "%ecx" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void LessThan::generate()
{
    cout << "#LESS THAN" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetl\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void GreaterThan::generate()
{
    cout << "#GREATER THAN" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetg\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void LessOrEqual::generate()
{
    cout << "#LESS OR EQUAL" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetle\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void GreaterOrEqual::generate()
{
    cout << "#GREATER OR EQUAL" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl; 
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetge\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void Equal::generate()
{
    cout << "#EQUAL" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsete\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void NotEqual::generate()
{
    cout << "#NOT EQUAL" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetne\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void LogicalAnd::generate()
{
    /*
    
    */
    cout << "#LOGICALAND" << endl;
    _left->generate();
    _right->generate();
    _operand = getTemp();
    Label *lbl = new Label();
    if(lbl)
    {
     
      //left
      cout << "\tmovl\t" << _left << ", %eax" << endl;
      cout << "\tcmpl\t$0, %eax" << endl;
      cout << "\tje\t" << *lbl  << endl;
      //right
      cout << "\tmovl\t" << _right << ", %eax" << endl;
      cout << "\tcmpl\t$0, %eax" << endl;
      
      //LABEL
      cout << *lbl << ":" << endl;
      cout << "\tsetne\t%al" << endl;
      cout << "\tmovzbl\t%al, %eax" << endl;
      cout << "\tmovl\t%eax, " << _operand << endl;
    }
}

void LogicalOr::generate()
{
    /*
    
    */
    //_left->generate();
    //_right->generate();
    cout << "#LOGICALOR" << endl;
    _operand = getTemp();
    Label *lbl = new Label();
    if(lbl)
    { 
      
      //left
      _left->generate();
      cout << "\tmovl\t" << _left << ", %eax" << endl;
      cout << "\tcmpl\t$0, %eax" << endl;
      cout << "\tjne\t" << *lbl  << endl;
      _right->generate();
      //right
      cout << "\tmovl\t" << _right << ", %eax" << endl;
      cout << "\tcmpl\t$0, %eax" << endl;
      
      //LABEL
      cout << *lbl << ":" << endl;
      cout << "\tsetne\t%al" << endl;
      cout << "\tmovzbl\t%al, %eax" << endl;
      cout << "\tmovl\t%eax, " << _operand << endl;
    }
}

void Return::generate()
{
    /*
    _operand = *retlbl;
    */
    //need global Label *retlbl;
    cout << "#RETURN" << endl;
    _expr->generate();
   
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tjmp\t" << *retlbl << endl;
}

void String::generate()
{
    /*
    print this: .l3:    .asciz "%d\n"
    in use:     leal    .l3, %eax
    */

    cout << "#STRING" << endl;
    stringstream ss;
    Label *lbl = new Label();
    ss << *lbl;
    _operand = ss.str();
    ss << ":\t.asciz " << _value << endl;
    strs.push_back(ss.str());
    
    
}


void Promote::generate()
{
    /*
    if size == 1, extend value to long and store into a temp
    */ 
    //sign extend value of subexpression
    cout << "#PROMOTE" << endl;
    _expr->generate();
    
    if(_expr->type().size() == 1)
    {
        //extend value to long, store into temp
        _operand = getTemp();
        cout << "\tmovsbl\t" << _expr << ", %eax" << endl;
        cout << "\tmovl\t" << "%eax, " << _operand << endl;
    }
}

void While::generate()
{
    /*
    in notes
    */
    Label *loop = new Label();
    Label *exitloop = new Label();

    cout << "#WHILE" << endl;
    cout << *loop << ":" << endl;
    _expr->generate();
    
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tcmpl\t$0, %eax" << endl;
    cout << "\tje\t" << *exitloop << endl;
    _stmt->generate();
    cout << "\tjmp\t" << *loop << endl;
    cout << *exitloop << ":" << endl;
    
}

void For::generate()
{
    /*
    
    */
    Label *loop = new Label();
    Label *exitloop = new Label();

    cout << "#FOR" << endl;
    _init->generate();
    cout << *loop << ":" << endl;
    
    _expr->generate();
    
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tcmpl\t$0, %eax" << endl;
    cout << "\tje\t" << *exitloop << endl;
    _stmt->generate();
    _incr->generate();
    cout << "\tjmp\t" << *loop << endl;
    cout << *exitloop << ":" << endl;



    
}

void If::generate()
{
    /*
    in notes
    */
    Label *lbl = new Label();
    Label *lblelse = new Label();
    cout << "#IF" << endl;
    _expr->generate();
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tcmpl\t$0, %eax" << endl;
    cout << "\tje\t" << *lblelse << endl;
    _thenStmt->generate();
    cout << "\tjmp\t" << *lbl << endl;
    
    cout << *lblelse << ":" << endl;
    if(_elseStmt)
    {
        _elseStmt->generate();
    }
    cout << *lbl << ":" << endl;
}