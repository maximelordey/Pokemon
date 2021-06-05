#ifndef MEDIUM_FAST_EXPERIENCE_CURVE_HPP
#define MEDIUM_FAST_EXPERIENCE_CURVE_HPP

#include "iexperience_curve.hpp"

struct MediumFastExperienceCurve : public IExperienceCurve {
	uint32_t getExperienceMax(uint32_t level) const;
};

#endif
