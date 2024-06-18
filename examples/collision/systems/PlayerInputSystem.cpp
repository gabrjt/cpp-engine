//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Input.h"
#include "Player.h"
#include "PlayerInputSystem.h"

namespace Engine::Examples::Collision {
    PlayerInputSystem::PlayerInputSystem(const std::shared_ptr<entt::registry> &&registry) : m_Registry(registry) {}

    void PlayerInputSystem::Update() {
        auto view = m_Registry->view<const Player, Input>();

        view.each([](Input &input) {
            float x = 0, y = 0;

            if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
                x -= 1;
            }

            if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
                x += 1;
            }

            if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
                y -= 1;
            }

            if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
                y += 1;
            }

            input.Joystick = raylib::Vector2(x, y);
        });
    }
}
