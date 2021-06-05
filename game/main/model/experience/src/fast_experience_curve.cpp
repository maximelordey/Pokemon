#include "fast_experience_curve.hpp"

uint32_t FastExperienceCurve::getExperienceMax(uint32_t level) const {
	return (4u * (level * level * level)) / 5u;
}
