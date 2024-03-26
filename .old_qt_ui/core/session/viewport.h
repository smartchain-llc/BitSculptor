#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "IViewport.h"

class ViewportData {};

class Viewport: public IViewport
{
public:
    Viewport();
    uint32_t capacity() const noexcept override { return 2048; }
};

#endif // VIEWPORT_H
