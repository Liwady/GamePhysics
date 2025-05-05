#include "objects/Force_Field.h"
#include <glm/glm.hpp>

ForceField::ForceField(const glm::vec2& position, float radius, const glm::vec2& force) : position(position), radius(radius), force(force) {}

const glm::vec2& ForceField::GetPosition() const {
    return position;
}

const glm::vec2& ForceField::GetForce() const 
{
    return force;
}

float ForceField::GetRadius() const {
    return radius;
}

void ForceField::SetForce(const glm::vec2& force) {
    this->force = force;
}

void ForceField::SetPosition(const glm::vec2& position) {
    this->position = position;
}

void ForceField::SetRadius(float radius) {
    this->radius = radius;
}

float ForceField::GetDragCoefficient() const {
    return dragCoefficient;
}

void ForceField::SetDragCoefficient(float drag) {
    dragCoefficient = drag;
}

glm::vec2 ForceField::ComputeForce(const glm::vec2& objPos, const glm::vec2& objVel) const {
    glm::vec2 drag = -dragCoefficient * objVel;
    return force + drag;
}
