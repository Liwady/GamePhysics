#pragma once

#include "core/Simple2DScene.h"
#include <glm/vec2.hpp>
#include "objects/circle.h"

class Assignment1 : public Simple2DScene 
{
public:
    Assignment1();

    void OnEnable() override;
    void OnDisable() override;

    void Update(float deltaTime) override;

    void Draw() override;
    void DrawGUI() override;

    const char* GetName() override { return "Assignment 1"; };

private:
    Circle circle; 
    bool simulate; 
};