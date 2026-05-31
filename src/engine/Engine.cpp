/**
 * Created by max on 22.05.26.
 *
 * @file Engine.cpp
 * @brief Implementation of the Engine class.
 */

#include "Engine.h"

#if defined(__INTELLISENSE__) || !defined(USE_CPP20_MODULES)
#include <vulkan/vulkan_raii.hpp>
#else
import vulkan_hpp;
#endif

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>

void Engine::run()
{
    initGLFW();
    initVulkanInstance();
    mainLoop();
}

void Engine::mainLoop() const
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

void Engine::initGLFW()
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

    glfwWindowInstance = instance;
}

void Engine::framebufferResizeCallback(GLFWwindow* window, const int width, const int height)
{
    const auto engine = static_cast<Engine*>(glfwGetWindowUserPointer(window));
    std::cout << "New size -- width " << width << " height " << height << std::endl;
    engine->settings.setWindowWidth(width);
    engine->settings.setWindowHeight(height);
}

VKAPI_ATTR vk::Bool32 VKAPI_CALL Engine::debugCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT severity,
                                                       const vk::DebugUtilsMessageTypeFlagsEXT type,
                                                       const vk::DebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                       void* pUserData)
{
    std::cerr << "validation layer: type " << to_string(type) << " msg: " << pCallbackData->pMessage << std::endl;

    return vk::False;
}

void Engine::initVulkanInstance()
{
    // Vulkans Information about the Application
    const vk::ApplicationInfo appInfo(settings.getAppName().c_str(), settings.getAppVersion(),
                                      settings.getEngineName().c_str(), settings.getEngineVersion(), vk::ApiVersion14);

    // Get the required layers
    std::vector<char const*> requiredLayers;
    if (settings.isDebug())
    {
        requiredLayers.assign(vulkanValidationLayers.begin(), vulkanValidationLayers.end());
    }

    // Check if the required layers are supported by the Vulkan implementation.
    auto layerProperties = vulkanContext.enumerateInstanceLayerProperties();
    const auto unsupportedLayerIt = std::ranges::find_if(
        requiredLayers,
        [&layerProperties](auto const& requiredLayer)
        {
            return std::ranges::none_of(layerProperties, [requiredLayer](auto const& layerProperty)
                                        { return strcmp(layerProperty.layerName, requiredLayer) == 0; });
        });
    if (unsupportedLayerIt != requiredLayers.end())
    {
        throw std::runtime_error("Required Validation Layer not supported: " + std::string(*unsupportedLayerIt));
    }

    // Get the required extensions.
    auto requiredExtensions = getRequiredInstanceExtensions();

    // Check if the required extensions are supported by the Vulkan implementation.
    auto extensionProperties = vulkanContext.enumerateInstanceExtensionProperties();
    const auto unsupportedPropertyIt = std::ranges::find_if(
        requiredExtensions,
        [&extensionProperties](auto const& requiredExtension)
        {
            return std::ranges::none_of(extensionProperties, [requiredExtension](auto const& extensionProperty)
                                        { return strcmp(extensionProperty.extensionName, requiredExtension) == 0; });
        });
    if (unsupportedPropertyIt != requiredExtensions.end())
    {
        throw std::runtime_error("Required extension not supported: " + std::string(*unsupportedPropertyIt));
    }

    if (settings.debugLevel.check(Debug::VERBOSE))
    {
        // print the extensions available
        const auto extensions = vulkanContext.enumerateInstanceExtensionProperties();
        std::cout << "available extensions:\n";
        for (const auto& extension : extensions)
        {
            std::cout << '\t' << extension.extensionName << '\n';
        }
    }

    // Info about the vulkan instance
    const vk::InstanceCreateInfo createInfo({}, &appInfo, static_cast<uint32_t>(requiredLayers.size()),
                                            requiredLayers.data(), static_cast<uint32_t>(requiredExtensions.size()),
                                            requiredExtensions.data());
    // Vulkan instance
    vulkanInstance = vk::raii::Instance(vulkanContext, createInfo);
}

std::vector<const char*> Engine::getRequiredInstanceExtensions() const
{
    uint32_t glfwExtensionCount = 0;
    const auto glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
    if (settings.isDebug())
    {
        extensions.push_back(vk::EXTDebugUtilsExtensionName);
    }

    return extensions;
}
