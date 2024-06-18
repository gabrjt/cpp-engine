//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_PLAYERINPUTSYSTEM_H
#define CPP_ENGINE_PLAYERINPUTSYSTEM_H

namespace Engine::Examples::Collision {
    class PlayerInputSystem final : public Engine::System {
    private:
        std::shared_ptr<entt::registry> m_Registry;

    public:
        PlayerInputSystem() = delete;

        explicit PlayerInputSystem(const std::shared_ptr<entt::registry> &&registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_PLAYERINPUTSYSTEM_H
