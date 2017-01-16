#include <cctype>
#include <stdio.h>
#include "lexer.h"
#include <iostream>
#include <string>

using namespace std;
//folder: phase1
//filenames: lexer.h, lexer.cpp, Makefile
//./a.out < testfile.txt
//./a.out < fib.c > fib.txt
//diff examples/fib.out fib.txt
//tar: tar cvf phase1.tar phase1

int checkKey(string s)
{
	string keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
	for(int i = 0; i < 32; i++)
	{
		if(s.compare(keywords[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int checkOp(string s)
{
	
	string operators[] = {"=", "||", "&&", "==", "!=", "<", ">", "<=", ">=", "+", "-", "*", "/", "%", "&", "!", "++", "--", ".", "->", "(", ")", "[", "]", "{", "}", ";", ":", ","};
	for(int i = 0; i < 28; i++)
	{
		if(s.compare(operators[i]) == 0)
		{
			//cout << "checkop" << endl;
			return 1;
		}
	}
	return 0;
}

int checkOp_a(string c)
{
	string operators_1[] = {"|", "&", "=", "<", ">", "-", "+", "!"};
	for(int i = 0; i < 8; i++)
	{
		if(c == operators_1[i])
		{
			return 1;
		}
	}
return 0;
}

int checkOp_b(string c1, string c2)
{
	if(c1 == "=")
	{
		if(c2 == "=")
		{
			return 1;
		}
	}
	else if(c1 == "|")
	{
		if(c2 == "|")
		{
			return 1;
		}
	}
	else if(c1 == "&")
	{
		if(c2 == "&")
		{
			return 1;
		}
	}
	else if(c1 == "!")
	{
		if(c2 == "=")
		{
			return 1;
		}
	}
	else if(c1 == "<")
	{
		if(c2 == "=")
		{
			return 1;
		}
	}
	else if(c1 == ">")
	{
		if(c2 == "=")
		{
			return 1;
		}
	}
	else if(c1 == "+")
	{
		if(c2 == "+")
		{
			return 1;
		}
	}	
	else if(c1 == "-")
	{
		if(c2 == "-"||c2 == ">")
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char c, c1, c2;
	string s, s1;
	int flag = 0;
	//cout << "initialize" << endl;
	c = cin.get();
	while(!cin.eof())
	{
		//cout << "1--------" << endl;
		//if whitespace, skip
		if(isspace(c))
		{
			//cout << "in isspace" << endl;
			c = cin.get();
		}
		
		//handle numbers:
		if(isdigit(c))
		{
			s.clear();
			do {
				s += c;
				c = cin.get();
			}
			while(isdigit(c));
			cout << "number:" << s << endl;
		}
		
		//handle identifiers and keywords
		if(isalpha(c)||c == '_')
		{
			s.clear();
			do {
				s+=c;
				c = cin.get();
			}
			while(isalnum(c)||c == '_');
			if(checkKey(s) == 1)
			{
				cout << "keyword:" << s << endl;
			}
			else
				cout << "identifier:" << s << endl;

					
		}
		
		//handle strings, operators (double characters treated as separate cases), and comments
		if(ispunct(c))
		{
			flag = 0;
			//cout << "in ispunct" << endl;
			s.clear();
			s1.clear();
			//strings
			if(c == '"')
			{

				s.clear();
				s+=c;
				//cout << "in string" << s << endl;
				do
				{
					c = cin.get();
					//cout << "in string 1 " << s << endl;
					if(c == '"' && s[(s.length()-1)] == '\\')
					{
						//flag++;
						s+=c;
						c = cin.get();
					}
					else if(c == '"')
					{
						//cout << "in string " << s << endl;
						s+=c;
						//c = cin.get();
						break;
					}
					s+=c;
				}
				while(c!='"');
				// cout << "pre string c:" << c << endl;
				cout << "string:" << s << endl;
				c = cin.get();
				//cout << "post string c:" << c << endl;
				continue;
			}
			//comments
			if(c == '/') {
				 s.clear();
				// s1.clear();
				// s+=c;
				s+=c;
				c = cin.get();
				//cout << "in comments: " << s << endl;
				
				//cout << "in comments1: " << s << endl;
				if(c == '*') {
					//cout << "in *" << endl;
					do {
						s+=c;
						c = cin.get();
						//cout << "in comments" << endl;
					}while(!(c == '/' && s[s.length()-1] == '*'));
					
					//cout << "in comm after while" << endl;
					s+=c;
					c = cin.get();
					//cout << "in *: " << s << endl;
					s.clear();
					//cout << "2in *: " << s << endl;

				}
				/* division case */
				//cout << "3in *: " << s << endl;
				if(checkOp(s))
				{
					cout << "operator:" << s << endl;
				}
					
				//cout << "comment:" << s << endl;
				continue;
			}
			//operators
			if(c != '"' || c != '\\'){
				//cout << "in op" << endl;
				s.clear();
				s1.clear();
				s+=c;
				//cout << "in operators: " << s << endl;
				c = cin.get();
				//check if second op is part of a double op, if so then print double op
				//else print first op and increment
				if(checkOp_a(s))
				{
					//cout << "inop: " << s << endl;
					s1+=c;
					if(checkOp_b(s,s1))
					{
						//cout << "double op" << endl;
						s+=s1;
						cout << "operator:" << s << endl;
						c = cin.get();
						flag = 1;
						//break;
					}
				}
				if(flag == 0 && s != "|")
						cout << "operator:" << s << endl;
				
				continue;
			}
			
			
		}
		//comments and strings for the end
		/*
			1. strings start with quotes
			2. contents of a string can be any character that is NOT  \\, \n, "
			3. IF there's a "\", there can be anything after it
			4. if you encounter a quote, check if previous char was a \
			5. special case: \"
		*/
		
			
	}
return 0;
}


