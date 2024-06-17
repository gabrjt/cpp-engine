//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Input.h"
#include "MovementInput.h"
#include "PlayerRef.h"
#include "PlayerMovementInputSystem.h"

namespace Engine::Examples::Collision {
    void PlayerMovementInputSystem::Update() {
        static entt::registry &registry = Engine::Application::Get().GetRegistry();
        auto view = registry.view<const PlayerRef, MovementInput>();

        view.each([](const PlayerRef &playerRef, MovementInput &movementInput) {
            movementInput.Direction = registry.get<Input>(playerRef.Value).Joystick.Normalize();
        });
    }
}
