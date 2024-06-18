//
// Created by Gabriel on 12/06/2024.
//

#include <raylib-cpp.hpp>
#include <entt/entt.hpp>
#include "System.h"
#include "Application.h"

namespace Engine {
    Application::Application()
            : m_FrameRate(60)
            , m_Window(nullptr)
            , m_Registry(std::make_shared<entt::registry>())
            , m_Systems() {
        SetTargetFPS(m_FrameRate);
        SetRandomSeed(GetTime());
    }

    Application::~Application() {
        m_Window = nullptr;
        m_Systems.clear();
    }

    Application &Application::Get() {
        static Application application;

        return application;
    }

    void Application::SetTargetFrameRate(const int frameRate) {
        SetTargetFPS(m_FrameRate = frameRate);
    }

    int Application::GetTargetFrameRate() const {
        return m_FrameRate;
    }

    std::shared_ptr<raylib::Window> Application::OpenWindow(const char *title, const int width, const int height) {
        static raylib::Window window(width, height, title);

        if (!m_Window) {
            m_Window = std::make_shared<raylib::Window>(window);
        }

        return m_Window;
    }

    std::shared_ptr<raylib::Window> Application::GetWindow() {
        return m_Window;
    }

    std::size_t Application::GetSystemsCount() const {
        return m_Systems.size();
    }

    void Application::UpdateSystems() {
        for (const std::unique_ptr<System> &system : m_Systems) {
            system->Update();
        }
    }

    std::shared_ptr<entt::registry> Application::GetRegistry() {
        return m_Registry;
    }

    std::vector<std::unique_ptr<System>> &Application::GetSystems() {
        return m_Systems;
    }
}
