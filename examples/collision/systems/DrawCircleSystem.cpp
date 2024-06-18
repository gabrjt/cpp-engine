//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Circle.h"
#include "Position.h"
#include "DrawCircleSystem.h"

namespace Engine::Examples::Collision {
    DrawCircleSystem::DrawCircleSystem(const std::shared_ptr<entt::registry> &&registry) : m_Registry(registry) {}

    void DrawCircleSystem::Update() {
        auto view = m_Registry->view<const Circle, const Position>();

        view.each([](const Circle &circle, const Position &position) {
            DrawCircle(position.Value.x, position.Value.y, circle.Radius, circle.Color);
        });
    }
}
