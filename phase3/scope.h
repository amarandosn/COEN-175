# include <iostream>
# include <cstdlib>
# include <string>
# include <vector>
# include "type.h"
# include "symbol.h"

using namespace std;

# ifndef SCOPE_H
# define SCOPE_H

typedef std::vector <Symbol *> Symbols; 


// class Scope {
// 	Scope *_enclosing;
// 	Symbols _symbols;
	
// public:
// 	// bool operator == (const Type &that) const; 		//comparator
// 	// bool operator != (const Type &that) const;		//comparator
// };

// std::ostream & operator << (std::ostream &ostr, const Type & type);


# endif /* SCOPE_H */