//
// Created by Gabriel on 17/06/2024.
//

#ifndef CPP_ENGINE_AIMOVEMENTINPUTSYSTEM_H
#define CPP_ENGINE_AIMOVEMENTINPUTSYSTEM_H

namespace Engine::Examples::Collision {
    class AIMovementInputSystem final : public Engine::System {
    private:
        std::shared_ptr<raylib::Window> m_Window;
        std::shared_ptr<entt::registry> m_Registry;

    public:
        AIMovementInputSystem() = delete;

        explicit AIMovementInputSystem(const std::shared_ptr<raylib::Window> &&window,
                                       const std::shared_ptr<entt::registry> &&registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_AIMOVEMENTINPUTSYSTEM_H
