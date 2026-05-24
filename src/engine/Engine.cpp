//
// Created by max on 22.05.26.
//
#include "Engine.h"
#include <GLFW/glfw3.h>
#include <iostream>

Engine::Engine() : window(nullptr)
{
    settings = Settings();
    initGLFW();
    initVulkan();
};

Engine::~Engine()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Engine::run() const
{
    std::cout << "hello world";
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        // TODO:
        // update
        // render
    }
}

void Engine::initGLFW()
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(settings.getWindowWidth(), settings.getWindowHeight(), settings.getWindowTitle().c_str(),
                              nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void Engine::framebufferResizeCallback(GLFWwindow* window, const int width, const int height)
{
    const auto engine = static_cast<Engine*>(glfwGetWindowUserPointer(window));

    std::cout << "New size -- width " << width << " height " << height << std::endl;

    engine->settings.setWindowWidth(width);
    engine->settings.setWindowHeight(height);
}

void Engine::initVulkan()
{
    // TODO:
    // Vulkan Instance
    // Surface mit GLFW
    // Physical Device auswählen
    // Logical Device
    // Swapchain
    // Render Pass
    // Pipeline
    // Command Buffers
}
