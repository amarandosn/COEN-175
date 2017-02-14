/*
 * File:	checker.h
 *
 * Description:	This file contains the public function declarations for the
 *		semantic checker for Simple C.
 */

# ifndef CHECKER_H
# define CHECKER_H
# include "Scope.h"

Scope *openScope();
Scope *closeScope();

Symbol *defineFunction(const std::string &name, const Type &type);
Symbol *declareFunction(const std::string &name, const Type &type);
Symbol *declareVariable(const std::string &name, const Type &type);
Symbol *checkIdentifier(const std::string &name);
Symbol *checkFunction(const std::string &name);

Type checkFuncCall(const Type &funcType, const Parameters &args);
Type checkLogicalOr(const Type &left, const Type &right);
Type checkLogicalAnd(const Type &left, const Type &right);
Type checkEqual(const Type &left, const Type &right);
Type checkNotEqual(const Type &left, const Type &right);
Type checkLEQ(const Type &left, const Type &right);
Type checkGEQ(const Type &left, const Type &right);
Type checkLT(const Type &left, const Type &right);
Type checkGT(const Type &left, const Type &right);
Type checkAdd(const Type &left, const Type &right);
Type checkSub(const Type &left, const Type &right);
Type checkMul(const Type &left, const Type &right);
Type checkDiv(const Type &left, const Type &right);
Type checkRem(const Type &left, const Type &right);
Type checkNeg(const Type &left);
Type checkNot(const Type &left);
Type checkAddr(const Type &left, bool &lvalue);
Type checkDeref(const Type &left);
Type checkSizeof(const Type &left);
Type checkPostfix(const Type &left, bool &lvalue);
Type checkScalar(const Type &left, bool &lvalue);




# endif /* CHECKER_H */
