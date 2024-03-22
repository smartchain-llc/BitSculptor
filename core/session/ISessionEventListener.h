#ifndef ISESSIONEVENTLISTENER_H
#define ISESSIONEVENTLISTENER_H

#include <cstdint>

class ISessionEventListener {
public:
    virtual ~ISessionEventListener() = default;
    virtual void handler(class omega_session_struct* session, class omega_session_event_t* event, const void* ptr) = 0;
};

#endif // ISESSIONEVENTLISTENER_H
