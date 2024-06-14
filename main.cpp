#include <cstring>
#include "cppengine.h"

int main() {
    Engine::Application &application = Engine::Application::Get();
    raylib::Window &window = application.OpenWindow("CPP ENGINE", 1920, 1080);
    const char *text = "WELCOME TO CPP ENGINE";
    int length = strlen(text);

    while (!window.ShouldClose()) {
        BeginDrawing();

        window.ClearBackground(BLACK);

        DrawText(text, (window.GetWidth() / 2) - (length * 60 / 3), window.GetHeight() / 2, 60, RAYWHITE);

        EndDrawing();
    }

    return 0;
}
