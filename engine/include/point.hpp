#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>
#include <optional>
#include <memory>

struct Point;
typedef std::optional<Point> OptPoint;
typedef std::shared_ptr<Point> SharedPoint;
typedef std::unique_ptr<Point> UniquePoint;
typedef std::weak_ptr<Point> WeakPoint;

struct Point {
	int32_t x;
	int32_t y;
};

#endif
