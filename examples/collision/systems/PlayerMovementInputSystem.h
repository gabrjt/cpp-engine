//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_PLAYERMOVEMENTINPUTSYSTEM_H
#define CPP_ENGINE_PLAYERMOVEMENTINPUTSYSTEM_H

namespace Engine::Examples::Collision {
    class PlayerMovementInputSystem final : public Engine::System {
    private:
        std::shared_ptr<entt::registry> m_Registry;

    public:
        PlayerMovementInputSystem() = delete;

        explicit PlayerMovementInputSystem(const std::shared_ptr<entt::registry> &&registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_PLAYERMOVEMENTINPUTSYSTEM_H
