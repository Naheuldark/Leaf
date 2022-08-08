# Leaf
Leaf is a simple application framework built with Dear ImGui and designed to be used with Vulkan - basically this means you can seemlessly blend real-time Vulkan rendering with a great UI library to build desktop applications. The plan is to expand Leaf to include common utilities to make immediate-mode desktop apps and simple Vulkan applications.

Currently supports Windows - with macOS and Linux support planned. Setup scripts support Visual Studio 2022 by default.

## Requirements
- [Visual Studio 2022](https://visualstudio.com) (not strictly required, however included setup scripts only support this)
- [Vulkan SDK](https://vulkan.lunarg.com/sdk/home#windows) (preferably a recent version)

## Getting Started
Once you've cloned, run `scripts/Setup.bat` to generate Visual Studio 2022 solution/project files. Once you've opened the solution, you can run the LeafApp project to see a basic example (code in `LeafApp.cpp`). I recommend modifying that LeafApp project to create your own application, as everything should be setup and ready to go.

### 3rd party libaries
- [Dear ImGui](https://github.com/ocornut/imgui)
- [GLFW](https://github.com/glfw/glfw)
- [stb_image](https://github.com/nothings/stb)
- [GLM](https://github.com/g-truc/glm) (included for convenience)

### Additional
- Leaf uses the [Roboto](https://fonts.google.com/specimen/Roboto) font ([Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0))