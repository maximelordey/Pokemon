#include "experience_curve.h"

#include <utility>

ExperienceCurve::ExperienceCurve(const IExperienceCurve* experienceCurve) 
	: _experienceCurve(experienceCurve->clone())
{}

ExperienceCurve::ExperienceCurve(const ExperienceCurve& experienceCurve)
	: _experienceCurve(experienceCurve._experienceCurve->clone())
{}

ExperienceCurve::ExperienceCurve(ExperienceCurve&& experienceCurve) 
	: _experienceCurve(std::move(experienceCurve._experienceCurve)) 
{}

ExperienceCurve::~ExperienceCurve() {
	delete _experienceCurve;
}

uint32_t ExperienceCurve::getExperienceMax(uint32_t level) const {
	return _experienceCurve->getExperienceMax(level);
}

ExperienceCurve& ExperienceCurve::operator=(const ExperienceCurve& experienceCurve) {
	if (this != &experienceCurve) {
		_experienceCurve = experienceCurve._experienceCurve->clone();
	}
	return *this;
}

ExperienceCurve& ExperienceCurve::operator=(ExperienceCurve&& experienceCurve) {
	if (this != &experienceCurve) {
		_experienceCurve = std::move(experienceCurve._experienceCurve);
	}
	return *this;
}
