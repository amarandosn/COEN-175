//generate.cpp


#include <iostream>
#include <sstream>
#include "Tree.h"

using namespace std;

void Call::generate()
{
	//push all parameters before calling functions
	for(int i = _args.size()-1; i >= 0; i--)
	{
		cout << "\tpushl\t";
		//i+=1;
		_args[i]->generate();
		cout << _args[i]->location << endl;
		//cout << "post push" << i;
		//cout << endl;
		//cout << "hi" << endl;
		
	}
	//cout << "pre call" << endl;
	cout << "\tcall\t" << _id->name() << endl;
}

void Identifier::generate()
{
	//set nonglobal IDs with addresses and names
	//set global IDs as names
	int offset = _symbol->offset;	
	stringstream str_offset;
	if(offset)
	{
		//nonglobal	
gcc -m32 local.s examples/local-lib.c
		str_offset << offset;
		location = str_offset.str() +  "(%ebp)";
	}
	else
	{
		//global
		location = _symbol->name();
	}

}


void Function::generate()
{
	int offset = 0;
	allocate(offset);
	if(offset < 0)
		offset = -offset;
	cout << ".globl " << _id->name() << endl;
	
	//function prologue
	cout << _id->name() << ":" << endl;
	cout << "#FUNCTION PROLOGUE" << endl;
	cout << "\tpushl\t%ebp" << endl;
	cout << "\tmovl\t%esp, %ebp" << endl;
	cout << "\tsubl\t" << "$" << offset << ", %esp" << endl;
	
	//function body
	cout << "#FUNCTION BODY" << endl;
	_body->generate();
	
	//function epilogue
	cout << "#FUNCTION EPILOGUE" << endl;
	cout << "\tmovl\t%ebp, %esp" << endl;
	cout << "\tpop\t" << "%ebp" << endl;

	cout << "\tret" << endl;
 

}

void Block::generate()
{
	//call generate on all statements in body
	for(unsigned i = 0; i < _stmts.size(); i++)
	{
		_stmts[i]->generate();
	}
}

void Number::generate()
{
	//set number with $ sign
	location += "$" + value();
}

void Assignment::generate()
{
	//move source to destination
	cout << "\tmovl\t";
	_right->generate();
	//cout << ", %eax" << endl;
	
	//cout << "\tmovl %eax, ";
	_left->generate();
	//cout << endl;
	
	cout << _right->location << ", " <<_left->location << endl;

	//move left
	//cout << "\tmovl\t";
	//cout << "\tmovl\t";
	//cout << "%eax, ";
	//_right->generate();
	//cout << ", " << _right->location << endl;
	//cout << endl;

}

