//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_PLAYERREF_H
#define CPP_ENGINE_PLAYERREF_H

namespace Engine::Examples::Collision {
    struct PlayerRef {
        entt::entity Value;

        PlayerRef() = delete;

        explicit PlayerRef(entt::entity playerEntity);
    };
}

#endif //CPP_ENGINE_PLAYERREF_H
