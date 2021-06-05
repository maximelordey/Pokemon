#include "computer.hpp"

#include "pokemon.h"

Computer::Computer() 
	: content()
{}

Computer::Computer(uint32_t capability,  uint32_t box_capability) 
	: content(capability)
{
	for(Box& box : content) {
		box = Box(box_capability);
	}
}

void Computer::storePokemon(UniquePokemon pokemon){
	//TODO: ASSERT(!this->isFull)

	auto iterator = content.begin();
	while(iterator->isFull()) {
		iterator++;
	}
	iterator->storePokemon(std::move(pokemon));
}

Box& Computer::getBox(uint32_t position){
	//TODO: ASSERT(position < this->getCapability())

	auto iterator = content.begin();
	iterator = iterator + position;
	return *iterator;
}


uint32_t Computer::getCapacity() const{
	uint32_t capacity = 0;
	for(const Box& box : content) {
		capacity += box.getCapacity();
	}
	return capacity;
}

uint32_t Computer::getSize() const{
	uint32_t size = 0;
	for(const Box& box : content) {
		size += box.getSize();
	}
	return size;
}

bool Computer::isFull() const{
	return this->getCapacity() == this->getSize();
}

