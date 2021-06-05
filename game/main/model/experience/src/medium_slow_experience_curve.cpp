#include "medium_slow_experience_curve.hpp"

uint32_t MediumSlowExperienceCurve::getExperienceMax(uint32_t level) const {
	return  ((6u * level * level * level) - (75u * level * level) + (500u * level) - 700u) / 5u;
}
