#include "box.hpp"

Box::Box()
	: content()
{}

Box::Box(uint32_t capacity)
	: content(capacity)
{}

void Box::storePokemon(UniquePokemon pokemon){
	//ASSERT(!this->isFull())

	auto iterator = content.begin();
	while(iterator->get()) {
		iterator++;
	}
	*iterator = std::move(pokemon);
}

void Box::storePokemon(UniquePokemon pokemon, uint32_t position){
	auto iterator = content.begin();
	iterator = iterator + position;
	
	//ASSERT(iterator->empty())

	*iterator = std::move(pokemon);
}

UniquePokemon Box::retrievePokemon(uint32_t position){
	auto iterator = content.begin();
	iterator = iterator + position;

	return std::move(*iterator);
}

UniquePokemon Box::swapPokemon(UniquePokemon pokemon, uint32_t position){
	UniquePokemon retrievedPokemon = this->retrievePokemon(position);
	this->storePokemon(std::move(pokemon), position);
	return std::move(retrievedPokemon);
}


Pokemon& Box::getPokemon(uint32_t position){
	//ASSERT(position < this->getCapacity())

	auto iterator = content.begin();
	iterator = iterator + position;
	return **iterator;
}


uint32_t Box::getCapacity() const{
	return content.capacity();
}

uint32_t Box::getSize() const{
	uint32_t size = 0;
	for (const UniquePokemon& pokemon : content) {
		if (pokemon) size++;
	}
	return size;
}

bool Box::isFull() const{
	return this->getCapacity() == this->getSize();
}
