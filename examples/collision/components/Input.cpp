//
// Created by Gabriel on 16/06/2024.
//
#include <cppengine.h>
#include "Input.h"

namespace Engine::Examples::Collision {
    Input::Input()
            : Joystick(raylib::Vector2::Zero()) {}

    Input::Input(const raylib::Vector2 joystick)
            : Joystick(joystick) {}
}
