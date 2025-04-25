#include "Assignment1.h"
#include "imgui.h"

Assignment1::Assignment1() : circle({0.f, 1.f}, 1.f),  simulate(false) {}

void Assignment1::OnEnable() {}

void Assignment1::OnDisable() {}

void Assignment1::Update(float deltaTime) 
{
    if (simulate) 
    	circle.Update(deltaTime);
}

void Assignment1::Draw() 
{
    Draw::Circle(circle.GetPosition(), circle.GetRadius());
	Draw::Line(glm::vec2(-5, 0), glm::vec2(5, 0));
}

void Assignment1::DrawGUI() 
{
    ImGui::Begin("Assignment 1");
    ImGui::Checkbox("Simulate", &simulate);

    if (!simulate) {
        glm::vec2 pos = circle.GetPosition();
        glm::vec2 vel = circle.GetVelocity();
        float r = circle.GetRadius();

        if (ImGui::DragFloat2("Position", &pos.x, 0.05f)) 
            circle.SetPosition(pos);

        if (ImGui::DragFloat2("Velocity", &vel.x, 0.05f)) 
            circle.SetVelocity(vel);

        ImGui::DragFloat("Radius", &r, 0.05f, 0.1f, 10.0f);
        circle = Circle(pos, r, vel); 
    }

    if (ImGui::Button("Reset"))
        circle = Circle({0.f, 1.f}, 1.f, {0.f, 0.f});


    ImGui::End();
}
