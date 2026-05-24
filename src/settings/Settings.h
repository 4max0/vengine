//
// Created by max on 22.05.26.
//

#ifndef UNTITLED_SETTINGS_H
#define UNTITLED_SETTINGS_H

#include <string>
#include <vulkan/vulkan_core.h>

class Settings
{
public:
    Settings();

    [[nodiscard]] const std::string& getEngineName() const;
    [[nodiscard]] uint32_t getEngineVersion() const;

    void setAppName(const std::string& title);
    [[nodiscard]] const std::string& getAppName() const;
    void setAppVersion(uint32_t version);
    [[nodiscard]] uint32_t getAppVersion() const;

    void setWindowTitle(const std::string& title);
    [[nodiscard]] const std::string& getWindowTitle() const;
    void setWindowHeight(uint32_t height);
    [[nodiscard]] uint32_t getWindowHeight() const;
    void setWindowWidth(uint32_t width);
    [[nodiscard]] uint32_t getWindowWidth() const;

private:
    std::string engineName;
    uint32_t engineVersion;

    std::string appName;
    uint32_t appVersion;

    std::string windowTitle;
    uint32_t windowWidth;
    uint32_t windowHeight;
};


#endif // UNTITLED_SETTINGS_H
