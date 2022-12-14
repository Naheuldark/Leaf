#pragma once

#include <chrono>
#include <iostream>
#include <string>

namespace Leaf {

class Timer {
  public:
    Timer() { reset(); }
    ~Timer() = default;

    void reset() { _start = std::chrono::high_resolution_clock::now(); }

    float elapsed() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - _start).count() * 0.0000001f;
    }

    float elapsedMillis() { return elapsed() * 1000.0f; }

  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
};

class ScopedTimer {
  public:
    ScopedTimer(const std::string& iName) : _name(iName) {}

    ~ScopedTimer() {
        float time = _timer.elapsedMillis();
        std::cout << "[TIMER] " << _name << " - " << time << "ms\n";
    }

  private:
    std::string _name;
    Timer       _timer;
};
}
