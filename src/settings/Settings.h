//
// Created by max on 22.05.26.
//

#ifndef UNTITLED_SETTINGS_H
#define UNTITLED_SETTINGS_H

#include <string>


class Settings
{
public:
    Settings();
    ~Settings();
    void setWindowTitle(const std::string& title);
    std::string getWindowTitle();
    [[nodiscard]] int getWindowHeight() const;
    void setWindowHeight(int height);
    [[nodiscard]] int getWindowWidth() const;
    void setWindowWidth(int width);

private:
    int windowHeight;
    int windowWidth;
    std::string windowTitle;
};


#endif // UNTITLED_SETTINGS_H
