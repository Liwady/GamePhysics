#pragma once
#include <glm/vec2.hpp>
#include "core/Simple2DScene.h"
#include "objects/circle.h"
#include "objects/Force_Field.h"

class Assignment2 : public Simple2DScene {
public:
    Assignment2();

    void OnEnable() override;
    void OnDisable() override;

    void Update(float deltaTime) override;

    void Draw() override;
    void DrawGUI() override;

    const char* GetName() override { return "Assignment 1"; };

private:
    Circle circle;
    bool simulate;
    std::vector<ForceField> forceFields;
};