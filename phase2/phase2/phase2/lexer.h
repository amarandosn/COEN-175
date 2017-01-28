/*
 * File:	lexer.h
 *
 * Description:	This file contains the public function and variable
 *		declarations for the lexical analyzer for Simple C.
 */

# ifndef LEXER_H
# define LEXER_H

extern int lineno, numerrors;

int lexan(std::string &lexbuf);
void report(const std::string &str, const std::string &arg = "");

void expression();
void exp_and();
void exp_eq();
void exp_cmp();
void exp_a();
void exp_b();
void exp_unary();
void exp_d();
void exp_id();
void exp_list();
void assignment();
void statement();
void pointers();
//void global_declaration();
void global_declarator();
void specifier();
void declarations();
void declarator();
void declaration();
void declarationList();
void declaratorList();
void parameter();
void parameters();
void parameterList();
void remainingDecls();



# endif /* LEXER_H */
