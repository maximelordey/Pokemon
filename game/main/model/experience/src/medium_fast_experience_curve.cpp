#include "medium_fast_experience_curve.hpp"

uint32_t MediumFastExperienceCurve::getExperienceMax(uint32_t level) const {
	return level * level * level;
}
