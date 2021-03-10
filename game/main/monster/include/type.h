#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <map>

#include "coefficient.h"
#include "identifier.h"
#include "translation.h"

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
		Translation _name;
		std::map<Type, Coefficient> _weaknesses;
};

#endif
