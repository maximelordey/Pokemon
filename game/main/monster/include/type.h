#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <map>

#include "coefficient.h"

class Type {
	public:
		Type();
		Type(const std::string &name);
		Type(const char *name);

		bool isEqualTo(const Type &type) const;
		bool operator==(const Type &type) const;
		bool operator!=(const Type &type) const;
		bool operator<(const Type &type) const;
		bool operator>(const Type &type) const;

	public:
		std::string _name;
		std::map<Type, Coefficient> _weaknesses;
};

#endif
