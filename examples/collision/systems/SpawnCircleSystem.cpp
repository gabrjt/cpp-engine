//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Circle.h"
#include "MovementInput.h"
#include "Position.h"
#include "Speed.h"
#include "SpawnCircleSystem.h"

namespace Engine::Examples::Collision {
    SpawnCircleSystem::SpawnCircleSystem(const int count) : m_Count(count) {}

    void SpawnCircleSystem::Initialize() {
        Engine::Application &application = Engine::Application::Get();
        std::shared_ptr<raylib::Window> window = application.GetWindow();
        entt::registry &registry = application.GetRegistry();
        const int width = window->GetWidth();
        const int height = window->GetHeight();

        for (int i = 0; i < m_Count; ++i) {
            const Speed speed(GetRandomValue(64, 256));
            const MovementInput movementInput{
                    raylib::Vector2(GetRandomValue(-1, 1), GetRandomValue(-1, 1)).Normalize()};
            const Circle circle(GetRandomValue(5, 20), RED);
            const Position position{raylib::Vector2(GetRandomValue(circle.Radius, width - circle.Radius),
                                                    GetRandomValue(circle.Radius, height - circle.Radius))};

            Circle::CreateAI(registry, circle, position, speed, movementInput);
        }
    }

    void SpawnCircleSystem::Update() {}
}
