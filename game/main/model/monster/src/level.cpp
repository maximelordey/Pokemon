#include "level.hpp"

Level::Level()
	: gauge()
{}

Level::Level(uint32_t max)
	: gauge(max)
{}

Level::Level(uint32_t max, uint32_t value)
	: gauge(max)
{
	gauge.setValue(value);
}

void Level::levelUp(){
	return gauge.add(1u);
}

void Level::setLevel(uint32_t value){
	//TODO: assert(value < gauge.getValueMax())
	return gauge.setValue(value);
}

uint32_t Level::getLevelMax() const{
	return gauge.getCapacity();
}

uint32_t Level::getLevel() const{
	return gauge.getValue();
}

bool Level::isLevelMax() const{
	return gauge.isFull();
}
