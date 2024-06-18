//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "MovementInput.h"
#include "Position.h"
#include "Speed.h"
#include "MovementSystem.h"

namespace Engine::Examples::Collision {
    MovementSystem::MovementSystem(const std::shared_ptr<entt::registry> &&registry)
            : m_Registry(registry) {}

    void MovementSystem::Update() {
        auto        view{m_Registry->view<const MovementInput, const Speed, Position>()};
        const float deltaTime{GetFrameTime()};

        view.each([&](const MovementInput &movementInput, const Speed &speed, Position &position) {
            position.Value += movementInput.Direction * speed.Value * deltaTime;
        });
    }
}
