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
    SpawnCircleSystem::SpawnCircleSystem(const int count,
                                         const std::shared_ptr<raylib::Window> window,
                                         const std::shared_ptr<entt::registry> registry)
            : m_Count(count) {
        const int width{window->GetWidth()};
        const int height{window->GetHeight()};

        for (int i = 0; i < m_Count; ++i) {
            const Speed         speed(GetRandomValue(64, 256));
            const MovementInput movementInput(Engine::RandomVector2(-1, 1, -1, 1).Normalize());
            const Circle        circle(GetRandomValue(5, 20), RED);
            const Position      position(Engine::RandomVector2(circle.Radius,
                                                               width - circle.Radius,
                                                               circle.Radius,
                                                               height - circle.Radius));

            Circle::CreateAI(*registry, circle, position, speed, movementInput);
        }
    }

    void SpawnCircleSystem::Update() {}
}
