#include "Assignment2.h"
#include "imgui.h"

Assignment2::Assignment2() : circle({0.f, 1.f}, 1.f), simulate(false) {}

void Assignment2::OnEnable() {
    ForceField field(glm::vec2(0.f, 0.f), 2.3f, glm::vec2(0.f, 12.f));
    forceFields.push_back(field); 
}

void Assignment2::OnDisable() {}

void Assignment2::Update(float deltaTime) {
    if (simulate) 
    {
        for (size_t i = 0; i < forceFields.size(); ++i) 
        {
            forceFields[i].IsInside(circle.GetPosition());
		    circle.ApplyForceField(&forceFields[i]);
		}
        circle.Update(deltaTime);
    }
}

void Assignment2::Draw() {

    for (size_t i = 0; i < forceFields.size(); ++i)
		Draw::Circle(forceFields[i].GetPosition(), forceFields[i].GetRadius());
	
    Draw::Circle(circle.GetPosition(), circle.GetRadius());
    Draw::Line(glm::vec2(-5, 0), glm::vec2(5, 0));
}

void Assignment2::DrawGUI() {
    ImGui::Begin("Assignment 2");
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

        for (size_t i = 0; i < forceFields.size(); ++i) {
            ImGui::Separator();
            ImGui::Text("Force Field", i + 1);

            glm::vec2 fieldPos = forceFields[i].GetPosition();
            float fieldRadius = forceFields[i].GetRadius();
            glm::vec2 fieldForce = forceFields[i].GetForce();

            if (ImGui::DragFloat2("Force Field Position", &fieldPos.x, 0.05f))
                forceFields[i].SetPosition(fieldPos);

            if (ImGui::DragFloat("Force Field Radius", &fieldRadius, 0.05f,
                                 0.1f, 10.0f))
                forceFields[i].SetRadius(fieldRadius);

            if (ImGui::DragFloat2("Force Applied", &fieldForce.x, 0.05f))
                forceFields[i].SetForce(fieldForce);
        }
    }

    if (ImGui::Button("Reset")) {
        circle = Circle({0.f, 1.f}, 1.f, {0.f, 0.f});
        forceFields.clear();
        ForceField field(glm::vec2(0.f, 0.f), 3.f, glm::vec2(0.f, 0.f));
        forceFields.push_back(field); 
    }   

    ImGui::End();
}
