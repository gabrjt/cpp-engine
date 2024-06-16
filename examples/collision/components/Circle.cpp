//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "MovementInput.h"
#include "PlayerRef.h"
#include "Position.h"
#include "Speed.h"
#include "Circle.h"

namespace Engine::Examples::Collision {
    entt::entity Circle::Create(entt::registry &registry, const Circle &circle, const Position &position) {
        const entt::entity entity = registry.create();
        registry.emplace<Circle>(entity, circle);
        registry.emplace<Position>(entity, position);

        return entity;
    }

    entt::entity Circle::CreatePlayer(entt::registry &registry, const PlayerRef &playerRef, const Circle &circle,
                                      const Position &position, const Speed &speed) {
        const entt::entity entity = Create(registry, circle, position);
        registry.emplace<Speed>(entity, speed);
        registry.emplace<MovementInput>(entity);
        registry.emplace<PlayerRef>(entity, playerRef);

        return entity;
    }
}
