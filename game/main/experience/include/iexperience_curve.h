#ifndef IEXPERIENCE_CURVE_H
#define IEXPERIENCE_CURVE_H

#include <cstdint>

class IExperienceCurve {
	public:
		virtual uint32_t getExperienceMax(uint32_t level) const = 0;
		virtual IExperienceCurve* clone () const = 0;
};

#endif
