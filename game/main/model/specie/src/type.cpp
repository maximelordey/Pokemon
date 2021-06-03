#include "type.hpp"

Type::Type() 
	: identifier()
{}

Type::Type(const Identifier& identifier)
	: identifier(identifier)
{}

void Type::AddOrUpdateEffectiveness(const SharedType& type, Coefficient coefficient) {
	effectiveness.AddOrUpdateEffectiveness(type, coefficient);
}

Coefficient Type::GetCoefficient(const SharedType& type) const {
	return effectiveness.GetCoefficient(type);
}

bool Type::isEqualTo(const Type& type) const {
	return identifier == type.identifier;
}

bool Type::isLesserThan(const Type& type) const {
	return identifier < type.identifier;
}

bool Type::isGreaterThan(const Type& type) const {
	return identifier > type.identifier;
}

bool Type::operator==(const Type& type) const {
	return this->isEqualTo(type);
}

bool Type::operator!=(const Type& type) const {
	return !this->isEqualTo(type);
}
		
bool Type::operator>(const Type& type) const {
	return this->isGreaterThan(type);
}

bool Type::operator<(const Type& type) const {
	return this->isLesserThan(type);
}
