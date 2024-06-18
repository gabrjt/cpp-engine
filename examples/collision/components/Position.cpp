//
// Created by Gabriel on 16/06/2024.
//
#include <cppengine.h>
#include "Position.h"

namespace Engine::Examples::Collision {
    Position::Position() : Value(raylib::Vector2::Zero()) {}

    Position::Position(const raylib::Vector2 value) : Value(value) {}
}
