#ifndef EFFECTIVENESS_HPP
#define EFFECTIVENESS_HPP

#include <memory>
#include <map>

#include "effectiveness_comparator.hpp"

class Type;
typedef std::shared_ptr<Type> SharedType;
typedef float Coefficient;

class Effectiveness {
	public:
		void AddOrUpdateEffectiveness(const SharedType& type, Coefficient coefficient);
		Coefficient GetCoefficient(const SharedType& type) const;	
		
	private:
		std::map<SharedType, Coefficient, EffectivenessComparator> content;
};

#endif
