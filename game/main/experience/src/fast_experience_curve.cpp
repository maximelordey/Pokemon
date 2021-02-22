#include "fast_experience_curve.h"

uint32_t FastExperienceCurve::getExperienceMax(uint32_t level) const {
	return (4u * (level * level * level)) / 5u;
}

IExperienceCurve* FastExperienceCurve::clone () const {
	return new FastExperienceCurve();
}
