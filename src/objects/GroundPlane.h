#pragma once
#include <glm/vec2.hpp>

class GroundPlane {
public:
    GroundPlane(const glm::vec2& a, const glm::vec2& b);

    const glm::vec2& GetNormal() const;
    const glm::vec2& GetPointA() const;
    const glm::vec2& GetPointB() const;

private:
    glm::vec2 pointA, pointB;
    glm::vec2 normal;
};
