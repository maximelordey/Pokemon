#include "pokemon.h"

Pokemon::Pokemon()
	: _name(), _specie(), _height(), _weight(),
	_health(), _level(), _experience(), _iv(), _ev() 
{}

Pokemon::Pokemon(PokemonCreateInfo infos)
	: _name(infos._name), _specie(infos._specie), _height(infos._height),
	_weight(infos._weight), _health(infos._health), _level(infos._level),
	_experience(infos._experience), _iv(infos._iv), _ev(infos._ev) 
{}
