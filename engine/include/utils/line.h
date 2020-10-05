#ifndef LINE_H
#define LINE_H

#include <cstdint>

class Line {
	public:
		Line();
		Line(int32_t _x1, int32_t _y1, int32_t _x2, int32_t _y2);
		Line(const Line &line);
		Line(Line &&line);
		~Line();

		Line &operator=(const Line &line);
		Line &operator=(Line &&line);

	public:
		int32_t _x1;
		int32_t _y1;
		int32_t _x2;
		int32_t _y2;
};

#endif
