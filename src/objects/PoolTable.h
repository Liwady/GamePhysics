#pragma once
#include <glm/vec2.hpp>
#include "objects/circle.h"

class PoolTable {
public:
    PoolTable(float left, float right, float bottom, float top);

    void ResolveCollision(Circle& ball) const;

    float GetLeft() const { return left; }
    float GetRight() const { return right; }
    float GetTop() const { return top; }
    float GetBottom() const { return bottom; }

private:
    float left, right, bottom, top;
};
