#include "erratic_experience_curve.h"

uint32_t ErraticExperienceCurve::getExperienceMax(uint32_t level) const {
	uint32_t sub_calculation = (6u * level * level * level) - (75u * level * level) + (500u * level) - 700u;
	return  sub_calculation / 5u;
}

IExperienceCurve* ErraticExperienceCurve::clone () const {
	return new ErraticExperienceCurve();
}
