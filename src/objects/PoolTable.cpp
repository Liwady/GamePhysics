#include "PoolTable.h"

PoolTable::PoolTable(float l, float r, float b, float t)
    : left(l), right(r), bottom(b), top(t) {}

void PoolTable::ResolveCollision(Circle& ball) const {
    glm::vec2 pos = ball.GetPosition();
    glm::vec2 vel = ball.GetVelocity();
    float r = ball.GetRadius();

    if (pos.x - r < left) {
        pos.x = left + r;
        vel.x = -vel.x;
    }
    if (pos.x + r > right) {
        pos.x = right - r;
        vel.x = -vel.x;
    }
    if (pos.y - r < bottom) {
        pos.y = bottom + r;
        vel.y = -vel.y;
    }
    if (pos.y + r > top) {
        pos.y = top - r;
        vel.y = -vel.y;
    }

    ball.SetPosition(pos);
    ball.SetVelocity(vel);
}

