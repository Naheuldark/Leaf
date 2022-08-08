#pragma once

#include <string>
#include <vulkan/vulkan.h>

namespace Leaf {

enum class ImageFormat { NONE = 0, RGBA, RGBA32F };

class Image {
  public:
    Image(std::string_view iPath);
    Image(uint32_t iWidth, uint32_t iHeight, ImageFormat iFormat, const void* iData = nullptr);
    ~Image();

    void setData(const void* iData);

    void resize(uint32_t iWidth, uint32_t iHeight);

    uint32_t width() const { return _width; }
    uint32_t height() const { return _height; }

    // Vulkan
    VkDescriptorSet GetDescriptorSet() const { return _descriptorSet; }

  private:
    void allocateMemory(uint64_t iSize);
    void release();

  private:
    std::string _filepath;
    uint32_t    _width = 0, _height = 0;

    ImageFormat _format = ImageFormat::NONE;

    size_t          _alignedSize         = 0;
    VkImage         _image               = nullptr;
    VkImageView     _imageView           = nullptr;
    VkDeviceMemory  _memory              = nullptr;
    VkSampler       _sampler             = nullptr;
    VkBuffer        _stagingBuffer       = nullptr;
    VkDeviceMemory  _stagingBufferMemory = nullptr;
    VkDescriptorSet _descriptorSet       = nullptr;
};
}
