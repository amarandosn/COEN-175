//scope.cpp
# include <cstdlib>
# include <string>
# include <iostream>
# include "scope.h"

using namespace std;


// Scope::Scope(Scope *enclosing, Symbols symbols)
// 	:_enclosing(enclosing), _symbols(symbols)
// {
// }



//similar structure as type, need symbols inside them, container class for symbols (vector or list)
//static stack of scopes in checker
//open scope adds scopes to stack, close scope removes from stack
//could do stacks as multiple symbols and reference it to the stack above it (up to scope to look up chain of scopes)
//symbol find(bool &found); - check if inside current scope
//symbol lookup(); - has this been declared anywhere? 
	//these need to be in checker if vector, inside scope if stacks as mult symbols and references parent scope
//x: int *
//need hierarchy

//public:
	//insert()	- into scope

//private:

