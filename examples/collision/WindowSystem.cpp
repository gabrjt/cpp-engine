//
// Created by Gabriel on 16/06/2024.
//

#include <cstring>
#include <cppengine.h>
#include "WindowSystem.h"

namespace Engine::Examples::Collision {
    WindowSystem::WindowSystem() : m_Window(Engine::Application::Get().OpenWindow("CPP ENGINE", 1920, 1080)),
                                   m_ClearBackgroundColor(BLACK) {}

    WindowSystem::WindowSystem(const char *title, int width, int height, raylib::Color clearBackgroundColor) : m_Window(
            Engine::Application::Get().OpenWindow(title, width, height)), m_ClearBackgroundColor(clearBackgroundColor) {
    }

    void WindowSystem::Update() {
        static const char *text = "WELCOME TO CPP ENGINE";
        static const int length = strlen(text);

        m_Window->ClearBackground(m_ClearBackgroundColor);

        DrawText(text, (m_Window->GetWidth() / 2) - (length * 60 / 3), m_Window->GetHeight() / 2, 60, RAYWHITE);
    }
}
