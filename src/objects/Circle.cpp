#include "circle.h"
#include "Force_Field.h"
#include <glm/glm.hpp>

Circle::Circle(const glm::vec2& pos, float r, const glm::vec2& vel, float m) : position(pos), radius(r), velocity(vel), mass(m), accumulatedForce(0.0f, 0.0f) {}

void Circle::Update(float dt) {

    ApplyForce({0.0f, g*mass});

    glm::vec2 acceleration = accumulatedForce / mass; // F = m*a => a = F/m
    velocity += acceleration * dt;
    position += velocity * dt;

    accumulatedForce = glm::vec2(0.0f, 0.0f); // Reset accumulated force after applying it
}

void Circle::ApplyForce(const glm::vec2& force) {
    accumulatedForce += force;
}

void Circle::ApplyForceField(ForceField* forceField) {
		ApplyForce(forceField->GetForce());
}

void Circle::ApplyImpulse(const glm::vec2& impulse) {
    velocity += impulse / mass;
}

void Circle::ResolveCollisionWithPlane(const glm::vec2& planeNormal) {
    glm::vec2 N = glm::normalize(planeNormal);
    float projectedDist = glm::dot(position, N);

    if (projectedDist < radius) 
    {
        float penetration = radius - projectedDist;
        position += N * penetration;

        velocity = velocity - 2.0f * glm::dot(velocity, N) * N; // reflected = v - 2 * dot(v, n) * n
    }
}
