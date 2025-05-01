#pragma once
#include <glm/vec2.hpp>
#include <vector>

class Impulse {
public:
    static glm::vec2 CalculateVelocity(const glm::vec2& impulse, float mass);
    static std::vector<glm::vec2> PredictTrajectory(const glm::vec2& startPos, const glm::vec2& initialVelocity, float mass, float radius, float timeStep = 0.1f, int steps = 30);
};
