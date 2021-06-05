#include "slow_experience_curve.hpp"

uint32_t SlowExperienceCurve::getExperienceMax(uint32_t level) const {
	return (5u * (level * level * level)) / 4u;
}
