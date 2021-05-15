#ifndef LINE_HPP
#define LINE_HPP

#include <optional>
#include <memory>

#include "point.hpp"

struct Line;
typedef std::optional<Line> OptLine;
typedef std::shared_ptr<Line> SharedLine;
typedef std::unique_ptr<Line> UniqueLine;
typedef std::weak_ptr<Line> WeakLine;

struct Line {
	Point from;
	Point to;
};

#endif
