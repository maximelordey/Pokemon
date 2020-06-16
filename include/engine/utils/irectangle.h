#ifndef IRECTANGLE_H
#define IRECTANGLE_H

class IRectangle {
	public:
		virtual int getX() const = 0;
		virtual int getY() const = 0;
		virtual void setX(int x) = 0;
		virtual void setY(int y) = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual void setWidth(int width) = 0;
		virtual void setHeight(int height) = 0;

		virtual void move(int x, int y) = 0;
		virtual void translate(int dx, int dy) = 0;
}

#endif
