//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_LOGPLAYERINPUTSYSTEM_H
#define CPP_ENGINE_LOGPLAYERINPUTSYSTEM_H

namespace Engine::Examples::Collision {
    class LogPlayerInputSystem final : public Engine::System {
    public:
        void Initialize() override;

        void Update() override;
    };
}

#endif //CPP_ENGINE_LOGPLAYERINPUTSYSTEM_H
