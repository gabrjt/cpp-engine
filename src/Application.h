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
        std::vector<System> m_Systems;

    public:
        Application();

        ~Application();

        Application(Application &) = delete;

        static Application &Get();

        void SetTargetFrameRate(int frameRate);

        int GetTargetFrameRate() const;

        std::shared_ptr<raylib::Window> &OpenWindow(const char *title, int width, int height);

        std::shared_ptr<raylib::Window> &GetWindow();

        template<std::size_t TSize>
        void RegisterSystems(const std::array<System, TSize> &systems) {
            m_Systems.reserve(m_Systems.size() + TSize);

            for (const System &system: systems) {
                m_Systems.emplace_back(system);
            }
        }

        std::size_t GetSystemsCount() const;

        void UpdateSystems();
    };
}

#endif //CPP_ENGINE_APPLICATION_H
