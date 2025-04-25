#include "circle.h"
#include "Force_Field.h"


Circle::Circle(const glm::vec2& pos, float r, const glm::vec2& vel) : position(pos), velocity(vel), radius(r), accumulatedForce(0.0f,0.0f) {}

void Circle::Update(float dt) {

    ApplyForce({0.0f, g*radius});

    glm::vec2 acceleration = accumulatedForce / radius; // F = m*a => a = F/m
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
    if (forceField->IsInside(position)) 
		ApplyForce(forceField->GetForce());
}
