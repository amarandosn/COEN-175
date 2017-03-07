//allocate.cpp

#include <iostream>
#include "Tree.h"

using namespace std;

void Function::allocate(int &offset)
{
	int paramSize = _id->type().parameters()->size();
	//cout << paramSize << endl;
	offset = 8;
	// cout << _id->name() << ":" endl;
	// cout << "\tpushq\t" << "%rbp" << endl;
	// cout << "\tmovq\t" << "%rsp, %rbp" << endl;
	// cout << "\tsubq" << "size, %rsp" << endl;

	for(int i = 0; i < paramSize; i++)
	{
		offset +=4;
		_body->declarations()->symbols()[i]->offset = offset;
	}

	int declSize = _body->declarations()->symbols().size();
	offset = 0;
	for(int i = paramSize; i < declSize; i++)
	{
		//offset -= 4;
		//cout << "allocate 1" << endl;
		if(_body->declarations()->symbols()[i]->type().isArray())
		{
			//cout << "allocate 2" << endl;
			int arrayLength = _body->declarations()->symbols()[i]->type().length();
			offset = offset - (4*arrayLength);
			_body->declarations()->symbols()[i]->offset = offset;
		}
		else if(_body->declarations()->symbols()[i]->type().isScalar())
		{
			//cout << "allocate 3" << endl;
			offset -= 4;
			_body->declarations()->symbols()[i]->offset = offset;
		}
	}

}
