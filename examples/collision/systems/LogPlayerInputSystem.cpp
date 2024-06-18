//
// Created by Gabriel on 16/06/2024.
//

#include <iostream>
#include <cppengine.h>
#include "Input.h"
#include "Player.h"
#include "LogPlayerInputSystem.h"

namespace Engine::Examples::Collision {
    LogPlayerInputSystem::LogPlayerInputSystem(const std::shared_ptr<entt::registry> &&registry) : m_Registry(registry) {}

    void LogPlayerInputSystem::Update() {
        auto view = m_Registry->view<const Player, const Input>();

        view.each([](const Input &input) {
            std::cout << "Player Input: " << input.Joystick.ToString() << std::endl;
        });
    }
}
