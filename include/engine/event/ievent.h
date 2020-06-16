#ifndef IEVENT_H
#define IEVENT_H

#include <cstdint>

class IEvent {
    virtual uint32_t getEventType() const = 0;

    virtual uint32_t getEventCode() const = 0;
}
#endif
