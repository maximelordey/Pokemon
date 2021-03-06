#include "effectiveness.hpp"

#include <stdexcept>

#include "coefficient.h"
#include "type.hpp"

void Effectiveness::AddOrUpdateEffectiveness(const SharedType& type, Coefficient coefficient) {
	auto pair = content.insert(std::make_pair(type, coefficient));
	pair.first->second = coefficient;
}

Coefficient Effectiveness::GetCoefficient(const SharedType& type) const {
	auto iterator = content.find(type);
	if (iterator != content.cend()) {
		return iterator->second;
	} else {
		throw std::runtime_error("Couldn't find type");
	}
}

