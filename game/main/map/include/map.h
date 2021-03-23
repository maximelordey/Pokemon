#ifndef MAP_H
#define MAP_H

#include <vector>

#include "tile.h"

typedef struct Map{
	std::vector<Tile> _tiles;
} Map;


#endif
