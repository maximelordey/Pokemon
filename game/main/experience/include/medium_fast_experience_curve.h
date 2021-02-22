#ifndef MEDIUM_FAST_EXPERIENCE_CURVE
#define MEDIUM_FAST_EXPERIENCE_CURVE

#include "iexperience_curve.h"

class MediumFastExperienceCurve : public IExperienceCurve {
	public:
		uint32_t getExperienceMax(uint32_t level) const;
		IExperienceCurve* clone () const;
};

#endif
