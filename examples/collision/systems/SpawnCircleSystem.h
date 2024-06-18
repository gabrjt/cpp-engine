//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_SPAWNCIRCLESYSTEM_H
#define CPP_ENGINE_SPAWNCIRCLESYSTEM_H

namespace Engine::Examples::Collision {
    class SpawnCircleSystem final : public Engine::System {
    private:
        int m_Count;

    public:
        SpawnCircleSystem() = delete;

        explicit SpawnCircleSystem(int count, std::shared_ptr<raylib::Window> window,
                                   std::shared_ptr<entt::registry> registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_SPAWNCIRCLESYSTEM_H
