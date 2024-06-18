//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_DRAWCIRCLESYSTEM_H
#define CPP_ENGINE_DRAWCIRCLESYSTEM_H

namespace Engine::Examples::Collision {
    class DrawCircleSystem final : public Engine::System {
    private:
        std::shared_ptr<entt::registry> m_Registry;

    public:
        DrawCircleSystem() = delete;

        explicit DrawCircleSystem(const std::shared_ptr<entt::registry> &&registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_DRAWCIRCLESYSTEM_H
