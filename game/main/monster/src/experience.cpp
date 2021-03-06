#include "experience.h"

Experience::Experience() 
	: _gauge()
{}

Experience::Experience(uint32_t experienceMax)
	: _gauge(experienceMax)
{}
