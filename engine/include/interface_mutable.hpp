#ifndef INTERFACE_MUTABLE_HPP
#define INTERFACE_MUTABLE_HPP

#include "time.h"

struct InterfaceMutable {
	virtual void update(Delta delta) = 0;
};

#endif
