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

private:
    glm::vec2 position; 
    float radius;      
    glm::vec2 force;   
};
