#ifndef SESSION_H
#define SESSION_H
#include <omega_edit/fwd_defs.h>
#include <string>
#include <map>
#include <vector>
#include "ISession.h"

class Session: public ISession
{
public:
    typedef void (*event_handler)();
    using Events = std::map<omega_session_event_t, event_handler>;

    Session();
    Session( const std::string& filePath );
    Session( const std::string& filePath, Events& eventHandlers );

    inline const std::string& FilePath() const noexcept override { return filePath_; }
    inline const std::string& CheckpointDirectory() const noexcept override { return checkpointDirectoryPath_; }

protected:
    std::string filePath_;
    std::string checkpointDirectoryPath_;

    Events registeredEvents_;

    omega_session_t* session_;

protected:
    void SessionEventCallback(omega_session_struct* session, omega_session_event_t event, const void* ptr);
};

#endif // SESSION_H
