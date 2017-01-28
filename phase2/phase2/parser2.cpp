/*parser*/

# include <cstdio>
# include <string>
# include <iostream>
# include <cstdlib>
# include "lexer.h"
# include "tokens.h"

/*
g++ parser.cpp lexer.cpp
./a.out < test.txt

Common mistakes:
-can parse one verbal declaration but not multiple ones
-can do int x; but not int x,y;
-unary operators: forget to do recursive, can't do "**p;"
-expression goes in brackets
*/

using namespace std;

int lookahead;
string lexbuf;

void match(int t) {
	if(lookahead == t)
	{
		lookahead = lexan(lexbuf);
	}
	else
	{
		cout << "MATCH ERROR--------===================--: " << lookahead << "," << t << endl;
		return;
	}
	return; 
}

void expression(){
	cout << "EXPRESSION: " << lookahead << endl;
	exp_and();	
	while(lookahead == OR){
		cout << "expression(): " << lookahead << endl;
		match(lookahead);
		exp_and();
		cout << "or" << endl;
	}	
	
}

void exp_and(){
	cout << "exp_and" << endl;
	exp_eq();
	while(lookahead == AND){
		match(lookahead);
		exp_eq();
		cout << "and" << endl;
	}
}

void exp_eq(){
	cout << "eq " << lookahead << endl;
	exp_cmp();
	while(lookahead == EQL || lookahead == NEQ){
		int tmp = lookahead;
		match(lookahead);
		exp_cmp();
		if(tmp == EQL)
			cout << "eql" << endl;
		else if(tmp == NEQ)
			cout << "neq" << endl;
	}	
	
}

void exp_cmp(){
	cout << "cmp" << endl;
	exp_a();
	while(lookahead == '<' || lookahead == '>' || lookahead == LEQ || lookahead == GEQ)
	{
		int tmp = lookahead;
		match(lookahead);
		exp_a();
		
		

		switch(tmp) {
			case '<':
				cout << "ltn" << endl;
				break;
			case '>':
				cout << "gtn" << endl;
				break;
			case LEQ:
				cout << "leq" << endl;
				break;
			case GEQ:
				cout << "geq" << endl;
				break;
		}
	}
}

void exp_a(){
	cout << "a: " << lookahead << endl;
	exp_b();
	//while loop, call exp_b inside
	while(lookahead == ADD || lookahead == SUB){
		
		int tmp = lookahead;
		match(lookahead);
		exp_b();
		cout << "exp_a(): " << lookahead << endl;
		if(tmp == ADD)
		{
			//match(lookahead);
			cout << "add" << endl;
		}
		else if(tmp == SUB)
		{
			//match(lookahead);
			cout << "sub" << endl;
		}
		
	}
}

void exp_b(){
	cout << "b: " << lookahead << endl;
	exp_unary();
	
	while(lookahead == '*' || lookahead == '/' || lookahead == '%'){
		cout << "exp_b() lookahead: " << lookahead << endl;
		int tmp = lookahead;
		match(lookahead);
		exp_unary();
		

		//match(lookahead);
		switch(tmp){
			case MUL:
				//match(lookahead);
				cout << "mul" << endl;
				break;
			case DIV:
				//match(lookahead);
				cout << "div"  << endl;
				break;
			case MOD:
				//match(lookahead);
				cout << "rem"<< endl;
				break;
		}
	}
	
	
}

void exp_unary(){
	cout << "unary: " << lookahead << endl;
	//exp_d();
	
	if(lookahead == '&' || lookahead == '*' || lookahead == '!' || lookahead == '-' || lookahead == SIZEOF){
		cout << "unary1 : " << lookahead << endl;
		int tmp = lookahead;
		match(lookahead);
		cout << "unary2 : " << lookahead << endl;
		exp_unary();
		cout << "unary3 : " << lookahead << endl;
		switch(tmp){
			case '&':
				//match(lookahead);
				//cout << "pre addr" << endl;
				//exp_d();
				cout << "addr" << endl;
				break;
			case '*':
				//match(lookahead);
				//exp_d();
				cout << "deref" << endl;
				break;
			case '!':
				//match(lookahead);
				//exp_d();
				cout << "not" << endl;
				break;
			case '-':
				//match(lookahead);
				//exp_d();
				cout << "neg" << endl;
				break;
			case SIZEOF:
				//match(lookahead);
				if(lookahead == '(')
				{
					cout << "unary sizeof: " << lookahead << endl;
					match('(');
					cout << "unary sizeof 2: " << lookahead << endl;
					expression();
					if(lookahead == ')')
					{
						match(')');
					}
				}
				cout << "sizeof" << endl;
				break;
		}
	}
	exp_d();
}

void exp_d(){
	cout << "d " << lookahead << endl;
	exp_id();
	if(lookahead == '[')
	{
		match('[');
		while(lookahead != ']'){
			expression();

		}
		if(lookahead == ']') {
		cout << "exp_d(): " << lookahead << endl;
		match(']');
		}
		cout << "index" << lookahead << endl;
		
	}
	//exp_id();
}

void exp_id(){
	cout << "id " << lookahead << endl;
	if(lookahead == ID)
	{
		cout << "id1a: " << lookahead << endl;
		match(ID);
		cout << "id1b: " << lookahead << endl;
		if(lookahead == '(')
		{
			cout << "id2" << endl;
			match('(');
			if(!(lookahead == ')'))
			{
				cout << "id2a: " << lookahead << endl;
				exp_list();
				cout << "id2b: " << lookahead << endl;
			}
			cout << "id3: " << lookahead << endl;
			if(lookahead == ')')
				match(')');
		}
		//match(ID);
	}
	else if(lookahead == NUM || lookahead == STRING) {
		cout << "exp_id() NUM/STRING " << lookahead << endl;
		match(lookahead);
		cout << "POST exp_id() NUM/STRING " << lookahead << endl;
	}
	else if(lookahead == '(')
	{
		cout << "id4" << endl;
		match('(');
		expression();
		if(lookahead == ')')
			match(')');
	}

}

void exp_list()
{	
	cout << "list: " << lookahead << endl;
	expression();
	if(lookahead == ',')
	{	
		match(lookahead);
		cout << "exp_list() , " << lookahead << endl;
		exp_list();
	}
}

void statement(){
	//cout << "statement" << endl;
	if(lookahead == ERROR){
		cout << "STATEMENT ERROR" << endl;
		return;
	}
	if(lookahead == '{')
	{
		cout << "curly1 "<< lookahead << endl;
		match('{');				
		cout << "curly2 "<< lookahead << endl;

		declarations();
		cout << "curly3 "<< lookahead << endl;

		statement();
		cout << "curly4 "<< lookahead << endl;
		//while with statement
		while(lookahead != '}')
		{
			statement();
		}
		// while(lookahead != '}')
		// {
		// 	cout << "curly while" << endl;
		// 	// if(lookahead == ERROR){
		// 	// 	break;
		// 	// }
		// 	declarations();
		// 	statement();
		// }
		cout << "curly5 "<< lookahead << endl;

		match('}');
		cout << "CURLY6 "<< lookahead << endl;
	}
	else if(lookahead == WHILE || lookahead == IF)
	{	
		cout << "statement if/while " << lookahead << endl;
		int tmp = lookahead;
		match(lookahead);
		match('(');
		expression();
		match(')');
		statement();
		
		if(tmp == IF)
		{
			cout << "statement if" << endl;
			//match(lookahead);
			if(lookahead == ELSE)
			{
				match(lookahead);
				statement();
				cout << "else" << endl;
			}
			//statement();
			cout << "if" << endl;
		}
		//statement();
		else if(tmp == WHILE)
			cout << "while" << endl;
			
	}
	else if(lookahead == FOR)
	{
		cout << "statement for " << lookahead << endl;
		match(lookahead);
		match('(');
		assignment();
		match(';');
		expression();
		match(';');
		assignment();
		match(')');
		statement();
		cout << "for" << endl;
	}
	else if(lookahead == RETURN)
	{
		cout << "statement return " << lookahead << endl;
		match(lookahead);
		cout << "statement return 2: " << lookahead << endl;
		expression();
		cout << "statement return 3: " << lookahead << endl;
		if(lookahead == ';')
			match(';');
		cout << "return: " << lookahead << endl;
	}
	else 
	{
		cout << "statement assignment 1 " << lookahead << endl;
		assignment();
		cout << "statement assignment 2 " << lookahead << endl;
		if(lookahead == ';')
			match(';');
		cout << "statement assignment 3 " << lookahead << endl;
	}
	cout << "STATEMENT : " << lookahead << endl;
}
				
void assignment() {
	cout << "assignment 1: " << lookahead << endl;
	expression();
	cout << "assignment 2: " << lookahead << endl;
	while(lookahead == '=')
	{
		cout << "assignment match " << lookahead << endl;
		match(lookahead);
		expression();
	}
		
}

// void global_declaration(){
// 	pointers();
// 	match(ID);
// 	if(lookahead == '['){
// 		match('[');
// 		match(NUM);
// 		match(']');
// 	}
// }

void pointers(){
	//int count = 0;
	cout << "pointers: " << lookahead << endl;
	while(lookahead == '*'){
		match('*');
		//count++;
	}
	//return count;
}

void specifier(){
	//int spec = lookahead;
	cout << "specifier:" << lookahead << endl;

	if(lookahead == INT || lookahead == CHAR || lookahead == VOID){
		cout << "matched specifier: " << lookahead << endl;
		match(lookahead);

		//return spec;
	}
}

void declaration(){
	specifier();
	declarator();
	cout << "pre ; match "<< lookahead << endl;
	match(';');
	cout << "end declaration "<< lookahead << endl;
}


void funcOrGlobal(){
	cout << "funcorglobal 1: " << lookahead << endl;
	specifier();
	cout << "funcorglobal 2: " << lookahead << endl;
	pointers();
	cout << "funcorglobal 3: " << lookahead << endl;
	match(ID);
	cout << "funcorglobal 4: " << lookahead << endl;
	if(lookahead == '('){
		cout << "funcorglobal 5: " << lookahead << endl;
		match('(');
		cout << "funcorglobal 6: " << lookahead << endl;
		parameters();
		cout << "funcorglobal 7: " << lookahead << endl;
		match(')');
		cout << "funcorglobal 8: " << lookahead << endl;
		if(lookahead == '{'){
			cout << "funcorglobal 9: " << lookahead << endl;
			match('{');
			//while(lookahead != '}'){
			declarations();
			cout << "funcorglobal 9 b: " << lookahead << endl;
			while(lookahead != '}') {
				statement();
			}
			cout << "funcorglobal 9 c: " << lookahead << endl;
			//}
			match('}');
		}
		else{
			cout << "funcorglobal 10: " << lookahead << endl;
			remainingDecls();
		}
	}
	else {
		while(lookahead == '['){
			cout << "funcorglobal 11: " << lookahead << endl;
			match('[');
			match(NUM);
			match(']');
			cout << "funcorglobal 12: " << lookahead << endl;
		}
	
	remainingDecls();
	}
}

void remainingDecls(){
	/*
	remainingDecls --> ;
						| , global-declarator remainingDecls
	*/
	while(lookahead != ';'){
		cout << "remainingDecls 1: " << lookahead << endl;
		match(',');
		cout << "remainingDecls 2: " << lookahead << endl;
		global_declarator();
		cout << "remainingDecls 3: " << lookahead << endl;
		//remainingDecls();
	}
	match(';');
	cout << "remainingDecls 4: " << lookahead << endl;

}

void global_declarator(){
	cout << "global_declarator(): " << lookahead << endl;
	pointers();
	match(ID);
	if(lookahead == '('){
		match('(');			
		parameters();
		
		match(')');
	}
	else if(lookahead == '['){
		match('[');
		
		match(NUM);
		
		match(']');
	}
}



void parameter(){
	specifier();
	cout << "parameter 1: " << lookahead << endl;
	pointers();
	cout << "parameter 2: " << lookahead << endl;

	cout << "parameter 3: " << lookahead << endl;
	if(lookahead == ID)
		match(ID);
	
	cout << "parameter 4: " << lookahead << endl;
}

void parameters(){
	parameter();
	while(lookahead == ','){
		match(',');
		parameter();
	}
	
}

// void parameterList(){
// 	parameter();
// 	if(lookahead == ','){
// 		parameterList();
// 	}
// }

// void declaratorList(){
// 	declarator();
// 	if(lookahead == ',') {
// 		declaratorList();
// 	}
// }

void declarations(){
	while(lookahead == INT || lookahead == VOID || lookahead == CHAR) {
		//match(lookahead);
		cout << "declarations: " << lookahead << endl;
		declaration();
	}
}


void declarator(){
	cout << "declarator" << endl;
	pointers();
	cout << "declarator 2" << endl;
	match(ID);
	cout << "declarator 3:" << lookahead << endl;
	if(lookahead == '['){
		cout << "declarator index" << endl;
		match('[');	
		match(NUM);
		match(']');
	}
	//declarator-list case
	if(lookahead == ','){
		match(',');
		declarator();
	}

	

}

// void declarator_list(){
// 	cout << "declarator list: " << lookahead << endl;
// 	declarator();
// 	if(lookahead == ','){
// 		match(',');
// 		declarator();
// 	}

// }

int main() {
	lookahead = lexan(lexbuf);
	while(lookahead!=DONE)
	{
		cout << "START" << endl;
		//expression();
		//declaration();
		funcOrGlobal();
		if(lookahead == ERROR){
			cout << "lookahead: error" << endl;
			return -1;
		}
		//statement();

		//statement();
		cout << "END" << endl;

	}
	cout << "DONE" << endl;
	return 0;
}
		
	



