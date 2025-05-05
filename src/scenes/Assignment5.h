#pragma once
#include "core/Simple2DScene.h"
#include "objects/circle.h"
#include "objects/PoolTable.h"

class Assignment5 : public Simple2DScene {
public:
    Assignment5();

    void OnEnable() override;
    void OnDisable() override {}

    void Update(float deltaTime) override;
    void Draw() override;
    void DrawGUI() override;

    const char* GetName() override { return "Assignment 5 - Pool"; }

private:
    Circle cBall;
    bool dragging;
    glm::vec2 dragStart;
    PoolTable table;
    ForceField dragField;
};
