#include "Impulse.h"
#include <glm/glm.hpp>

glm::vec2 Impulse::CalculateVelocity(const glm::vec2& impulse, float mass) {
    return impulse / mass;
}

std::vector<glm::vec2> Impulse::PredictTrajectory( const glm::vec2& startPos, const glm::vec2& initialVelocity, float mass, float radius, float timeStep, int steps) {
    std::vector<glm::vec2> points;
    glm::vec2 pos = startPos;
    glm::vec2 vel = initialVelocity;
    const glm::vec2 gravity(0.0f, -9.81f);

    for (int i = 0; i < steps; ++i) 
    {
        vel += gravity * timeStep;
        pos += vel * timeStep;

        if (pos.y - radius <= 0.0f) {
            pos.y = radius;
            vel.y = -vel.y;
        }

        points.push_back(pos);
    }

    return points;
}
