//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Input.h"
#include "MovementInput.h"
#include "PlayerRef.h"
#include "PlayerMovementInputSystem.h"

namespace Engine::Examples::Collision {
    PlayerMovementInputSystem::PlayerMovementInputSystem(const std::shared_ptr<entt::registry> &&registry) : m_Registry(
            registry) {}

    void PlayerMovementInputSystem::Update() {
        auto view = m_Registry->view<const PlayerRef, MovementInput>();

        view.each([&](const PlayerRef &playerRef, MovementInput &movementInput) {
            movementInput.Direction = m_Registry->get<Input>(playerRef.Value).Joystick.Normalize();
        });
    }


}
