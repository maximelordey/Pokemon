#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <memory>
#include <vector>

#include "box.hpp"

class Computer {
public:
	Computer();
	Computer(uint32_t capability, uint32_t box_capability);

	void storePokemon(UniquePokemon pokemon);
	Box& getBox(uint32_t position);

	uint32_t getCapacity() const;
	uint32_t getSize() const;
	bool isFull() const;

private:
	std::vector<Box> content;
};

#endif
