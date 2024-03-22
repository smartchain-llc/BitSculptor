#ifndef SESSIONVIEWPORTMANAGER_H
#define SESSIONVIEWPORTMANAGER_H

#include "ISession.h"
#include "IViewport.h"

#include <unordered_map>>
#include <unordered_set>

class SessionViewportManager
{
public:
    SessionViewportManager();
    void Register(ISession*);
    void AddViewport(ISession*, IViewport*);

protected:
    std::unordered_map<ISession*, std::unordered_set<IViewport*>> sessionViewportMap_ {};
};

#endif // SESSIONVIEWPORTMANAGER_H
