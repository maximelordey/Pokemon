#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <map>

#include "coefficient.h"
#include "identifier.h"

class Type {
	public:
		Type();
		Type(const Identifier &identifier);

		bool isEqualTo(const Type &type) const;
		bool operator==(const Type &type) const;
		bool operator!=(const Type &type) const;
		bool operator<(const Type &type) const;
		bool operator>(const Type &type) const;

	public:
		Identifier _identifier;
		std::string _name;
		std::map<Type, Coefficient> _weaknesses;
};

#endif
