#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <optional>
#include <memory>

struct Color;
typedef std::optional<Color> OptColor;
typedef std::shared_ptr<Color> SharedColor;
typedef std::unique_ptr<Color> UniqueColor;
typedef std::weak_ptr<Color> WeakColor;

struct Color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};

#endif
