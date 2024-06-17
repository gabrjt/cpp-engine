//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Circle.h"
#include "Position.h"
#include "DrawCircleSystem.h"

namespace Engine::Examples::Collision {
    void DrawCircleSystem::Initialize() {}

    void DrawCircleSystem::Update() {
        static entt::registry &registry = Engine::Application::Get().GetRegistry();
        auto view = registry.view<const Circle, const Position>();

        view.each([](const Circle &circle, const Position &position) {
            DrawCircle(position.Value.x, position.Value.y, circle.Radius, circle.Color);
        });
    }
}
