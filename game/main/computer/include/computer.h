#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>

#include "box.h"

class Computer {
	public:
		Computer();

	public:
		std::vector<Box> _boxes;
};

#endif
