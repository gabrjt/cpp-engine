//
// Created by Gabriel on 16/06/2024.
//

#include <iostream>
#include <cppengine.h>
#include "Input.h"
#include "Player.h"
#include "LogPlayerInputSystem.h"

namespace Engine::Examples::Collision {
    void LogPlayerInputSystem::Initialize() {}

    void LogPlayerInputSystem::Update() {
        static entt::registry &registry = Engine::Application::Get().GetRegistry();
        auto view = registry.view<const Player, const Input>();

        view.each([](const Input &input) {
            std::cout << "Player Input: " << input.Joystick.ToString() << std::endl;
        });
    }
}
