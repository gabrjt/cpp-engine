//
// Created by Gabriel on 12/06/2024.
//

#ifndef CPP_ENGINE_APPLICATION_H
#define CPP_ENGINE_APPLICATION_H

namespace Engine {
    class System;

    class Application final {
    private:
        int m_FrameRate;
        std::shared_ptr<raylib::Window> m_Window;
        std::shared_ptr<entt::registry> m_Registry;
        std::vector<std::unique_ptr<System>> m_Systems;

    public:
        Application();

        ~Application();

        Application(Application &) = delete;

        static Application &Get();

        void SetTargetFrameRate(int frameRate);

        int GetTargetFrameRate() const;

        std::shared_ptr<raylib::Window> OpenWindow(const char *title, int width, int height);

        std::shared_ptr<raylib::Window> GetWindow();

        template<typename ... TSystems>
        void RegisterSystems(const TSystems &... systems) {
            m_Systems.reserve(m_Systems.size() + sizeof...(systems));

            ([&] {
                m_Systems.emplace_back(std::make_unique<TSystems>(systems));
            }(), ...);
        }

        std::size_t GetSystemsCount() const;

        std::shared_ptr<entt::registry> GetRegistry();

        void UpdateSystems();

        std::vector<std::unique_ptr<System>> &GetSystems();
    };
}

#endif //CPP_ENGINE_APPLICATION_H
