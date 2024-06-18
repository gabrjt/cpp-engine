//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_MOVEMENTINPUT_H
#define CPP_ENGINE_MOVEMENTINPUT_H

namespace Engine::Examples::Collision {
    struct MovementInput {
        raylib::Vector2 Direction;

        MovementInput();

        explicit MovementInput(raylib::Vector2 direction);
    };
}

#endif //CPP_ENGINE_MOVEMENTINPUT_H
