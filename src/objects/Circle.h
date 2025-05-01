#pragma once
#include <glm/vec2.hpp>
#include <vector>
#include "force_field.h"

class Circle {
public:
    Circle(const glm::vec2& pos = {0.0f, 0.0f}, float r = 1.0f, const glm::vec2& vel = {0.0f, 0.0f}, float m = 1.0f);

    void Update(float deltaTime);
    void ApplyForce(const glm::vec2& force);
    void ApplyForceField(ForceField* forceField);
    void ApplyImpulse(const glm::vec2& impulse); 

    void SetPosition(const glm::vec2& p) { position = p; }
    void SetVelocity(const glm::vec2& v) { velocity = v; }
    void SetMass(float m) { mass = m; }
    void SetRadius(float r) { radius = r; }

    const glm::vec2& GetPosition() const { return position; }
    const glm::vec2& GetVelocity() const { return velocity; }

    float GetRadius() const { return radius; }
    float GetMass() const { return mass; }

private:
    glm::vec2 position; 
    glm::vec2 velocity;
    float radius;  
    float mass;
    glm::vec2 accumulatedForce; 
    static constexpr float g = -9.81f; 
};
