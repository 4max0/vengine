//
// Created by max on 22.05.26.
//

#ifndef UNTITLED_ENGINE_H
#define UNTITLED_ENGINE_H

#include <GLFW/glfw3.h>
#include "../settings/Settings.h"


class Engine
{
public:
    Engine();
    ~Engine();
    void run() const;


private:
    Settings settings;
    GLFWwindow* window;
    void initGLFW();
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    void initVulkan();
};


#endif // UNTITLED_ENGINE_H
