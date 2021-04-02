#ifndef EXPERIENCE_CURVE_H
#define EXPERIENCE_CURVE_H

#include <cstdint>

#include "iexperience_curve.h"

class ExperienceCurve {
	public:
		ExperienceCurve(const IExperienceCurve* experienceCurve);
		ExperienceCurve(const ExperienceCurve& experienceCurve);
		ExperienceCurve(ExperienceCurve&& experienceCurve);
		~ExperienceCurve();

		uint32_t getExperienceMax(uint32_t level) const;

		ExperienceCurve& operator=(const ExperienceCurve& experienceCurve);
		ExperienceCurve& operator=(ExperienceCurve&& experienceCurve);

	private:
		IExperienceCurve* _experienceCurve;
};

#endif
