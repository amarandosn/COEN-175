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
# include "generator.h"
# include "machine.h"
# include "label.h"


using namespace std;

static unsigned maxargs;
int temp_offset;		//how much offset needs to move for temps allocated

static Label *labelPointer;
unsigned Label::counter = 0;

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


# if STACK_ALIGNMENT == 4

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
	cout << "\taddl\t$" << numBytes << ", %esp" << endl;
}

# else

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
# endif


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
    _left->generate();
    _right->generate();

    cout << "\tmovl\t" << _right << ", %eax" << endl;
    cout << "\tmovl\t%eax, " << _left << endl;
}


/*
 * Function:	Block::generate
 *
 * Description:	Generate code for this block, which simply means we
 *		generate code for each statement within the block.
 */

void Block::generate()
{
    for (unsigned i = 0; i < _stmts.size(); i ++)
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


    /* Generate our epilogue. */
    cout << "#FUNCTION EPILOGUE" << endl;
    cout << "\tmovl\t%ebp, %esp" << endl;
    cout << "\tpopl\t%ebp" << endl;
    cout << "\tret" << endl << endl;

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
}

void Expression::generate()
{
    Cerr <”have not finished assignment” << endl;
}

void Address::generate()
{
    bool indirect;
    _expr->generate(indirect);
    if(indirect)
    {
        //& → * → p case
        _operand = _expr->_operand; //&*p is just p, so nothing generated
    }
    else
    {
        _operand = getTemp();       //get next temp and set it in memory
        cout << "\tleal\t" << _expr << endl;
        cout << ", " << this << endl;    //break into two parts
    }
}

void Dereference::generate(bool &indirect)
{
    indirect = true;
    _expr->generate();
    _operand = _expr->_operand;
}

string getTemp()
{
    stringstream ss;
    temp_offset -= 4;
    ss << temp_offset << "(%ebp)";
    return ss.str();
}


void Negate::generate()
{
    _expr->generate();
    _operand = getTemp();
    cout << "#NEGATE" << endl;
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tnegl\t" << "%eax" << endl;
    //string temp = getTemp();
    cout << "\tmovl\t %eax, " << _operand << endl;
}

void Not::generate()
{
    _expr->generate();
    _operand = getTemp();
    cout << "#NOT" << endl;
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tcmpl\t" << "$0, %eax" << endl;
    cout << "\tsete\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t %eax, " << _operand << endl;
}

void Add::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#ADD" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\taddl\t" << _right << ", %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl; 
}

void Subtract::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#SUB" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tsubl\t" << _right << ", %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void Multiply::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#MULTIPLY" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\timull\t" << _right << ", %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void Remainder::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#REMAINDER" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tmovl\t" << _right << ", %ecx" << endl;
    cout << "\tcltd" << endl;
    cout << "\tidivl\t" << "%ecx" << endl;
    cout << "\tmovl\t%edx, " << _operand << endl;
}

void Divide::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#DIVIDE" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tmovl\t" << _right << ", %ecx" << endl;
    cout << "\tcltd" << endl;
    cout << "\tidivl\t" << "%ecx" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void LessThan::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#LESS THAN" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetl\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void GreaterThan::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#GREATER THAN" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetg\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void LessOrEqual::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#LESS OR EQUAL" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetle\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void GreaterOrEqual::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#GREATER OR EQUAL" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetge\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void Equal::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#EQUAL" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsete\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void NotEqual::generate()
{
    _left->generate();
    _right->generate();
    _operand = getTemp();
    cout << "#NOT EQUAL" << endl;
    cout << "\tmovl\t" << _left << ", %eax" << endl;
    cout << "\tcmpl\t" << _right << ", %eax" << endl;
    cout << "\tsetne\t%al" << endl;
    cout << "\tmovzbl\t%al, %eax" << endl;
    cout << "\tmovl\t%eax, " << _operand << endl;
}

void Return::generate()
{
    /*
    
    */
}