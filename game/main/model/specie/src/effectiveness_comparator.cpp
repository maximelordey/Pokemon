#include "effectiveness_comparator.hpp"

#include "type.hpp"

bool EffectivenessComparator::operator()(const SharedType& rigthType, const SharedType& leftType) const {
	return *rigthType < *leftType;
}
