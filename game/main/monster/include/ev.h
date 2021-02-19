#ifndef EV_H
#define EV_H

#include <cstdint>
#include "gauge.h"

class Ev {
	public:
		Ev();
		Ev(uint32_t total_limit, uint32_t stat_limit);

		void setHealth(uint32_t value);
		void setAttack(uint32_t value);
		void setDefence(uint32_t value);
		void setAttackSpe(uint32_t value);
		void setDefenceSPe(uint32_t value);
		void setSpeed(uint32_t value);

		uint32_t getHealth() const;
		uint32_t getAttack() const;
		uint32_t getDefence() const;
		uint32_t getAttackSpe() const;
		uint32_t getDefenceSpe() const;
		uint32_t getSpeed() const;

		uint32_t getTotalStats() const;

	private:
		Gauge _health;
		Gauge _attack;
		Gauge _defence;
		Gauge _attackSpe;
		Gauge _defenceSpe;
		Gauge _speed;
		uint32_t _total_limit;
};

#endif
