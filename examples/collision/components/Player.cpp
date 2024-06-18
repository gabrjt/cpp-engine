//
// Created by Gabriel on 16/06/2024.
//
#include <cppengine.h>
#include "Input.h"
#include "Player.h"

namespace Engine::Examples::Collision {
    entt::entity Engine::Examples::Collision::Player::Create(entt::registry &registry) {
        const entt::entity entity{registry.create()};
        registry.emplace<Player>(entity);
        registry.emplace<Input>(entity);

        return entity;
    }
}
