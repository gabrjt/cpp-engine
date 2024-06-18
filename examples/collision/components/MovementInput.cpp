//
// Created by Gabriel on 16/06/2024.
//
#include <cppengine.h>
#include "MovementInput.h"

namespace Engine::Examples::Collision {
    MovementInput::MovementInput()
            : Direction(raylib::Vector2::Zero()) {}

    MovementInput::MovementInput(const raylib::Vector2 direction)
            : Direction(direction) {}
}
