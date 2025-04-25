#include "circle.h"

Circle::Circle(const glm::vec2& pos, float r, const glm::vec2& vel) : position(pos), velocity(vel), radius(r) {}

void Circle::Update(float dt) {

    velocity.y += g * dt;
    position += velocity * dt;

    if (position.y - radius <= 0.0f) 
    {
        position.y = radius;
        velocity.y = -velocity.y;
    }
}
