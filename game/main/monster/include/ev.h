#ifndef EV_H
#define EV_H

#include <cstdint>
#include "gauge.h"

class Ev {
	public:
		Ev();
		Ev(uint32_t total_limit, uint32_t stat_limit);

		bool isHealthEmpty() const;
		bool isHealthFull() const;
		void setHealthEmpty();
		void setHealthFull();
		void addHealth(uint32_t value);
		void removeHealth(uint32_t value);
		uint32_t getHealthCapacity() const;
		uint32_t getHealthValue() const;
		void setHealthValue(uint32_t value);
		void initHealth(uint32_t capacity, uint32_t value);

		bool isAttackEmpty() const;
		bool isAttackFull() const;
		void setAttackEmpty();
		void setAttackFull();
		void addAttack(uint32_t value);
		void removeAttack(uint32_t value);
		uint32_t getAttackCapacity() const;
		uint32_t getAttackValue() const;
		void setAttackValue(uint32_t value);
		void initAttack(uint32_t capacity, uint32_t value);

		bool isDefenceEmpty() const;
		bool isDefenceFull() const;
		void setDefenceEmpty();
		void setDefenceFull();
		void addDefence(uint32_t value);
		void removeDefence(uint32_t value);
		uint32_t getDefenceCapacity() const;
		uint32_t getDefenceValue() const;
		void setDefenceValue(uint32_t value);
		void initDefence(uint32_t capacity, uint32_t value);

		bool isAttackSpeEmpty() const;
		bool isAttackSpeFull() const;
		void setAttackSpeEmpty();
		void setAttackSpeFull();
		void addAttackSpe(uint32_t value);
		void removeAttackSpe(uint32_t value);
		uint32_t getAttackSpeCapacity() const;
		uint32_t getAttackSpeValue() const;
		void setAttackSpeValue(uint32_t value);
		void initAttackSpe(uint32_t capacity, uint32_t value);

		bool isDefenceSpeEmpty() const;
		bool isDefenceSpeFull() const;
		void setDefenceSpeEmpty();
		void setDefenceSpeFull();
		void addDefenceSpe(uint32_t value);
		void removeDefenceSpe(uint32_t value);
		uint32_t getDefenceSpeCapacity() const;
		uint32_t getDefenceSpeValue() const;
		void setDefenceSpeValue(uint32_t value);
		void initDefenceSpe(uint32_t capacity, uint32_t value);

		bool isSpeedEmpty() const;
		bool isSpeedFull() const;
		void setSpeedEmpty();
		void setSpeedFull();
		void addSpeed(uint32_t value);
		void removeSpeed(uint32_t value);
		uint32_t getSpeedCapacity() const;
		uint32_t getSpeedValue() const;
		void setSpeedValue(uint32_t value);
		void initSpeed(uint32_t capacity, uint32_t value);

		uint32_t getTotalStats() const;
		bool isFull();

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
