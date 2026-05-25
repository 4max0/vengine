#ifndef VENGINE_DEBUG_H
#define VENGINE_DEBUG_H

#include <cstdint>

class Debug
{
public:
    Debug();
    enum Level : uint32_t
    {
        NONE = 0,
        ERROR = 1 << 0,
        WARNING = 1 << 1,
        INFO = 1 << 2,
        VERBOSE = 1 << 3,

        ALL = 0xF
    };
    // Deleted assignment so the object can't be manipulated
    Debug& operator=(const Debug&) = delete;
    // to add a Level
    void addLevel(Level levelToAdd);
    // to remove a Level
    void removeLevel(Level levelToRemove);
    // to check for a Level
    [[nodiscard]] bool check(Level levelToCheck) const;
    // to get the Level instance
    [[nodiscard]] Level getLevel() const;
    // to clear the Level
    void clear();

private:
    Level level;
};

// override of the bitwise operations for Debug
inline Debug::Level operator|(Debug::Level a, Debug::Level b);
inline Debug::Level operator&(Debug::Level a, Debug::Level b);
inline Debug::Level operator~(Debug::Level a);
inline Debug::Level& operator|=(Debug::Level& a, Debug::Level b);
inline Debug::Level& operator&=(Debug::Level& a, Debug::Level b);

#endif
