//checker.cpp


# include <cstdlib>
# include <iostream>
# include <string>
# include "type.h"
# include "symbol.h"
# include "scope.h"

using namespace std;

/*
./scc < array.c 2 > array.txt
remove prints: ./scc < array.c > /dev/null 2> array.txt
diff array.err array.txt

./scc < array.c | diff array.out -
*/


//topscope();
//currentscope();

/*
bool found;
Symbol sym = find(name, found);
if(found)
{
	...
}
else
{
	...
}
*/
//start with declarevar and usesymbol

static string confTypes = "conflicting types for '%s'";
static string redef = "redefinition of '%s'";
static string redecl = "redeclaration of '%s'";
static string undecl = "'%s' undeclared";
static string voidType = "'%s' has type void";

Scope *current_scope, *global_scope;

void openScope()
{
	cout << "Opening Scope" << endl;
	//add scope to stack
}

void closeScope()
{
	cout << "Closing Scope" << endl;
	//remove scope from stack
}


void declareFunc(string name, int spec, unsigned ind)
{
	cout << "Declare function " << name << endl;
	// Symbol *symbol;
	// Symbol = current_scope->find(name);

	// if(type != symbol->type())
	// {
	// 	report(confTypes, name);
	// }
}

void useSymbol(string name)
{
	cout << "Use symbol " << name << endl;

	// Symbol *symbol;
	// Symbol = current_scope->find(name);
	
	// if(symbol == NULL)
	// {
	// 	symbol = new symbol(name, type);
	// 	current_scope->insert(symbol);
	// }
	// else if(current_scope != global_scope)
	// {
	// 	report(redecl, name);
	// }
	// else if(type != symbol->type())
	// {
	// 	report(confTypes, name);
	// }
}


//Type t( );
//declareVar(name, t);
//or declarVar(name, Type(____));
void declareVar(string name, int spec, unsigned ind)
{
	// cout << "Declare variable " << name << " with specifier " << spec << " and indirection " << ind << endl;
	// Symbol *symbol;
	// Symbol = current_scope->find(name);

	// if(symbol == NULL)
	// {
	// 	symbol = new symbol(name, type);
	// 	current_scope->insert(symbol);
	// }
	// else if(current_scope != global_scope)
	// {
	// 	report(redecl, name);
	// }
	// else if(type != symbol->type())
	// {
	// 	report(confTypes, name);
	// }
}

void declareArray(string name, int spec, string length, unsigned ind)
{
	//Type t(nspec, ind);
	//t.length = length;
	//Symbol sym(name, t);
	//is this void or void array?
		//if yes, then error e5
	//does it exist anywhere?
		//find()
		//if not, insert()
		//if it does
			//global?
				//if not, error because cannot have a redeclaration 
				//if yes, check for same type

	cout << "Declare array " << name << " with specifier " << spec << ", length " << length << " and indirection " << ind << endl;
}

void defineFunc(string name, int spec, unsigned ind)
{
	cout << "Define function " << name << " with specifier " << spec << " and indirection " << ind << endl;

}

