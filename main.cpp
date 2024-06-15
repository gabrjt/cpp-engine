#include <cstring>
#include "cppengine.h"

class MenuSystem : public Engine::System {
public:
    void Update() override {
        static Engine::Application &application = Engine::Application::Get();
        static const char *text = "WELCOME TO CPP ENGINE";
        static const int length = strlen(text);
        std::shared_ptr<raylib::Window> window = application.GetWindow();

        BeginDrawing();

        window->ClearBackground(BLACK);

        DrawText(text, (window->GetWidth() / 2) - (length * 60 / 3), window->GetHeight() / 2, 60, RAYWHITE);

        EndDrawing();
    }
};

int main() {
    Engine::Application &application = Engine::Application::Get();

    std::array<std::unique_ptr<Engine::System>, 1> systems{std::make_unique<MenuSystem>()};
    application.RegisterSystems(systems);

    std::shared_ptr<raylib::Window> window = application.OpenWindow("CPP ENGINE", 1920, 1080);

    while (!window->ShouldClose()) {
        application.UpdateSystems();
    }

    return 0;
}
