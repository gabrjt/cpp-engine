//
// Created by Gabriel on 12/06/2024.
//

#include "Application.h"

namespace Engine {
    Application::Application() : m_FrameRate(60), m_Window(nullptr), m_Registry(), m_Systems() {
        SetTargetFPS(m_FrameRate);
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

    raylib::Window &Application::OpenWindow(const char *title, const int width, const int height) {
        static raylib::Window window(width, height, title);

        return *(m_Window = &window);
    }

    raylib::Window &Application::GetWindow() const {
        return *m_Window;
    }

    std::size_t Application::GetSystemsCount() const {
        return m_Systems.size();
    }
}
