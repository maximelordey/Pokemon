#ifndef IEXPERIENCE_CURVE_HPP
#define IEXPERIENCE_CURVE_HPP

#include <cstdint>
#include <memory>

struct IExperienceCurve;
typedef std::shared_ptr<IExperienceCurve> SharedExperienceCurve;

struct IExperienceCurve {
	virtual uint32_t getExperienceMax(uint32_t level) const = 0;
};

#endif
