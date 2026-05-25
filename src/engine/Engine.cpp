//
// Created by max on 22.05.26.
//

#include "Engine.h"

#if defined(__INTELLISENSE__) || !defined(USE_CPP20_MODULES)
#include <vulkan/vulkan_raii.hpp>
#else
import vulkan_hpp;
#endif

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>

Engine::Engine() : settings(Settings()), glfwWindowInstance(initGLFW()), vulkanInstance(initVulkanInstance())
{
    // Surface mit GLFW
    // Physical Device auswählen
    // Logical Device
    // Swap-Chain
    // Render Pass
    // Pipeline
    // Command Buffers
}


Engine::~Engine()
{
    glfwDestroyWindow(glfwWindowInstance);
    glfwTerminate();
}

void Engine::run() const
{
    std::cout << "hello world";
    while (!glfwWindowShouldClose(glfwWindowInstance))
    {
        glfwPollEvents();
        // TODO:
        // update
        // render
    }
}

GLFWwindow* Engine::initGLFW()
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    // deactivating the API of GLFW because of vulkan
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    // create the GLFW instance
    // NOTE: IDK if this should be a cast, or I should just use int instead of uint
    GLFWwindow* instance =
        glfwCreateWindow(static_cast<int>(settings.getWindowWidth()), static_cast<int>(settings.getWindowHeight()),
                         settings.getWindowTitle().c_str(), nullptr, nullptr);
    if (!instance)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwSetWindowUserPointer(instance, this);
    glfwSetFramebufferSizeCallback(instance, framebufferResizeCallback);

    return instance;
}

void Engine::framebufferResizeCallback(GLFWwindow* window, const int width, const int height)
{
    const auto engine = static_cast<Engine*>(glfwGetWindowUserPointer(window));
    std::cout << "New size -- width " << width << " height " << height << std::endl;
    engine->settings.setWindowWidth(width);
    engine->settings.setWindowHeight(height);
}

vk::raii::Instance Engine::initVulkanInstance() const
{
    // Vulkans Information about the Application
    const vk::ApplicationInfo appInfo(settings.getAppName().c_str(), settings.getAppVersion(),
                                      settings.getEngineName().c_str(), settings.getEngineVersion(),
                                      VK_API_VERSION_1_4);

    // Get the vulkans extensions needed by GLFW
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    auto extensionProperties = vulkanContext.enumerateInstanceExtensionProperties();
    for (uint32_t i = 0; i < glfwExtensionCount; ++i)
    {
        if (std::ranges::none_of(extensionProperties, [glfwExtension = glfwExtensions[i]](const auto& extensionProperty)
                                 { return strcmp(extensionProperty.extensionName, glfwExtension) == 0; }))
        {
            throw std::runtime_error("Required GLFW extension not supported: " + std::string(glfwExtensions[i]));
        }
    }


    if (settings.debugLevel.check(settings.debugLevel.VERBOSE))
    {
        // print the extensions available
        const auto extensions = vulkanContext.enumerateInstanceExtensionProperties();
        std::cout << "available extensions:\n";
        for (const auto& extension : extensions)
        {
            std::cout << '\t' << extension.extensionName << '\n';
        }
    }

    // // Get the required layers
    // std::vector<char const*> requiredLayers;
    // if (settings.isDebug())
    // {
    //     requiredLayers.assign(vulkanValidationLayers.begin(), vulkanValidationLayers.end());
    // }
    //
    // // Check if the required layers are supported by the Vulkan implementation.
    // auto layerProperties = vulkanContext.enumerateInstanceLayerProperties();
    // const auto unsupportedLayerIt = std::ranges::find_if(
    //     requiredLayers,
    //     [&layerProperties](auto const& requiredLayer)
    //     {
    //         return std::ranges::none_of(layerProperties, [requiredLayer](auto const& layerProperty)
    //                                     { return strcmp(layerProperty.layerName, requiredLayer) == 0; });
    //     });
    // if (unsupportedLayerIt != requiredLayers.end())
    // {
    //     throw std::runtime_error("Required Validation Layer not supported: " + std::string(*unsupportedLayerIt));
    // }

    // Info about the vulkan instance
    const vk::InstanceCreateInfo createInfo({}, &appInfo, 0, nullptr, glfwExtensionCount, glfwExtensions);
    // Vulkan instance
    auto instance = vk::raii::Instance(vulkanContext, createInfo);
    return instance;
}
