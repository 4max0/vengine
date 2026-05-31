/**
 * Created by max on 22.05.26.
 *
 * @file Settings.h
 * @brief Declaration of the Settings class.
 */

#ifndef UNTITLED_SETTINGS_H
#define UNTITLED_SETTINGS_H

#include <string>
#include "Debug.h"

/**
 * @brief Stores engine and application configuration.
 *
 * Contains metadata about the engine and application,
 * window configuration, and debugging settings used
 * during engine initialization and runtime.
 */
class Settings
{
public:
    /// Active debug configuration.
    Debug debugLevel;

    /**
     * @brief Creates a Settings instance with default values.
     */
    Settings();

    /**
     * @brief Returns the engine name.
     *
     * @return Engine name.
     */
    [[nodiscard]] const std::string& getEngineName() const;

    /**
     * @brief Returns the engine version.
     *
     * @return Engine version.
     */
    [[nodiscard]] uint32_t getEngineVersion() const;

    /**
     * @brief Sets the application name.
     *
     * @param title Application name.
     */
    void setAppName(const std::string& title);

    /**
     * @brief Returns the application name.
     *
     * @return Application name.
     */
    [[nodiscard]] const std::string& getAppName() const;

    /**
     * @brief Sets the application version.
     *
     * @param version Application version.
     */
    void setAppVersion(uint32_t version);

    /**
     * @brief Returns the application version.
     *
     * @return Application version.
     */
    [[nodiscard]] uint32_t getAppVersion() const;

    /**
     * @brief Sets the window title.
     *
     * @param title Window title.
     */
    void setWindowTitle(const std::string& title);

    /**
     * @brief Returns the window title.
     *
     * @return Window title.
     */
    [[nodiscard]] const std::string& getWindowTitle() const;

    /**
     * @brief Sets the window height.
     *
     * @param height Window height in pixels.
     */
    void setWindowHeight(uint32_t height);

    /**
     * @brief Returns the window height.
     *
     * @return Window height in pixels.
     */
    [[nodiscard]] uint32_t getWindowHeight() const;

    /**
     * @brief Sets the window width.
     *
     * @param width Window width in pixels.
     */
    void setWindowWidth(uint32_t width);

    /**
     * @brief Returns the window width.
     *
     * @return Window width in pixels.
     */
    [[nodiscard]] uint32_t getWindowWidth() const;

    /**
     * @brief Indicates whether debug mode is enabled.
     *
     * @return True if debug mode is enabled.
     */
    [[nodiscard]] bool isDebug() const;

private:
    /// Name of the engine.
    std::string engineName;

    /// Engine version number.
    uint32_t engineVersion;

    /// Name of the application.
    std::string appName;

    /// Application version number.
    uint32_t appVersion;

    /// Window title displayed in the title bar.
    std::string windowTitle;

    /// Window width in pixels.
    uint32_t windowWidth;

    /// Window height in pixels.
    uint32_t windowHeight;

    /// Indicates whether debug mode is enabled.
    bool debug;

    /**
     * @brief Checks for a declaration of the Debug Macro
     *
     * @return True if Debug Makro is enabled.
     */
    [[nodiscard]] static bool debugYesOrNo();
};

#endif // UNTITLED_SETTINGS_H
