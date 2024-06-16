//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_WINDOWSYSTEM_H
#define CPP_ENGINE_WINDOWSYSTEM_H

namespace Engine::Examples::Collision {
    class WindowSystem final : public Engine::System {
    private:
        std::shared_ptr<raylib::Window> m_Window;
        raylib::Color m_ClearBackgroundColor;
    public:
        WindowSystem();

        WindowSystem(const char *title, int width, int height, raylib::Color clearBackgroundColor);

        void Update() override;
    };
}

#endif //CPP_ENGINE_WINDOWSYSTEM_H
