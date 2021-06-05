#include "fluctuating_experience_curve.hpp"

uint32_t FluctuatingExperienceCurve::getExperienceMax(uint32_t level) const {
	uint32_t experienceMax = 0;

	if (level < 16) {
		experienceMax = (level * level * level * (73u + level)) / 150u;
	} else if(level < 36) {
		experienceMax = (level * level * level * (14u + level)) / 50u;
	} else {
		experienceMax = (level * level * level * (64u + level)) / 100u;
	}

	return experienceMax;
}
