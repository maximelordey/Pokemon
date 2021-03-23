#ifndef TILE_TYPE_H
#define TILE_TYPE_H

#include "identifier.h"

typedef struct Tiletype{
	Identifier _identifier;
	bool _walkable;
	bool _surfable;	
} Tiletype;

#endif
