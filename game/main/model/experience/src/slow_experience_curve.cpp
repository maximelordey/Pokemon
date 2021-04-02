#include "slow_experience_curve.h"

uint32_t SlowExperienceCurve::getExperienceMax(uint32_t level) const {
	return (5u * (level * level * level)) / 4u;
}

IExperienceCurve* SlowExperienceCurve::clone () const {
	return new SlowExperienceCurve();
}
