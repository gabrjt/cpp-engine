//
// Created by Gabriel on 12/06/2024.
//

#ifndef CPP_ENGINE_APPLICATION_H
#define CPP_ENGINE_APPLICATION_H

#include <raylib-cpp.hpp>
#include <entt/entt.hpp>
#include "System.h"

namespace Engine {
    class Application final {
    private:
        int m_FrameRate;
        std::shared_ptr<raylib::Window> m_Window;
        entt::registry m_Registry;
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

        template<std::size_t TSize>
        void RegisterSystems(std::array<std::unique_ptr<System>, TSize> &systems) {
            m_Systems.reserve(m_Systems.size() + TSize);

            for (std::unique_ptr<System> &system: systems) {
                m_Systems.emplace_back(std::move(system));
            }
        }

        std::size_t GetSystemsCount() const;

        void UpdateSystems();
    };
}

#endif //CPP_ENGINE_APPLICATION_H
