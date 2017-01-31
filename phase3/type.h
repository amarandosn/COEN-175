# include <iostream>

# ifndef TYPE_H
# define TYPE_H

enum Kind {
	SCALAR, ARRAY, FUNCTION
};

class Type {
	Kind _kind;
	int _specifier;
	unsigned _indirection;
	
public:
	Type(Kind kind, int specifier, unsigned indirection = 0);		//constructor
	Kind kind() const;			//accessor
	int specifier() const;			//accessor
	unsigned indirection() const;		//accessor
	bool operator == (const Type &that) const; 		//comparator
	bool operator != (const Type &that) const;		//comparator
};
std::ostream & operator << (std::ostream &ostr, const Type & type);


# endif /* TYPE_H */