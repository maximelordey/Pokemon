#include "erratic_experience_curve.hpp"

uint32_t ErraticExperienceCurve::getExperienceMax(uint32_t level) const {
	uint32_t experienceMax = 0u;

	if (level < 51) {
		experienceMax = ((level * level * level) * (100u - level)) / 50u;
	} else if (level < 69) {
		experienceMax = ((level * level * level) * (150u - level)) / 100u;
	} else if (level < 99) {
		experienceMax = ((level * level * level) * (1911u - (10u * level))) / 1500u;
	} else {
		experienceMax = ((level * level * level) * (160u - level)) / 100u;
	}

	return experienceMax;
}
