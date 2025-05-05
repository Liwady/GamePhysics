#include "Assignment5.h"
#include <glm/glm.hpp>
#include "imgui.h"


Assignment5::Assignment5() : cBall(glm::vec2(0.f), 0.3f, glm::vec2(0.f), 1.0f), dragging(false), dragStart(0.f), table(-5.f, 5.f, -3.f, 3.f), dragField(glm::vec2(0.0f), 100.0f, glm::vec2(0.f)) {}

void Assignment5::OnEnable() {
    cBall.SetUseGravity(false); // Disable gravity for the ball
    dragField.SetDragCoefficient(0.4f);
}

void Assignment5::Update(float deltaTime) {

    if (Input::IsMouseClicked(ImGuiMouseButton_Left)) 
    {
        glm::vec2 mousePos = Input::GetMousePos();
        if (glm::distance(mousePos, cBall.GetPosition()) <= cBall.GetRadius()) 
        {
            dragging = true;
            dragStart = cBall.GetPosition();
        }
    }

    if (Input::IsMouseReleased(ImGuiMouseButton_Left) && dragging) 
    {
        glm::vec2 impulse = dragStart - Input::GetMousePos(); // reverse direction
        cBall.ApplyImpulse(impulse);
        dragging = false;
    }

    cBall.Update(deltaTime);
    table.ResolveCollision(cBall);
    glm::vec2 drag = dragField.ComputeForce(cBall.GetPosition(), cBall.GetVelocity());
    cBall.ApplyForce(drag);
}

void Assignment5::Draw() {
    //pool table
    Draw::Line(glm::vec2(table.GetLeft(), table.GetTop()), glm::vec2(table.GetRight(), table.GetTop()));
    Draw::Line(glm::vec2(table.GetRight(), table.GetTop()), glm::vec2(table.GetRight(), table.GetBottom()));
    Draw::Line(glm::vec2(table.GetRight(), table.GetBottom()), glm::vec2(table.GetLeft(), table.GetBottom()));
    Draw::Line(glm::vec2(table.GetLeft(), table.GetBottom()), glm::vec2(table.GetLeft(), table.GetTop()));

    //ball
    Draw::Circle(cBall.GetPosition(), cBall.GetRadius());

    //impulse line
    if (dragging) 
        Draw::Line(dragStart, Input::GetMousePos());
}

void Assignment5::DrawGUI() {
    ImGui::Begin("Assignment 5 - Pool");
    ImGui::Text("Click and drag on the ball to apply an impulse.");
    ImGui::End();
}
