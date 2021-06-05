#ifndef FAST_EXPERIENCE_CURVE_HPP
#define FAST_EXPERIENCE_CURVE_HPP

#include "iexperience_curve.hpp"

struct FastExperienceCurve : public IExperienceCurve {
	virtual uint32_t getExperienceMax(uint32_t level) const;
};

#endif
