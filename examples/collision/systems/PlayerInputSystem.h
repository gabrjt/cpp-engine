//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_PLAYERINPUTSYSTEM_H
#define CPP_ENGINE_PLAYERINPUTSYSTEM_H

namespace Engine::Examples::Collision {
    class PlayerInputSystem final : public Engine::System {
    public:
        void Initialize() override;

        void Update() override;
    };
}

#endif //CPP_ENGINE_PLAYERINPUTSYSTEM_H
