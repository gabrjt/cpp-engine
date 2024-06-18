//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_OUTOFBOUNDSSYSTEM_H
#define CPP_ENGINE_OUTOFBOUNDSSYSTEM_H

namespace Engine::Examples::Collision {
    class OutOfBoundsSystem final : public Engine::System {
    private:
        std::shared_ptr<raylib::Window> m_Window;
        std::shared_ptr<entt::registry> m_Registry;

    public:
        OutOfBoundsSystem() = delete;

        explicit OutOfBoundsSystem(const std::shared_ptr<raylib::Window> &&window,
                                   const std::shared_ptr<entt::registry> &&registry);

        void Update() override;
    };
}

#endif //CPP_ENGINE_OUTOFBOUNDSSYSTEM_H
