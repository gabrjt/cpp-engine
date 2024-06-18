//
// Created by Gabriel on 16/06/2024.
//
#include <cppengine.h>
#include "PlayerRef.h"

namespace Engine::Examples::Collision {
    PlayerRef::PlayerRef(const entt::entity playerEntity)
            : Value(playerEntity) {}
}
