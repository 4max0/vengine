/**
 * Created by max on 22.05.26.
 *
 * @file Settings.cpp
 * @brief Implementation of the Settings class.
 */

#include "Settings.h"
#include "Debug.h"
#include "vulkan/vulkan_core.h"

Settings::Settings() :
    engineName("Vengine"), engineVersion(VK_MAKE_VERSION(0, 1, 0)), appName("untitled"),
    appVersion(VK_MAKE_VERSION(1, 0, 0)), windowTitle("untitled"), windowWidth(600), windowHeight(800),
    debug(debugYesOrNo())
{
    debugLevel.addLevel(Debug::Level::ERROR);
    debugLevel.addLevel(Debug::Level::WARNING);
}

const std::string& Settings::getEngineName() const { return engineName; }
uint32_t Settings::getEngineVersion() const { return engineVersion; }

void Settings::setAppName(const std::string& title) { appName = title; }
const std::string& Settings::getAppName() const { return appName; }
void Settings::setAppVersion(const uint32_t version) { appVersion = version; }
uint32_t Settings::getAppVersion() const { return appVersion; }

void Settings::setWindowTitle(const std::string& title) { windowTitle = title; }
const std::string& Settings::getWindowTitle() const { return windowTitle; }
void Settings::setWindowHeight(const uint32_t height) { windowHeight = height; }
uint32_t Settings::getWindowHeight() const { return windowHeight; }
void Settings::setWindowWidth(const uint32_t width) { windowWidth = width; }
uint32_t Settings::getWindowWidth() const { return windowWidth; }

bool Settings::isDebug() const { return debug; }

bool Settings::debugYesOrNo()
{
#ifndef NDEBUG
    return true;
#else
    return false;
#endif
}
