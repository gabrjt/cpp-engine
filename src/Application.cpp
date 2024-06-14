//
// Created by Gabriel on 12/06/2024.
//

#include "Application.h"

namespace Engine {
    Application::Application() : m_FrameRate(60), m_Window(nullptr) {
        SetTargetFPS(m_FrameRate);
    }

    Application &Application::Get() {
        static Application application;

        return application;
    }

    void Application::SetTargetFrameRate(int frameRate) {
        SetTargetFPS(m_FrameRate = frameRate);
    }

    int Application::GetTargetFrameRate() const {
        return m_FrameRate;
    }

    raylib::Window &Application::OpenWindow(const char *title, int width, int height) {
        static raylib::Window window(width, height, title);

        return *(m_Window = &window);
    }


}
