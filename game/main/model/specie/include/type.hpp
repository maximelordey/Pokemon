#ifndef TYPE_HPP
#define TYPE_HPP

#include <memory>
#include "identifier.h"
#include "effectiveness.hpp"

class Type;
typedef std::shared_ptr<Type> SharedType;
typedef float Coefficient;

class Type {
	public:
		Type();
		Type(const Identifier& identifier);

		void AddOrUpdateEffectiveness(const SharedType& type, Coefficient coefficient);
		Coefficient GetCoefficient(const SharedType& type) const;

		bool isEqualTo(const Type& type) const;
		bool isGreaterThan(const Type& type) const;
		bool isLesserThan(const Type& type) const;

		bool operator==(const Type& type) const;
		bool operator!=(const Type& type) const;
		bool operator>(const Type& type) const;
		bool operator<(const Type& type) const;

	private:
		Identifier identifier;
		Effectiveness effectiveness;
};

#endif
