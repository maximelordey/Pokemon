#ifndef ERRATIC_EXPERIENCE_CURVE_HPP
#define ERRATIC_EXPERIENCE_CURVE_HPP

#include "iexperience_curve.hpp"

struct ErraticExperienceCurve : public IExperienceCurve {
	virtual uint32_t getExperienceMax(uint32_t level) const;
};

#endif
