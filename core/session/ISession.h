#ifndef ISESSION_H
#define ISESSION_H

#include <string>
#include <functional>

class ISession {
public:
    virtual ~ISession() = default;
    virtual const std::string& FilePath() const noexcept = 0;
    virtual const std::string& CheckpointDirectory() const noexcept = 0;
};

template<>
struct std::hash<ISession*>{
    std::size_t operator()(const ISession* session) const noexcept { return 0; }
};

template<>
struct std::equal_to<ISession*>{
    const bool operator()(const ISession* lhs, const ISession* rhs) const { return lhs->FilePath() == rhs->FilePath(); }
};

#endif // ISESSION_H
