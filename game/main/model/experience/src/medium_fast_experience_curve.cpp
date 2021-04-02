#include "medium_fast_experience_curve.h"

uint32_t MediumFastExperienceCurve::getExperienceMax(uint32_t level) const {
	return level * level * level;
}

IExperienceCurve* MediumFastExperienceCurve::clone () const {
	return new MediumFastExperienceCurve();
}
