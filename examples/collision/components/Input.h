//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_INPUT_H
#define CPP_ENGINE_INPUT_H

namespace Engine::Examples::Collision {
    struct Input {
        raylib::Vector2 Joystick;

        Input();

        explicit Input(raylib::Vector2 joystick);
    };
}

#endif //CPP_ENGINE_INPUT_H
