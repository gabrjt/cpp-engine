//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Circle.h"
#include "Position.h"
#include "OutOfBoundsSystem.h"

namespace Engine::Examples::Collision {
    OutOfBoundsSystem::OutOfBoundsSystem(const std::shared_ptr<raylib::Window> &&window,
                                         const std::shared_ptr<entt::registry> &&registry) : m_Window(window),
                                                                                       m_Registry(registry) {}

    void OutOfBoundsSystem::Update() {
        const int width = m_Window->GetWidth();
        const int height = m_Window->GetHeight();
        auto view = m_Registry->view<const Circle, Position>();

        view.each([&](const Circle &circle, Position &position) {
            position.Value.x = Clamp(position.Value.x, circle.Radius, width - circle.Radius);
            position.Value.y = Clamp(position.Value.y, circle.Radius, height - circle.Radius);
        });
    }


}
