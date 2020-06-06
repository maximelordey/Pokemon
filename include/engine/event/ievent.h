#ifndef IEVENT_H
#define IEVENT_H

#include <cstdint>

class IEvent {

    virtual uint32_t getEventType() = 0;

    virtual uint32_t getEventCode() = 0;

    virtual bool equal() = 0;

}

#endif