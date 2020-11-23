#ifndef GAUGE_H
#define GAUGE_H

#include <cstdint>

class Gauge {
	public:
		Gauge(uint32_t capacity);
		Gauge(uint32_t capacity, uint32_t value);
		Gauge(const Gauge &gauge);
		Gauge(Gauge &&gauge);
		~Gauge();

		bool isEmpty() const;
		bool isFull() const;
		void setEmpty();
		void setFull();
		void fill(uint32_t value);
		void drain(uint32_t value);
		uint32_t getCapacity() const;
		uint32_t getValue() const;
		void setValue(uint32_t value);
		void init(uint32_t capacity, uint32_t value);

		Gauge& operator=(const Gauge &gauge);
		Gauge& operator=(Gauge &&gauge);

	private:
		uint32_t _capacity;
		uint32_t _value;
};

#endif
