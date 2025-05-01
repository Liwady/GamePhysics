#include "circle.h"
#include "Force_Field.h"


Circle::Circle(const glm::vec2& pos, float r, const glm::vec2& vel, float m) : position(pos), radius(r), velocity(vel), mass(m), accumulatedForce(0.0f, 0.0f) {}

void Circle::Update(float dt) {

    ApplyForce({0.0f, g*mass});

    glm::vec2 acceleration = accumulatedForce / mass; // F = m*a => a = F/m
    velocity += acceleration * dt;
    position += velocity * dt;

    accumulatedForce = glm::vec2(0.0f, 0.0f); // Reset accumulated force after applying it

    if (position.y - radius <= 0.0f) 
    {
        position.y = radius;
        velocity.y = -velocity.y;
    }
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
