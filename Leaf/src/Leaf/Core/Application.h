#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <imgui.h>
#include <vulkan/vulkan.h>

#include "Leaf/Core/Layer.h"

void check_vk_result(VkResult err);
struct GLFWwindow;

namespace Leaf {

struct ApplicationSpecification {
    std::string name = "Leaf App";

    uint32_t width  = 1600;
    uint32_t height = 900;
};

class Application {
  public:
    Application(const ApplicationSpecification& iSpecifications = ApplicationSpecification());
    ~Application();

    void run();
    void close();

    template <typename T>
    void pushLayer() {
        static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
        _layerStack.emplace_back(std::make_shared<T>())->onAttach();
    }

    void pushLayer(const std::shared_ptr<Layer>& iLayer) {
        _layerStack.emplace_back(iLayer);
        iLayer->onAttach();
    }

    void setMenubarCallback(const std::function<void()>& iCallback) { _menubarCallback = iCallback; }

    // Vulkan
    static VkInstance       GetInstance();
    static VkPhysicalDevice GetPhysicalDevice();
    static VkDevice         GetDevice();
    static VkCommandBuffer  GetCommandBuffer(bool begin);
    static void             FlushCommandBuffer(VkCommandBuffer commandBuffer);
    static void             SubmitResourceFree(std::function<void()>&& func);

  private:
    void init();
    void shutdown();

  private:
    ApplicationSpecification            _specification;
    GLFWwindow*                         _windowHandle = nullptr;
    bool                                _running      = false;
    std::vector<std::shared_ptr<Layer>> _layerStack;
    std::function<void()>               _menubarCallback;
};

// To be defined in CLIENT
Application* CreateApplication(int argc, char** argv);
}
