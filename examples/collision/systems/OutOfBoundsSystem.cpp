//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Circle.h"
#include "Position.h"
#include "OutOfBoundsSystem.h"

namespace Engine::Examples::Collision {
    void OutOfBoundsSystem::Initialize() {}

    void OutOfBoundsSystem::Update() {
        static Engine::Application &application = Engine::Application::Get();
        static entt::registry &registry = application.GetRegistry();
        std::shared_ptr<raylib::Window> window = application.GetWindow();
        const int width = window->GetWidth();
        const int height = window->GetHeight();
        auto view = registry.view<const Circle, Position>();

        view.each([&](const Circle &circle, Position &position) {
            position.Value.x = Clamp(position.Value.x, circle.Radius, width - circle.Radius);
            position.Value.y = Clamp(position.Value.y, circle.Radius, height - circle.Radius);
        });
    }
}
