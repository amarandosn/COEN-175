//type.cpp
# include <cstdlib>
# include <iostream>
# include "type.h"

using namespace std;



//constructor
Type::Type(Kind kind, int specifier, unsigned indirection)
	:_kind(kind), _specifier(specifier), _indirection(indirection)
{
}

Kind Type::kind() const		
{
	return _kind;
}

//int specifier and unsigned indirection

bool Type::operator != (const Type &that) const
{
	return ! (*this == that);
}

bool Type::operator == (const Type &that) const
{
	if(_kind != that._kind)
		return false;
	if(_specifier != that._specifier)
		return false;
	if(_indirection != that._indirection)
		return false;
	return true;
}

std::ostream & operator << (std::ostream &ostr, const Type &type)
{
	//ostr << …
	return ostr;
}
