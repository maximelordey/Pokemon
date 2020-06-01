#ifndef IDIMENSION_H
#define IDIMENSION_H

class IDimension {

	public:
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;

		virtual void setSize(int width, int height) = 0;

}

#endif
