/*
 * File:	checker.cpp
 *
 * Description:	This file contains the public and private function and
 *		variable definitions for the semantic checker for Simple C.
 *
 *		If a symbol is redeclared, the existing declaration is
 *		retained and the redeclaration discarded.  This behavior
 *		seems to be consistent with GCC, and who are we to argue
 *		with GCC?
 *
 *		Extra functionality:
 *		- inserting an undeclared symbol with the error type
 */

# include <iostream>
# include "lexer.h"
# include "checker.h"
# include "nullptr.h"
# include "tokens.h"
# include "Symbol.h"
# include "Scope.h"
# include "Type.h"

# define FUNCDEFN 1


using namespace std;

static Scope *outermost, *toplevel;
static const Type error;

static string redefined = "redefinition of '%s'";
static string redeclared = "redeclaration of '%s'";
static string conflicting = "conflicting types for '%s'";
static string undeclared = "'%s' undeclared";
static string void_object = "'%s' has type void";

//phase 4:
static string invReturn = "invalid return type";
static string invTest = "invalid type for test expression";
static string lvalueReq = "lvalue required in expression";
static string invBinary = "invalid operands to binary %s";
static string invUnary = "invalid operands to unary %s";
static string notFunction = "called object is not a function";
static string invArgs = "invalid arguments to called function";


/*
 * Function:	checkIfVoidObject
 *
 * Description:	Check if TYPE is a proper use of the void type (if the
 *		specifier is void, then the indirection must be nonzero or
 *		the kind must be a function).  If the type is proper, it is
 *		returned.  Otherwise, the error type is returned.
 */

static Type checkIfVoidObject(const string name, const Type &type)
{
    if (type.specifier() != VOID)
	return type;

    if (type.indirection() == 0 && !type.isFunction()) {
	report(void_object, name);
	return error;
    }

    return type;
}


/*
 * Function:	openScope
 *
 * Description:	Create a scope and make it the new top-level scope.
 */

Scope *openScope()
{
    toplevel = new Scope(toplevel);

    if (outermost == nullptr)
	outermost = toplevel;

    return toplevel;
}


/*
 * Function:	closeScope
 *
 * Description:	Remove the top-level scope, and make its enclosing scope
 *		the new top-level scope.
 */

Scope *closeScope()
{
    Scope *old = toplevel;
    toplevel = toplevel->enclosing();
    return old;
}


/*
 * Function:	defineFunction
 *
 * Description:	Define a function with the specified NAME and TYPE.  A
 *		function is always defined in the outermost scope.
 */

Symbol *defineFunction(const string &name, const Type &type)
{
    Symbol *symbol = declareFunction(name, type);

    if (symbol->_attributes & FUNCDEFN)
	report(redefined, name);

    symbol->_attributes = FUNCDEFN;
    return symbol;
}


/*
 * Function:	declareFunction
 *
 * Description:	Declare a function with the specified NAME and TYPE.  A
 *		function is always declared in the outermost scope.  Any
 *		redeclaration is discarded.
 */

Symbol *declareFunction(const string &name, const Type &type)
{
    //cout << name << ": " << type << endl;
    Symbol *symbol = outermost->find(name);

    if (symbol == nullptr) {
	symbol = new Symbol(name, type);
	outermost->insert(symbol);

    } else if (type != symbol->type()) {
	report(conflicting, name);
	delete type.parameters();

    } else
	delete type.parameters();

    return symbol;
}


/*
 * Function:	declareVariable
 *
 * Description:	Declare a variable with the specified NAME and TYPE.  Any
 *		redeclaration is discarded.
 */

Symbol *declareVariable(const string &name, const Type &type)
{
    //cout << name << ": " << type << endl;
    Symbol *symbol = toplevel->find(name);

    if (symbol == nullptr) {
	symbol = new Symbol(name, checkIfVoidObject(name, type));
	toplevel->insert(symbol);

    } else if (outermost != toplevel)
	report(redeclared, name);

    else if (type != symbol->type())
	report(conflicting, name);

    return symbol;
}


/*
 * Function:	checkIdentifier
 *
 * Description:	Check if NAME is declared.  If it is undeclared, then
 *		declare it as having the error type in order to eliminate
 *		future error messages.
 */

Symbol *checkIdentifier(const string &name)
{
    Symbol *symbol = toplevel->lookup(name);

    if (symbol == nullptr) {
	report(undeclared, name);
	symbol = new Symbol(name, error);
	toplevel->insert(symbol);
    }

    return symbol;
}


/*
 * Function:	checkFunction
 *
 * Description:	Check if NAME is a previously declared function.  If it is
 *		undeclared, then implicitly declare it.
 */

Symbol *checkFunction(const string &name)
{
    Symbol *symbol = toplevel->lookup(name);

    if (symbol == nullptr)
	symbol = declareFunction(name, Type(INT, 0, nullptr));

    return symbol;
}

Type checkFuncCall(const Type &funcType, const Parameters &args)
{
    //cout << funcType.parameters()->size() << "-" << args.size() << endl;
    //cout << "checkFuncCall: " << funcType << ", arg size: " << args.size() << endl;
    //identifier must have type "function returning T"
    //result is type T
    //else, report(notFunction);
    //arguments must be predicate types, number of params and args must agree and types must be compatible
    //else, report(invArgs);
    //cout << "checkFuncCall 2" << endl;
    if(funcType == Type())
    {
        return Type();
    }
    //cout << "checkFuncCall 3" << endl;
    Type t = Type();
    if(funcType.isFunction())
    {
        t = Type(funcType.specifier());
    }
    else
    {
        //funcType = Type();
        report(notFunction);
        return Type();
    }
    //cout << "checkFuncCall 4" << endl;
    //if params null
    Parameters *p = funcType.parameters();
    if(p != NULL)
    {
        if(funcType.parameters()->size() == args.size())
        {
            //cout << "checkFuncCall: params size matches args" << endl;
            for(unsigned i = 0; i < args.size(); i++)
            {
                if(args[i].isPredicate())
                {
                    if(t.isCompatible((*p)[i],args[i]))  //is compatible
                    {
                        //cout << "checkFuncCall: iscompatible: " << (*p)[i] << ", " << args[i] << endl;                                               
                        t = Type(funcType.specifier(), funcType.indirection());
                        //cout << "checkFuncCall: function type: " << t << endl;
                        return t;
                    }
                    else
                    {
                        //not compatible
                        report(invArgs);
                        t = Type();
                    }
                }
                else
                {
                    //not predicates
                    report(invArgs);
                    t = Type();
                }

            }
            return Type(funcType.specifier(), funcType.indirection());
        }
        else
        {
            //# of params and args don't match
            report(invArgs);
            return Type();
        }
    }
    
    return t;
      
}

Type checkLogicalOr(const Type &left, const Type &right)
{
    //cout << "checkLogicalOr(): " << left << "||" << right << endl;
    //ispredicate after any promotion
    //cout << "checkOr 1" << endl;
    if(left == Type() || right == Type())
    {
        //cout << "checkOr 2" << endl;
        return Type();
    }
    //cout << "checkOr 3" << endl;
    Type t, s;
    t = left.promote();
    s = right.promote();

    //cout << "checkOr 4" << endl;
    if(!t.isPredicate() || !s.isPredicate())
    {
        //cout << "checkOr 5" << endl;
        report(invBinary, "||");
        return Type();
    }
    //cout << "checkOr 6" << endl;
    t = Type(INT);

    return t;
}

Type checkLogicalAnd(const Type &left, const Type &right)
{
    //cout << "checkLogicalAnd(): " << left << "&&" << right << left.isFunction() << endl;
    //ispredicate after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }

    Type t, s;
    t = left.promote();
    s = right.promote();


    if(!t.isPredicate() || !s.isPredicate())
    {
        report(invBinary, "&&");
        return Type();
    }

    //t = Type(INT);

    return Type(INT);
}

Type checkEqual(const Type &left, const Type &right)
{
    //cout << left << "==" << right << endl;

    //iscompatible after any promotion
    //returns int
    //else, report(invBinary);

    if(left == Type() || right == Type())
    {
        return Type();
    }
    Type t, s, x;
    t = left.promote();
    s = right.promote();

    if(!x.isCompatible(t, s))
    {
        report(invBinary, "==");
        return Type();
    }

    t = Type(INT);
    return t;
}

Type checkNotEqual(const Type &left, const Type &right)
{
    //cout << left << "!=" << right << endl;
    //iscompatible after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }
    Type t, s, x;
    t = left.promote();
    s = right.promote();

    if(!x.isCompatible(t, s))
    {
        report(invBinary, "!=");
        return Type();
    }

    t = Type(INT);
    return t;
}

Type checkLEQ(const Type &left, const Type &right)
{
    //cout << left << "<=" << right << endl;
    //identical predicate types after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }

    Type t, s;
    t = left.promote();
    s = right.promote();

    if(t == s)
    {   
        t = Type(INT);
        return t;
    }
    else
    {
        report(invBinary, "<=");
        t = Type();
    }
    return t;
}
Type checkGEQ(const Type &left, const Type &right)
{
   // cout << left << " >= " << right << endl;
    //identical predicate types after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }    

    Type t, s;
    t = left.promote();
    s = right.promote();

    if(t == s)
    {   
        t = Type(INT);
        return t;
    }
    else
    {
        report(invBinary, ">=");
        t = Type();
    }
    return t;
}
Type checkLT(const Type &left, const Type &right)
{
    //cout << left << " < " << right << endl;
    //identical predicate types after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }    

    Type t, s;
    t = left.promote();
    s = right.promote();
    //cout << "checkLT 1" << endl;
    if(t == s)
    {   
        //cout << "checkLT 2" << t << ", " << s << endl;
        t = Type(INT);
        return t;
    }
    else
    {
        //cout << "checkLT 3" << endl;
        report(invBinary, "<");
        t = Type();
    }
    //cout << "checkLT 4" << endl;
    return t;
}
Type checkGT(const Type &left, const Type &right)
{
    //cout << left << " > " << right << endl;
    //identical predicate types after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }    

    Type t, s;
    t = left.promote();
    s = right.promote();

    if(t == s)
    {   
        t = Type(INT);
        return t;
    }
    else
    {
        report(invBinary, ">");
        t = Type();
    }
    return t;
}

Type checkAdd(const Type &left, const Type &right)
{

    //cout << "checkAdd(): " << left << " + " << right << endl;
    //if both operands have type int, result is int
    //if left is pointer(T), where T != void, and right is INT, result is pointer(T)
    //if left is INT and right is pointer(T) where T != void, then result is pointer(T)
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }   

    Type t, s;
    t = left.promote();
    s = right.promote();

    if(t == Type(INT) && s == Type(INT))
    {
        //cout << "checkSub 1" << endl;
        return Type(INT);
    }
    else if(t.isPointer() && !t.isPtrToNull() && s == Type(INT))
    {
        //cout << "checkSub 2" << endl;
        return t;
    }
    else if(s.isPointer() && !s.isPtrToNull() && t == Type(INT))
    {
        //cout << "checkAdd 3" << endl;
        return s;
    }
    else 
    {
        //cout << "checkAdd 4" << endl;
        report(invBinary, "+");
        t = Type();
    }
        
    return t;
}
Type checkSub(const Type &left, const Type &right)
{
    //cout << "checkSub(): " << left << " - " << right << endl;
    //if both operands have type int, result is int
    //if left is pointer(T), where T != void, and right is INT, result is pointer(T)
    //if both operands are pointer(T) where T != void but identical for both operands, result is int
    //else, report(invBinary);   
    if(left == Type() || right == Type())
    {
        return Type();
    }   

    Type t, s;
    t = left.promote();
    s = right.promote();

    if(t == Type(INT) && s == Type(INT))
    {
        //cout << "checkSub 1" << endl;
        return Type(INT);
    }
    else if(t.isPointer() && !t.isPtrToNull() && s == Type(INT))
    {
        //cout << "checkSub 2" << endl;
        return t;
    }
    else if(t.isPointer() && !t.isPtrToNull() && s.isPointer() && !s.isPtrToNull())
    {
        //cout << "checkSub 3" << endl;
        if(s == t)
        {
            //cout << "checkSub 4" << endl;
            return Type(INT);
        }
        else
        {
            report(invBinary, "-");
            t = Type();
        }
    }
    else 
    {
        //cout << "checkSub 5" << endl;
        report(invBinary, "-");
        t = Type();
    }
        
    return t;
}
Type checkMul(const Type &left, const Type &right)
{
    //cout << "checkMul(): " <<left << " * " << right << endl;
    //both types must be int after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }   

    Type t, s;
    t = left.promote();
    s = right.promote();

    if(t == Type(INT) && s == Type(INT))
    {
        return Type(INT);
    }
    else
    {
        report(invBinary, "*");
        t = Type();
    }
    return t;
}
Type checkDiv(const Type &left, const Type &right)
{
    //cout << "checkDiv(): " << left << " / " << right << endl;
    //both types must be int after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }   

    Type t, s;
    t = left.promote();
    s = right.promote();

    if(t == Type(INT) && s == Type(INT))
    {
        return Type(INT);
    }
    else
    {
        report(invBinary, "*");
        t = Type();
    }
    return t;
}
Type checkRem(const Type &left, const Type &right)
{
    //cout << "checkRem(): " << left << " %% " << right << endl;
    //both types must be int after any promotion
    //returns int
    //else, report(invBinary);
    if(left == Type() || right == Type())
    {
        return Type();
    }   

    Type t, s;
    t = left.promote();
    s = right.promote();

    if(t == Type(INT) && s == Type(INT))
    {
        return Type(INT);
    }
    else
    {
        report(invBinary, "%%");
        t = Type();
    }
    return t;
}
Type checkNeg(const Type &left)
{
    //cout << "checkNeg(): " << "-" << left << endl;
    //operand must be type INT
    //result has type INT
    //else, report(invUnary);
    if(left == Type())
    {
        return Type();
    }   


    if(left == Type(INT))
        return left;
    else
    {
        report(invUnary, "-");
        return Type();
    }
    return left;
}
Type checkNot(const Type &left)
{
    //cout << "checkNot(): " << "!" << left << endl;
    //operand must have predicate type
    //result is int
    //else, report(invUnary);
    if(left == Type())
    {
        return Type();
    }   

    if(left.isPredicate())
        return Type(INT);
    else
    {
        report(invUnary, "!");
        return Type();
    }
    return left;
}
Type checkAddr(const Type &left, bool &lvalue)
{
    //cout << "checkAddr(): &" << left << " lvalue: " << lvalue << endl;
    //operand must be lvalue
    //if operand has type T, then result has type pointer(T), not lvalue
    if(left == Type())
    {
        return Type();
    } 
    if(!lvalue)
    {
        report(lvalueReq);
        return Type();
    }
    else
    {
        return Type(left.specifier(), left.indirection()+1);
    }
    return left;
}
Type checkDeref(const Type &left)
{
   // cout << "checkDeref(): " << "*" << left << endl;
    //operand must be pointer(T) after any promotion, where T != void
    //result is type T

    if(left == Type())
    {
        return Type();
    }   
    Type t;
    t = left.promote();

    if(t.isPointer() && !t.isPtrToNull())
    {
        //cout << "checkDeref(): not pointer to void" << endl;
        t = Type(t.specifier(), t.indirection()-1);
        //cout << "checkDeref(): deref type: " << t << endl;
        return t;
    }
    else
    {
        report(invUnary, "*");
        return Type();
    }

    return left;
}
Type checkSizeof(const Type &left)
{
    cout << "sizeof(" << left << ")" << endl;
    //operand must be predicate type
    //result is int
    if(left == Type())
    {
        return Type();
    }   

    if(left.isPredicate())
        return Type(INT);
    else
    {
        report(invUnary, "sizeof");
        return Type();
    }
    return left;
}

// Type checkPrefix(const Type &left)
// {
//     cout << "PREFIX: " << left << endl;
//     return left;
// }

Type checkPostfix(const Type &left, const Type &expr, bool &lvalue)
{
    //cout << "checkPostfix(): " << left << ", " << expr << endl;
    //left must be pointer(T) after any promotion where T != void
    //expression must have type int
    //result has type T
    if(left == Type() || expr == Type())
    {
        return Type();
    }   
    Type t, s;
    t = left.promote();
    s = expr.promote();
    if(t.isPointer() && !t.isPtrToNull() && (s == Type(INT)))
    {
        //cout << "checkPostFix() 1" << endl;
        return Type(t.specifier(), t.indirection()-1);
    }
    else
    {
        report(invBinary, "[]");
        return Type();
    }


    return left;
}

// Type checkScalar(const Type &left, string name, int length)
// {
//     cout << "SCALAR: " << left << endl;
//     //Number case: type int, not lvalue
//     //String Lit case: type "array of char", not an lvalue

//     if(name == STRING)

//     return left;
// }

Type checkParen(const Type &left, const Type &expr, bool &lvalue)
{
    //cout << "checkParen(): "  << left << endl;
    //type is same as expression
    //is lvalue if expression itself is lvalue
    if(left == Type() || expr == Type())
    {
        return Type();
    }
    if(left == expr)
        return left;


    return left;
}

void checkFuncReturn(const Type &type, const Type &ret)
{
    //cout << "checkFuncReturn(): Return Type: "<< ret << ", Function Type: " << type << endl;
    //type of expression must be compatible with return type of enclosing function
    //else, report(invReturn);
   // cout << "checkFuncReturn() 1" << endl;
    if(type == Type() || ret == Type())
        return;
    Type t = type;
    //Type t1 = type.promote();
    //cout << "checkFuncReturn() 2" << endl;
    //Parameters *params = new Parameters;
    if(t.isFunction())
    {
        
        t = checkFuncCall(t, *(t.parameters()));
        //cout << "checkFuncReturn(): Function is function type: " << t << endl;
    }
    // if(t.isFunction())
    // {
    //     cout << "checkFuncReturn() 2: return val is function" << endl;
    //     params = t.parameters();
    //     t = checkFuncCall(t, *params);
        
    // }
    //cout << "checkFuncReturn() 3: Type Type: "<< t << ", Return Type: " << ret << endl;
    //t = checkFuncCall(t, *params);
    //cout << "checkFuncReturn() 4" << endl;

    if(!t.isCompatible(t,ret))
    {
        //cout << "checkFuncReturn() 4" << endl;
        report(invReturn);
        return;
    }
   // cout << "checkFuncReturn(): was compatible." << endl;

    return;
}

void checkWFI(const Type &type)
{
    //cout << "checkWFI(): " << type << endl;
    if(type == Type())
    {
        //cout << "In checkWFI(): Type is error" << endl;
        report(invTest);
        return;
    }
    Type t;
    t = type.promote();
    //cout << "checkWFI():2  " << t << endl;
    if(!t.isPredicate())
        report(invTest);
    return;
}

void checkAssignment(const Type &left, const Type &right, bool &lvalue)
{
    
    //lhs must be lvalue, else report(lvalueReq);
    //types of two sides must be compatible

    if(left == Type() || right == Type())
        return;
    //cout << "checkAssignment(): " << left << ", " << right << " lvalue: " << lvalue << endl;
    if(!lvalue)
    {
        report(lvalueReq);
        return;
    }
    
    Type t;
    if(!t.isCompatible(left, right))
        report(invBinary, "=");

    return;

}