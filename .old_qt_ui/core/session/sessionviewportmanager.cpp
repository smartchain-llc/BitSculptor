#include "sessionviewportmanager.h"

SessionViewportManager::SessionViewportManager() {

}

void SessionViewportManager::Register(ISession* session){

}
void SessionViewportManager::AddViewport(ISession* session, IViewport* viewport){
    sessionViewportMap_[session];
}
