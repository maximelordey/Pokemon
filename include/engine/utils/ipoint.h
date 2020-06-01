#ifndef IPOINT_H
#define IPOINT_H

class IPoint {
	public:
		virtual int getX() = 0;
		virtual int getY() = 0;

		virtual void move(int x, int y) = 0;
		virtual void translate(int dx, int dy) = 0;
}

#endif
