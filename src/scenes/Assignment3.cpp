#include <glm/glm.hpp>
#include "Assignment3.h"
#include "objects/Impulse.h"
#include "imgui.h"

Assignment3::Assignment3() : selected(nullptr), dragStart(0.0f), dragging(false) {
    circles.emplace_back(glm::vec2(-2.f, 0.f), 0.5f, glm::vec2(0), 1.0f);
    circles.emplace_back(glm::vec2(0.f, 0.f), 0.5f, glm::vec2(0), 2.0f);
    circles.emplace_back(glm::vec2(2.f, 0.f), 0.5f, glm::vec2(0), 3.0f);
}

void Assignment3::Update(float dt) {
    if (Input::IsMouseClicked(ImGuiMouseButton_Left)) 
    {
        glm::vec2 mousePos = Input::GetMousePos();
        for (std::size_t i = 0; i < circles.size(); ++i) 
        {
            const glm::vec2& pos = circles[i].GetPosition();
            float r = circles[i].GetRadius();
            if (glm::distance(pos, mousePos) <= r) 
            {
                selected = &circles[i];
                dragStart = pos;
                dragging = true;
                break;
            }
        }
    }

    if (Input::IsMouseReleased(ImGuiMouseButton_Left) && dragging && selected) 
    {
        glm::vec2 impulse = Input::GetMousePos() - dragStart;
        selected->ApplyImpulse(impulse);
        selected = nullptr;
        dragging = false;
    }

    for (std::size_t i = 0; i < circles.size(); ++i) 
        circles[i].Update(dt);
    
}

void Assignment3::Draw() {

    Draw::Line(glm::vec2(-10, 0), glm::vec2(10, 0));
    for (std::size_t i = 0; i < circles.size(); ++i) 
        Draw::Circle(circles[i].GetPosition(), circles[i].GetRadius());

    if (dragging && selected != nullptr) 
    {
        glm::vec2 current = Input::GetMousePos();
        Draw::Line(dragStart, current);

        glm::vec2 impulse = current - dragStart;
        glm::vec2 velocity = Impulse::CalculateVelocity(impulse, selected->GetMass());
        std::vector<glm::vec2> trajectory = Impulse::PredictTrajectory(selected->GetPosition(), velocity, selected->GetMass(), selected->GetRadius(), 1.0f/60.0f, 30);

        for (std::size_t i = 0; i < trajectory.size(); ++i) 
            Draw::Circle(trajectory[i], 0.5f);
    }
}

void Assignment3::DrawGUI() {
    ImGui::Begin("Assignment 3");
    ImGui::Text("Click and drag a circle to apply an impulse.");

    for (std::size_t i = 0; i < circles.size(); ++i) 
    {
        ImGui::PushID(static_cast<int>(i));
        float mass = circles[i].GetMass();

        ImGui::Text("Circle %d", static_cast<int>(i + 1));
        if (ImGui::DragFloat("Mass", &mass, 0.1f, 0.1f, 100.0f)) 
            circles[i].SetMass(mass);

        ImGui::Separator();
        ImGui::PopID();
    }

    ImGui::End();
}
