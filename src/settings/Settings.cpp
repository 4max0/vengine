//
// Created by max on 22.05.26.
//

#include "Settings.h"

Settings::Settings()
{
    windowHeight = 800;
    windowWidth = 600;
    windowTitle = "untitled";
}

Settings::~Settings() = default;

void Settings::setWindowTitle(const std::string& title) { windowTitle = title; }
std::string Settings::getWindowTitle() { return windowTitle; }

void Settings::setWindowHeight(const int height) { windowHeight = height; }
int Settings::getWindowHeight() const { return windowHeight; }

void Settings::setWindowWidth(const int width) { windowWidth = width; }
int Settings::getWindowWidth() const { return windowWidth; }
