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
static string invBinary = "invalid operands to binary operator";
static string invUnary = "invalid operands to unary operator";
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
    cout << name << ": " << type << endl;
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
    cout << name << ": " << type << endl;
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
    cout << funcType.parameters()->size() << "-" << args.size() << endl;
    //identifier must have type "function returning T"
    //result is type T
    //else, report(notFunction);
    //arguments must be predicate types, number of params and args must agree and types must be compatible
    //else, report(invArgs);
    return funcType;
}

Type checkLogicalOr(const Type &left, const Type &right)
{
    cout << left << "||" << right << endl;
    //ispredicate after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}

Type checkLogicalAnd(const Type &left, const Type &right)
{
    cout << left << "&&" << right << endl;
    //ispredicate after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}

Type checkEqual(const Type &left, const Type &right)
{
    cout << left << "==" << right << endl;
    //iscompatible after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}

Type checkNotEqual(const Type &left, const Type &right)
{
    cout << left << "!=" << right << endl;
    //iscompatible after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}

Type checkLEQ(const Type &left, const Type &right)
{
    cout << left << "<=" << right << endl;
    //identical predicate types after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}
Type checkGEQ(const Type &left, const Type &right)
{
    cout << left << ">=" << right << endl;
    //identical predicate types after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}
Type checkLT(const Type &left, const Type &right)
{
    cout << left << "<" << right << endl;
    //identical predicate types after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}
Type checkGT(const Type &left, const Type &right)
{
    cout << left << ">" << right << endl;
    //identical predicate types after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}

Type checkAdd(const Type &left, const Type &right)
{
    cout << left << "+" << right << endl;
    //if both operands have type int, result is int
    //if left is pointer(T), where T != void, and right is INT, result is pointer(T)
    //if left is INT and right is pointer(T) where T != void, then result is pointer(T)
    //else, report(invBinary);
    return left;
}
Type checkSub(const Type &left, const Type &right)
{
    cout << left << "-" << right << endl;
    //if both operands have type int, result is int
    //if left is pointer(T), where T != void, and right is INT, result is pointer(T)
    //if both operands are pointer(T) where T != void but identical for both operands, result is int
    //else, report(invBinary);   
    return left;
}
Type checkMul(const Type &left, const Type &right)
{
    cout << left << "*" << right << endl;
    //both types must be int after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}
Type checkDiv(const Type &left, const Type &right)
{
    cout << left << "/" << right << endl;
    //both types must be int after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}
Type checkRem(const Type &left, const Type &right)
{
    cout << left << "%%" << right << endl;
    //both types must be int after any promotion
    //returns int
    //else, report(invBinary);
    return left;
}
Type checkNeg(const Type &left)
{
    cout << "-" << left << endl;
    //operand must be type INT
    //result has type INT
    //else, report(invUnary);
    return left;
}
Type checkNot(const Type &left)
{
    cout << "!" << left << endl;
    //operand must have predicate type
    //result is int
    //else, report(invUnary);
    return left;
}
Type checkAddr(const Type &left, bool &lvalue)
{
    cout << "&" << left << endl;
    //operand must be lvalue
    //if operand has type T, then result has type pointer(T), not lvalue
    return left;
}
Type checkDeref(const Type &left)
{
    cout << "*" << left << endl;
    //operand must be pointer(T) after any promotion, where T != void
    //result is type T
    return left;
}
Type checkSizeof(const Type &left)
{
    cout << "sizeof(" << left << ")" << endl;
    //operand must be predicate type
    //result is int
    return left;
}

// Type checkPrefix(const Type &left)
// {
//     cout << "PREFIX: " << left << endl;
//     return left;
// }

Type checkPostfix(const Type &left, bool &lvalue)
{
    cout << "POSTFIX: " << left << endl;
    //left must be pointer(T) after any promotion where T != void
    //expression must have type int
    //result has type T
    return left;
}

Type checkScalar(const Type &left, bool &lvalue)
{
    cout << "SCALAR: " << left << endl;
    //Number case: type int, not lvalue
    //String Lit case: type "array of char", not an lvalue
    return left;
}

Type checkParen(const Type &left, bool &lvalue)
{
    cout << "Parenthesized Expression " << left << endl;
    //type is same as expression
    //is lvalue if expression itself is lvalue
    return left;
}

Type checkFuncReturn(const Type &type)
{
    cout << "Return statement: " << type << endl;
    //type of expression must be compatible with return type of enclosing function
    //else, report(invReturn);
    return type;
}

