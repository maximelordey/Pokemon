#ifndef FAST_EXPERIENCE_CURVE
#define FAST_EXPERIENCE_CURVE

#include "iexperience_curve.h"

class FastExperienceCurve : public IExperienceCurve {
	public:
		uint32_t getExperienceMax(uint32_t level) const;
		IExperienceCurve* clone () const;
};

#endif
