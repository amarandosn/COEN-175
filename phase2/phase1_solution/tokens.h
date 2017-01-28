/*
 * File:	tokens.h
 *
 * Description:	This file contains the public function and variable
 *		declarations for the lexical analyzer for Simple C.
 */

# ifndef TOKENS_H
# define TOKENS_H

enum {
		FOR = 256, DONE, ERROR, NUM, STRING, ID, LEQ, GEQ,
		EQL, NEQ, AND, OR, AUTO, BREAK, CASE, CHAR, CONST,
		CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN,
		FLOAT, GOTO, IF, INT, LONG, REGISTER, RETURN,
		SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, 
		TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE
};

# endif /* TOKENS_H */