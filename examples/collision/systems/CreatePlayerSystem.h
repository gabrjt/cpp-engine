//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_CREATEPLAYERSYSTEM_H
#define CPP_ENGINE_CREATEPLAYERSYSTEM_H

namespace Engine::Examples::Collision {
    class CreatePlayerSystem final : public Engine::System {
    public:
        CreatePlayerSystem() = delete;

        explicit CreatePlayerSystem(std::shared_ptr<raylib::Window> window, std::shared_ptr<entt::registry> registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_CREATEPLAYERSYSTEM_H
