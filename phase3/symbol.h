# include <iostream>
# include <cstdlib>
# include <string>
# include <vector>
# include "type.h"

using namespace std;
# ifndef SYMBOL_H
# define SYMBOL_H

typedef std::vector<Type> Parameters;
Parameters *_params;


class Symbol {
	string _name;
	Type _type;
	
	
public:
	Symbol(string name, Type type);		//constructor
	Type type() const;			//accessor
	string name() const;			//accessor
	bool ifDef() const;
	// bool operator == (const Type &that) const; 		//comparator
	// bool operator != (const Type &that) const;		//comparator
};

std::ostream & operator << (std::ostream &ostr, const Symbol & symbol);

//main to create some symbols and parameter vectors and insert parameter into symbols, check if they are equal
# endif /* SYMBOL_H */