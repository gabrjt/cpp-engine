//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_MOVEMENTSYSTEM_H
#define CPP_ENGINE_MOVEMENTSYSTEM_H

namespace Engine::Examples::Collision {
    class MovementSystem final : public Engine::System {
    public:
        void Initialize() override;

        void Update() override;
    };
}

#endif //CPP_ENGINE_MOVEMENTSYSTEM_H
