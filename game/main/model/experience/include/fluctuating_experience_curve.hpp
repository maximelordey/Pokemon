#ifndef FLUCTUATING_EXPERIENCE_CURVE_HPP
#define FLUCTUATING_EXPERIENCE_CURVE_HPP

#include "iexperience_curve.hpp"

struct FluctuatingExperienceCurve : public IExperienceCurve {
	virtual uint32_t getExperienceMax(uint32_t level) const;
};

#endif
