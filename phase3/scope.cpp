//scope.cpp
# include <cstdlib>
# include <string>
# include <iostream>
# include <cstdlib>
# include <vector>
# include "symbol.h"
# include "type.h"
# include "scope.h"

using namespace std;


Scope::Scope(Scope *enclosing, Symbols symbols)
	:_enclosing(enclosing), _symbols(symbols)
{
}

// Scope::Scope(Scope *enclosing)
// 	:_enclosing(enclosing)
// {
// }

// Scope::Scope(Scope *enclosing)
// {
// 	enclosing = _enclosing;
// }

Scope *Scope::enclosing() {
	return _enclosing;
}

Symbols Scope::getSymbols() const{
	return _symbols;
}



Symbol *Scope::find(const string &name) const {
		//check if name matches any symbols inside current scope
		Symbols symbols;
		for(int i = 0; i < symbols.size(); i++)
		{
			if(symbols[i]->name() == name)
			{
				return symbols[i];
			}
		}
		return NULL;
}

Symbol *Scope::lookup(const string &name) const {
	//check if name has been declared any parent scopes
	Scope *current;

	Scope *parent = current->enclosing();

	while(parent != NULL)
	{
		if(parent->find(name) != NULL)
		{
			return parent->find(name);
		}
		parent = parent->enclosing();
		
	}
	return NULL;

}



void Scope::insert(Symbol *symbol) const {
		Symbols symbols;
		symbols.push_back(symbol);
}

//similar structure as type, need symbols inside them, container class for symbols (vector or list)
//static stack of scopes in checker
//open scope adds scopes to stack, close scope removes from stack
//could do stacks as multiple symbols and reference it to the stack above it (up to scope to look up chain of scopes)
//symbol find(bool &found); - check if inside current scope
	/*
		Symbol sym = find(name);
		if(sym != NULL)
		else
	*/
//symbol lookup(const string &name); - has this been declared anywhere? 
	//these need to be in checker if vector, inside scope if stacks as mult symbols and references parent scope
//void insert(string name, Type type);
//x: int *
//need hierarchy

//public:
	//insert()	- into scope

//private:

