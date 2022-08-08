#pragma once

#include "Leaf/Core/Application.h"

#ifdef LF_PLATFORM_WINDOWS

extern Leaf::Application* Leaf::CreateApplication(int argc, char** argv);

// Global variable (used in Application.cpp)
bool gApplicationRunning = true;

namespace Leaf {

int Main(int argc, char** argv) {
    while (gApplicationRunning) {
        Leaf::Application* app = Leaf::CreateApplication(argc, argv);
        app->run();
        delete app;
    }
    return EXIT_SUCCESS;
}
}

#ifdef LF_DIST

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) { return Leaf::Main(__argc, __argv); }

#else

int main(int argc, char** argv) { return Leaf::Main(argc, argv); }

#endif // LF_DIST

#endif // LF_PLATFORM_WINDOWS
