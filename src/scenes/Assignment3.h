#pragma once
#include "core/Simple2DScene.h"
#include "objects/circle.h"

class Assignment3 : public Simple2DScene {
public:
    Assignment3();

    void OnEnable() override {}
    void OnDisable() override {}

    void Update(float deltaTime) override;
    void Draw() override;
    void DrawGUI() override;

    const char* GetName() override { return "Assignment 3"; }

private:
    std::vector<Circle> circles;
    Circle* selected = nullptr;
    glm::vec2 dragStart;
    bool dragging = false;
};
