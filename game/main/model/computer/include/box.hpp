#ifndef BOX_HPP
#define BOX_HPP

#include <cstdint>
#include <memory>
#include <vector>

#include "pokemon.h"

class Box {
	public:
		Box();
		Box(uint32_t capacity);

		void storePokemon(UniquePokemon pokemon);
		void storePokemon(UniquePokemon pokemon, uint32_t position);
		UniquePokemon retrievePokemon(uint32_t position);
		UniquePokemon swapPokemon(UniquePokemon pokemon, uint32_t position);

		Pokemon& getPokemon(uint32_t position);

		uint32_t getCapacity() const;
		uint32_t getSize() const;
		bool isFull() const;

	private:
		std::vector<UniquePokemon> content;
};

#endif
