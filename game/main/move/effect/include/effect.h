#ifndef EFFECT_H
#define EFFECT_H

#include "identifier.h"

class Effect {
	public:
		Effect();
		Effect(const Identifier& identifier);
		
	public:
		Identifier _identifier;
};

#endif
