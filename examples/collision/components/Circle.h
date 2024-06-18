//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_CIRCLE_H
#define CPP_ENGINE_CIRCLE_H

namespace Engine::Examples::Collision {
    struct MovementInput;
    struct Position;
    struct PlayerRef;
    struct Speed;

    struct Circle {
        float         Radius;
        raylib::Color Color;

        Circle() = delete;

        explicit Circle(float radius, raylib::Color color);

        static entt::entity Create(entt::registry &registry, const Circle &circle, const Position &position);

        static entt::entity CreatePlayer(entt::registry &registry,
                                         const PlayerRef &playerRef,
                                         const Circle &circle,
                                         const Position &position,
                                         const Speed &speed);

        static entt::entity CreateAI(entt::registry &registry,
                                     const Circle &circle,
                                     const Position &position,
                                     const Speed &speed,
                                     const MovementInput &movementInput);
    };
}

#endif //CPP_ENGINE_CIRCLE_H
