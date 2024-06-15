#include <cstring>
#include "cppengine.h"

class WindowSystem : public Engine::System {
private:
    std::shared_ptr<raylib::Window> m_Window;
public:
    WindowSystem() : m_Window(Engine::Application::Get().OpenWindow("CPP ENGINE", 1920, 1080)) {}

    void Update() override {
        static const char *text = "WELCOME TO CPP ENGINE";
        static const int length = strlen(text);

        BeginDrawing();

        m_Window->ClearBackground(BLACK);

        DrawText(text, (m_Window->GetWidth() / 2) - (length * 60 / 3), m_Window->GetHeight() / 2, 60, RAYWHITE);

        EndDrawing();
    }
};

int main() {
    Engine::Application &application = Engine::Application::Get();
    application.RegisterSystems<WindowSystem>();

    std::shared_ptr<raylib::Window> window = application.GetWindow();

    while (!window->ShouldClose()) {
        application.UpdateSystems();
    }

    return 0;
}
