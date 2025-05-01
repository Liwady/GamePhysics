#include "Assignment4.h"
#include <glm/glm.hpp>
#include "imgui.h"
#include "objects/Circle.h"

Assignment4::Assignment4() : circle(glm::vec2(5.f, 3.f), 0.5f, glm::vec2(0.f, 0.f), 1.0f), ground(glm::vec2(-10.f, -3.f), glm::vec2(10.f, 3.f)), simulate(false) {}

void Assignment4::Update(float deltaTime) {
    if (!simulate)
        return;

    circle.Update(deltaTime);
    circle.ResolveCollisionWithPlane(ground.GetNormal());
}

void Assignment4::Draw() {
    Draw::Line(ground.GetPointA(), ground.GetPointB());

    if (!simulate) 
    {
        glm::vec2 mid = (ground.GetPointA() + ground.GetPointB()) * 0.5f;
        Draw::Line(mid,mid + ground.GetNormal() * 1.5f); 
    }

    Draw::Circle(circle.GetPosition(), circle.GetRadius());

    glm::vec2 velocity = circle.GetVelocity();
    if (glm::length(velocity) > 0.01f) 
        Draw::Line(circle.GetPosition(), circle.GetPosition() + velocity * 0.2f);
    
}

void Assignment4::DrawGUI() {
    ImGui::SetNextWindowSize(ImVec2(300, 150), ImGuiCond_Once);
    ImGui::Begin("Assignment 4");
    ImGui::Text("Click 'Start Simulation' to begin.");

    if (!simulate) {
        glm::vec2 pos = circle.GetPosition();
        if (ImGui::DragFloat2("Start Position", &pos.x, 0.05f)) 
            circle.SetPosition(pos);
        if (ImGui::Button("Start Simulation"))
            simulate = true;
    }
    if (ImGui::Button("Reset Circle")) {
    	simulate = false;
        circle.SetPosition(glm::vec2(0.f));
        circle.SetVelocity(glm::vec2(0.f));
    }

    ImGui::End();
}
