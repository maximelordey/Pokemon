#ifndef EFFECTIVENESS_COMPARATOR_HPP
#define EFFECTIVENESS_COMPARATOR_HPP

#include <memory>

class Type;
typedef std::shared_ptr<Type> SharedType;

struct EffectivenessComparator {
	bool operator()(const SharedType& rigthType, const SharedType& leftType) const;
};

#endif
