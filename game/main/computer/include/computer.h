#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>

#include "box.h"
#include "computer_create_info.h"

class Computer {
	public:
		Computer();

	public:
		std::vector<Box> _boxes;
};

#endif
