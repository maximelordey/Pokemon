#include "translation.h"

Translation::Translation()
	: _identifier(), _translations()
{}

Translation::Translation(const Identifier& identifier) 
	: _identifier(identifier), _translations()
{}
