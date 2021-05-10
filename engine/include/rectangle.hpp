#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <optional>
#include <memory>

#include "point.hpp"
#include "dimension.hpp"

struct Rectangle;
typedef std::optional<Rectangle> OptRectangle;
typedef std::shared_ptr<Rectangle> SharedRectangle;
typedef std::unique_ptr<Rectangle> UniqueRectangle;
typedef std::weak_ptr<Rectangle> WeakRectangle;

struct Rectangle {
	Point origin;
	Dimension dimension;
};

#endif
