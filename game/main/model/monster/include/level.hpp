#ifndef LEVEL_H
#define LEVEL_H

#include <cstdint>
#include "gauge.h"

class Level {
	public:
		Level();
		Level(uint32_t max);
		Level(uint32_t max, uint32_t value);

		void levelUp();
		void setLevel(uint32_t value);

		uint32_t getLevelMax() const;
		uint32_t getLevel() const;
		bool isLevelMax() const;

	private:
		Gauge gauge;
};


#endif
