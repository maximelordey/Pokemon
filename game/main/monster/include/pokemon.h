#ifndef POKEMON_H
#define POKEMON_H

#include <string>

#include "pokemon_create_info.h"
#include "specie.h"
#include "height.h"
#include "weight.h"
#include "health.h"
#include "level.h"
#include "experience.h"
#include "iv.h"
#include "ev.h"
#include "nature.h"
#include "translation.h"
#include "identifier.h"

class Pokemon {
	private:
		static uint32_t computeStat(uint32_t _baseStat, uint32_t iv, uint32_t ev, Level level, Coefficient coefficient);
		static uint32_t computeMaxHealth(uint32_t _baseStat, uint32_t iv, uint32_t ev, Level level);
	
	public:
		Pokemon();
		Pokemon(PokemonCreateInfo infos);

		uint32_t getAttack() const;
		uint32_t getDefence() const;
		uint32_t getAttackSpe() const;
		uint32_t getDefenceSpe() const;
		uint32_t getSpeed() const;

		bool isExperienceEmpty() const;
		bool isExperienceFull() const;
		void setExperienceEmpty();
		void setExperienceFull();
		void addExperience(uint32_t value);
		void removeExperience(uint32_t value);
		uint32_t getExperienceMax() const;
		uint32_t getExperience() const;
		void setExperience(uint32_t value);

		bool isLevelEmpty() const;
		bool isLevelFull() const;
		void setLevelEmpty();
		void setLevelFull();
		void addLevel(uint32_t value);
		void removeLevel(uint32_t value);
		uint32_t getLevelMax() const;
		uint32_t getLevel() const;
		void setLevel(uint32_t value);
	
	private:
		void updateHealth();
		void updateExperience();

	public:
		Identifier _identifier;
		Translation _name;
		Specie _specie;
		Height _height;
		Weight _weight;
		Health _health;
		Iv _iv;
		Ev _ev;
		Nature _nature;

	private:
		Level _level;
		Experience _experience;
};

#endif
