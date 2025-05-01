#include "GroundPlane.h"
#include <glm/glm.hpp>

GroundPlane::GroundPlane(const glm::vec2& a, const glm::vec2& b) : pointA(a), pointB(b) {
    glm::vec2 dir = b - a;
    normal = glm::normalize(glm::vec2(-dir.y, dir.x));
}

const glm::vec2& GroundPlane::GetNormal() const {
    return normal;
}

const glm::vec2& GroundPlane::GetPointA() const {
    return pointA;
}

const glm::vec2& GroundPlane::GetPointB() const {
    return pointB;
}
