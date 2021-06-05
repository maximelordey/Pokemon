#ifndef SLOW_EXPERIENCE_CURVE_HPP
#define SLOW_EXPERIENCE_CURVE_HPP

#include "iexperience_curve.hpp"

struct SlowExperienceCurve : public IExperienceCurve {
	virtual uint32_t getExperienceMax(uint32_t level) const;
};

#endif
