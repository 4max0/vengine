//
// Created by max on 22.05.26.
//
#ifndef UNTITLED_ENGINE_H
#define UNTITLED_ENGINE_H

#if defined(__INTELLISENSE__) || !defined(USE_CPP20_MODULES)
#include <vulkan/vulkan_raii.hpp>
#else
import vulkan_hpp;
#endif
#define GLFW_INCLUDE_VULKAN

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
    GLFWwindow* glfwWindowInstance;
    vk::raii::Context vulkanContext;
    vk::raii::Instance vulkanInstance;
    // const std::vector<char const*> vulkanValidationLayers = {"VK_LAYER_KHRONOS_validation"};

    GLFWwindow* initGLFW();
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    [[nodiscard]] vk::raii::Instance initVulkanInstance() const;
    // void initVulkanSurface();
    // void initVulkanPhysicalDevice();
    // void initVulkanLogicalDevice();
    // void initVulkanSwapChain();
    // void initVulkanRenderPass();
    // void initVulkanPipeline();
    // void initVulkanCommandPool();
    // void initVulkanCommandBuffer();
};

#endif // UNTITLED_ENGINE_H
