#pragma once
#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/GroundPlane.h"

class Assignment4 : public Simple2DScene {
public:
    Assignment4();

    void OnEnable() override {}
    void OnDisable() override {}

    void Update(float deltaTime) override;
    void Draw() override;
    void DrawGUI() override;

    const char* GetName() override { return "Assignment 4"; }

private:
    Circle circle;
    GroundPlane ground;
    bool simulate;
};
