//checker.cpp


# include <cstdlib>
# include <iostream>
# include <string>

using namespace std;


void openScope()
{
	cout << "Opening Scope" << endl;
}

void closeScope()
{
	cout << "Closing Scope" << endl;
}

void openBlock()
{
	cout << "Opening Block" << endl;
}

void closeBlock()
{
	cout << "Closing Block" << endl;
}

void openFuncScope()
{
	cout << "Opening Function Scope" << endl;
}

void closeFuncScope()
{
	cout << "Closing Function Scope" << endl;
}

void openGlobalScope()
{
	cout << "Opening Global Scope" << endl;
}

void closeGlobalScope()
{
	cout << "Closing Global Scope" << endl;
}

void openRemDeclScope()
{
	cout << "Opening Remaining Declarators Scope" << endl;
}

void closeRemDeclScope()
{
	cout << "Closing Remaining Declarators Scope" << endl;
}

void declareFunc(string name, int spec, unsigned ind)
{
	cout << "Declare function " << name << endl;
}

void useSymbol(string name)
{
	cout << "Use symbol " << name << endl;
}

void declareVar(string name, int spec, unsigned ind)
{
	cout << "Declare variable " << name << " with specifier " << spec << " and indirection " << ind << endl;
}

void declareArray(string name, int spec, string length, unsigned ind)
{
	cout << "Declare array " << name << " with specifier " << spec << ", length " << length << " and indirection " << ind << endl;
}

void defineFunc(string name, int spec, unsigned ind)
{
	cout << "Define function " << name << " with specifier " << spec << " and indirection " << ind << endl;
}

