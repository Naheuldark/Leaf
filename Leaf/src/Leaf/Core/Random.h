#pragma once

#include <glm/glm.hpp>
#include <random>

class Random {
  public:
    static void Init() { sRandomEngine.seed(std::random_device()()); }

    static uint32_t UInt() { return sDistribution(sRandomEngine); }
    static uint32_t UInt(uint32_t min, uint32_t max) { return min + (sDistribution(sRandomEngine) % (max - min + 1)); }

    static float Float() { return (float)sDistribution(sRandomEngine) / (float)std::numeric_limits<uint32_t>::max(); }

    static glm::vec3 Vec3() { return glm::vec3(Float(), Float(), Float()); }

    static glm::vec3 Vec3(float min, float max) {
        return glm::vec3(Float() * (max - min) + min, Float() * (max - min) + min, Float() * (max - min) + min);
    }

    static glm::vec3 InUnitSphere() { return glm::normalize(Vec3(-1.0f, 1.0f)); }

  private:
    static std::mt19937                                             sRandomEngine;
    static std::uniform_int_distribution<std::mt19937::result_type> sDistribution;
};
