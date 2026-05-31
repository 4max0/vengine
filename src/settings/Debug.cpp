/**
 * Created by max on 25.05.26.
 *
 * @file Debug.cpp
 * @brief Implementation of the Debug class.
 */

#include "Debug.h"

Debug::Debug() : level(NONE) {}

void Debug::addLevel(const Level levelToAdd) { this->level |= levelToAdd; }
void Debug::removeLevel(const Level levelToRemove) { this->level &= ~levelToRemove; }
bool Debug::check(const Level levelToCheck) const { return (this->level & levelToCheck) != NONE; }
Debug::Level Debug::getLevel() const { return level; }
void Debug::clear() { level = NONE; }

Debug::Level operator|(const Debug::Level a, const Debug::Level b)
{
    return static_cast<Debug::Level>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}
Debug::Level operator&(const Debug::Level a, const Debug::Level b)
{
    return static_cast<Debug::Level>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b));
}
Debug::Level operator~(const Debug::Level a) { return static_cast<Debug::Level>(~static_cast<uint32_t>(a)); }
Debug::Level& operator|=(Debug::Level& a, const Debug::Level b)
{
    a = a | b;
    return a;
}
Debug::Level& operator&=(Debug::Level& a, const Debug::Level b)
{
    a = a & b;
    return a;
}
