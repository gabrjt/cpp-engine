//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_POSITION_H
#define CPP_ENGINE_POSITION_H

namespace Engine::Examples::Collision {
    struct Position {
        raylib::Vector2 Value;

        Position();

        explicit Position(raylib::Vector2 value);
    };
}

#endif //CPP_ENGINE_POSITION_H
