#ifndef ERRATIC_EXPERIENCE_CURVE_H
#define ERRATIC_EXPERIENCE_CURVE_H

#include "iexperience_curve.h"

class ErraticExperienceCurve : public IExperienceCurve {
	public:
		uint32_t getExperienceMax(uint32_t level) const;
		IExperienceCurve* clone () const;		
};

#endif
