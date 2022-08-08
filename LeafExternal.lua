---
--- Leaf Dependencies
---

VULKAN_SDK = os.getenv("VULKAN_SDK")

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/vendor/GLFW/include"
IncludeDir["ImGui"] = "%{wks.location}/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/vendor/stb_image"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"


-- Library directories relative to root folder (solution directory)
LibraryDir = {}
LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"

-- Library declarations (.lib)
Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"

-- Project Includes
group "Dependencies"
	include "vendor/GLFW"
	include "vendor/imgui"
group ""

group "Core"
	include "Leaf"
group ""
