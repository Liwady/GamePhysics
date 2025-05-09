#pragma once
#include <glm/vec2.hpp>

class ForceField {
public:
    ForceField(const glm::vec2& position, float radius, const glm::vec2& force);

    const glm::vec2& GetPosition() const;
    const glm::vec2& GetForce() const; 
    float GetRadius() const; 

    void SetForce(const glm::vec2& force);
    void SetPosition(const glm::vec2& position);
    void SetRadius(float radius);  
    void SetDragCoefficient(float drag);
    float GetDragCoefficient() const;

    glm::vec2 ComputeForce(const glm::vec2& objPos, const glm::vec2& objVel) const;

    private:
    glm::vec2 position; 
    float radius;      
    glm::vec2 force; 
    float dragCoefficient = 0.0f; 
};
