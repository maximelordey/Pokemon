#ifndef MEDIUM_SLOW_EXPERIENCE_CURVE_HPP
#define MEDIUM_SLOW_EXPERIENCE_CURVE_HPP

#include "iexperience_curve.hpp"

struct MediumSlowExperienceCurve : public IExperienceCurve {	
	virtual uint32_t getExperienceMax(uint32_t level) const;
};

#endif
