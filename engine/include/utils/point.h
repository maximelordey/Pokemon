#ifndef POINT_H
#define POINT_H

#include <cstdint>

class Point {
	public:
		Point(int32_t x, int32_t y);
		Point(const Point& point);
		Point(Point&& point);
		~Point();

		int32_t getX() const;
		int32_t getY() const;

		void move(int32_t x, int32_t y);
		void translate(int32_t dx, int32_t dy);

		Point& operator=(const Point& point);
		Point& operator=(Point&& point);

	public:
		int32_t _x;
		int32_t _y;
};

#endif
