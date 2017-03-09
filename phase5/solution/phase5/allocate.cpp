//allocate.cpp

#include <iostream>
#include "Tree.h"

using namespace std;

void Function::allocate(int &offset)
{
	int paramSize = _id->type().parameters()->size();
	//cout << paramSize << endl;
	offset = 8;

	for(int i = 0; i < paramSize; i++)
	{	
		//allocate global
		
		_body->declarations()->symbols()[i]->offset = offset;
		offset +=4;
	}

	int declSize = _body->declarations()->symbols().size();
	offset = 0;
	for(int i = paramSize; i < declSize; i++)
	{
		//offset -= 4;
		//cout << "allocate nonglobal" << endl;
		if(_body->declarations()->symbols()[i]->type().isArray())
		{
			//cout << "allocate array" << endl;
			int arrayLength = _body->declarations()->symbols()[i]->type().length();
			offset = offset - (4*arrayLength);
			_body->declarations()->symbols()[i]->offset = offset;
		}
		else if(_body->declarations()->symbols()[i]->type().isScalar())
		{
			//cout << "allocate scalar" << endl;
			offset -= 4;
			_body->declarations()->symbols()[i]->offset = offset;
		}
	}

}
