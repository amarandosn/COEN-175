/*
 * File:	tokens.h
 *
 * Description:	This file contains the public function and variable
 *		declarations for the lexical analyzer for Simple C.
 */

# ifndef TOKENS_H
# define TOKENS_H

#define LBR 91
#define RBR 93
#define ASSIGN 61
#define ADD 43
#define SUB 45
#define MUL 42
#define DIV 47
#define MOD 37
#define ADDR 38
#define NOT 33
#define GT 62
#define LT 60

enum {
		FOR = 256, DONE, ERROR, NUM, STRING, ID, LEQ, GEQ,
		EQL, NEQ, AND, OR, AUTO, BREAK, CASE, CHAR, CONST,
		CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN,
		FLOAT, GOTO, IF, INT, LONG, REGISTER, RETURN,
		SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, 
		TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE, 
		INCREMENT, DECREMENT, PTR, NEG
};

# endif /* TOKENS_H */
