#include "omegaeditclientfacade.h"
#include <omega_edit.h>
#include <string>

static const std::string TestFilePath { "/home/orion/.zsh_history" };

OmegaEditClientFacade::OmegaEditClientFacade() {}
Viewport::Viewport(
    omega_session_t* parentSession,
    uint32_t capacity
    ):
    session_{ parentSession },
    capacity_{ capacity }
{
    viewport_ptr_ = omega_edit_create_viewport(parentSession, 0, capacity_, 0, nullptr, nullptr, 0);
}

const omega_byte_t* Viewport::data() {
    return omega_viewport_get_data(viewport_ptr_);
}

void SessionEventCallback(const omega_session_t* session, omega_session_event_t event, const void* udo){
    ViewportData* obj = (ViewportData*)udo;

}

omega_session_t* OmegaEditClientFacade::CreateSession(
    const char* FilePath
) {
    if(!FilePath) FilePath = TestFilePath.c_str();

    return omega_edit_create_session(FilePath, &SessionEventCallback, nullptr, omega_session_event_t::SESSION_EVT_CREATE, nullptr);
}

