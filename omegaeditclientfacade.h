#ifndef OMEGAEDITCLIENTFACADE_H
#define OMEGAEDITCLIENTFACADE_H
#include <cstdint>
class ViewportData {
public:
    ViewportData(uint32_t size):
        size_{ size },
        data_{ new uint8_t[size_] }
    { }
    ~ViewportData(){ if(data_) delete[] data_; }
    inline const uint32_t size() const noexcept { return size_; }
    uint8_t& at(uint32_t index) { return data_[index]; }
private:
    uint32_t size_;
    uint8_t* data_;
};

class Viewport {
public:
    Viewport(
        class omega_session_struct* parentSession,
        uint32_t capacity
        );
    inline uint32_t capacity(){ return capacity_; }
    const uint8_t* data();
private:
    omega_session_struct* session_;
    class omega_viewport_struct* viewport_ptr_;
    uint32_t capacity_;
};

class OmegaEditClientFacade
{
public:
    OmegaEditClientFacade();

    omega_session_struct* CreateSession(
        const char* FilePath
    );
};

#endif // OMEGAEDITCLIENTFACADE_H
