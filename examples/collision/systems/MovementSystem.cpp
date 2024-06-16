//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "MovementInput.h"
#include "Position.h"
#include "Speed.h"
#include "MovementSystem.h"

namespace Engine::Examples::Collision {
    void MovementSystem::Update() {
        static entt::registry &registry = Engine::Application::Get().GetRegistry();
        auto view = registry.view<const MovementInput, const Speed, Position>();
        const float deltaTime = GetFrameTime();

        view.each([&](const MovementInput &movementInput, const Speed &speed, Position &position) {
            position.Value += movementInput.Direction * speed.Value * deltaTime;
        });
    }
}
