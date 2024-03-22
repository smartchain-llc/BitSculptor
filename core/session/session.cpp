#include "session.h"
// #include "ISessionEventListener.h"
#include <omega_edit/edit.h>

static const std::string TestFilePath { "/home/orion/.zsh_history" };

void Session::SessionEventCallback(omega_session_struct* session, omega_session_event_t event, const void* ptr){
    registeredEvents_[event]();
}

Session::Session():
    filePath_{ TestFilePath }
{

    session_ = omega_edit_create_session(filePath_.c_str(), nullptr, nullptr, 0, nullptr);
}

Session::Session( const std::string& filePath ):
    filePath_{ filePath }
{
    session_ = omega_edit_create_session(filePath_.c_str(), nullptr, nullptr, 0, nullptr);
}

Session::Session( const std::string& filePath, Events& eventHandlers):
    filePath_{ std::move(filePath) },
    registeredEvents_{ std::move(eventHandlers) }
{
    session_ = omega_edit_create_session(filePath_.c_str(), nullptr, nullptr, 0, nullptr);
}
