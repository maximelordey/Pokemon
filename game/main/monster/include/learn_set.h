#ifndef LEARNSET_H
#define LEARNSET_H

#include <map>
#include <vector>
#include <cstdint> 

#include "move.h"

typedef struct {
	std::map<uint32_t, std::vector<Move>> _content;
} LearnSet;

#endif
