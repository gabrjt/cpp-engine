//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_LOGPLAYERINPUTSYSTEM_H
#define CPP_ENGINE_LOGPLAYERINPUTSYSTEM_H

namespace Engine::Examples::Collision {
    class LogPlayerInputSystem final : public Engine::System {
    private:
        std::shared_ptr<entt::registry> m_Registry;

    public:
        LogPlayerInputSystem() = delete;

        explicit LogPlayerInputSystem(const std::shared_ptr<entt::registry> &&registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_LOGPLAYERINPUTSYSTEM_H
