//
// Created by Gabriel on 17/06/2024.
//

#ifndef CPP_ENGINE_AIMOVEMENTINPUTSYSTEM_H
#define CPP_ENGINE_AIMOVEMENTINPUTSYSTEM_H

namespace Engine::Examples::Collision {
    class AIMovementInputSystem final : public Engine::System {
    public:
        void Update() override;
    };
}

#endif //CPP_ENGINE_AIMOVEMENTINPUTSYSTEM_H
