# include <string>
using namespace std;

# ifndef CHECKER_H
# define CHECKER_H

void openScope();
void closeScope();
// void openBlock();
// void closeBlock();
// void openFuncScope();
// void closeFuncScope();
// void openGlobalScope();
// void closeGlobalScope();
// void openRemDeclScope();
// void closeRemDeclScope();
void declareFunc(string name, int spec, unsigned ind);
void declareVar(string name, int spec, unsigned ind);
void declareArray(string name, int spec, string length, unsigned ind);
void defineFunc(string name, int spec, unsigned ind);
void useSymbol(string name);


# endif /* CHECKER_H */