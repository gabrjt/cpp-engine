//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_MOVEMENTSYSTEM_H
#define CPP_ENGINE_MOVEMENTSYSTEM_H

namespace Engine::Examples::Collision {
    class MovementSystem final : public Engine::System {
    private:
        std::shared_ptr<entt::registry> m_Registry;

    public:
        MovementSystem() = delete;

        explicit MovementSystem(const std::shared_ptr<entt::registry> &&registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_MOVEMENTSYSTEM_H
