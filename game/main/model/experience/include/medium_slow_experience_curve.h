#ifndef MEDIUM_SLOW_EXPERIENCE_CURVE_H
#define MEDIUM_SLOW_EXPERIENCE_CURVE_H

#include "iexperience_curve.h"

class MediumSlowExperienceCurve : public IExperienceCurve {
	public:
		uint32_t getExperienceMax(uint32_t level) const;
		IExperienceCurve* clone () const;
};

#endif
