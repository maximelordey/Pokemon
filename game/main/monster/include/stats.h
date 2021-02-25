#ifndef BASE_STATS_H
#define BASE_STATS_H

#include <cstdint>

typedef struct Stats {
	uint32_t _health;
	uint32_t _attack;
	uint32_t _defence;
	uint32_t _attackSpe;
	uint32_t _defenceSpe;
	uint32_t _speed;
} Stats;

#endif
