#ifndef IVIEWPORT_H
#define IVIEWPORT_H

#include <functional>
#include <cstdint>

class IViewport {
public:
    virtual ~IViewport() = default;
    virtual uint32_t capacity() const noexcept = 0;
};

template<>
struct std::hash<IViewport*>{
    std::size_t operator()(const IViewport* session) const noexcept { return 0; }
};
#endif // IVIEWPORT_H
