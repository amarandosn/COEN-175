//generate.cpp


#include <iostream>
#include <sstream>
#include "Tree.h"

using namespace std;

void Call::generate()
{
	//for args.size
	//pushl 
	//args[i].generate
	//endl;
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
	int offset = _symbol->offset;	
	stringstream str_offset;
	if(offset)
	{
		//nonglobal
		//sprintf(str_offset, "%d", offset);
		//str_offset = itoa(offset);	
		str_offset << offset;
		location = str_offset.str() +  "(%ebp)";
	}
	else
	{
		//global
		location = _symbol->name();
	}
	//cout << location;
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
	//subl offset, esp
	cout << "#FUNCTION BODY" << endl;
	//allocate(offset);
	_body->generate();
	//function epilogue
	cout << "#FUNCTION EPILOGUE" << endl;
	cout << "\tmovl\t%ebp, %esp" << endl;
	cout << "\tpop\t\t" << "%ebp" << endl;
	//movl ebp esp
	//pop ebp
	
	cout << "\tret" << endl;
 

}

void Block::generate()
{
	for(unsigned i = 0; i < _stmts.size(); i++)
	{
		_stmts[i]->generate();
	}
}

void Number::generate()
{
	//$
	location += "$" + value();
}

void Assignment::generate()
{
	cout << "\tmovl\t";
	_right->generate();
	_left->generate();
	cout << _right->location << ", " <<_left->location << endl;

	//move left
	//cout << "\tmovl\t";
	//cout << "\tmovl\t";
	//cout << "%eax, ";
	//_right->generate();
	//cout << ", " << _right->location << endl;
	//cout << endl;

}

