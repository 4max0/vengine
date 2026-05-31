/**
 * Created by max on 25.05.26.
 *
 * @file Debug.h
 * @brief Declaration of the Debug class.
 */

#ifndef VENGINE_DEBUG_H
#define VENGINE_DEBUG_H

#include <cstdint>

/**
 * @brief Stores and manages active debug levels.
 *
 * Provides a bitmask-based interface for enabling,
 * disabling, and querying debug output categories.
 */
class Debug
{
public:
    /**
     * @brief Creates a Debug instance with no active levels.
     */
    Debug();

    /**
     * @brief Available debug output levels.
     */
    enum Level : uint32_t
    {
        /// No debug output.
        NONE = 0,
        /// Error messages.
        ERROR = 1 << 0,

        /// Warning messages.
        WARNING = 1 << 1,

        /// Informational messages.
        INFO = 1 << 2,

        /// Verbose diagnostic output.
        VERBOSE = 1 << 3,

        /// All debug levels.
        ALL = 0xF
    };

    /**
     * @brief Assignment operator is disabled.
     */
    Debug& operator=(const Debug&) = delete;

    /**
     * @brief Enables a debug level.
     *
     * @param levelToAdd Level to enable.
     */
    void addLevel(Level levelToAdd);

    /**
     * @brief Disables a debug level.
     *
     * @param levelToRemove Level to disable.
     */
    void removeLevel(Level levelToRemove);

    /**
     * @brief Checks whether a debug level is enabled.
     *
     * @param levelToCheck Level to test.
     * @return True if the level is enabled.
     */
    [[nodiscard]] bool check(Level levelToCheck) const;

    /**
     * @brief Returns the currently active debug levels.
     *
     * @return Current debug level bitmask.
     */
    [[nodiscard]] Level getLevel() const;

    /**
     * @brief Disables all debug levels.
     */
    void clear();

private:
    /// @brief Currently active debug levels.
    Level level;
};

/**
 * @brief Combines two debug levels.
 *
 * @param a First level.
 * @param b Second level.
 * @return Combined level mask.
 */
inline Debug::Level operator|(Debug::Level a, Debug::Level b);

/**
 * @brief Computes the intersection of two debug levels.
 *
 * @param a First level.
 * @param b Second level.
 * @return Resulting level mask.
 */
inline Debug::Level operator&(Debug::Level a, Debug::Level b);

/**
 * @brief Inverts a debug level mask.
 *
 * @param a Level mask.
 * @return Inverted level mask.
 */
inline Debug::Level operator~(Debug::Level a);

/**
 * @brief Combines and assigns debug levels.
 *
 * @param a Target level mask.
 * @param b Level mask to combine.
 * @return Reference to the modified level mask.
 */
inline Debug::Level& operator|=(Debug::Level& a, Debug::Level b);

/**
 * @brief Intersects and assigns debug levels.
 *
 * @param a Target level mask.
 * @param b Level mask to intersect with.
 * @return Reference to the modified level mask.
 */
inline Debug::Level& operator&=(Debug::Level& a, Debug::Level b);

#endif
