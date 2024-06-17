#include <cppengine.h>
#include "Systems.h"

using namespace Engine::Examples::Collision;

int main() {
    Engine::Application &application = Engine::Application::Get();
    application.RegisterSystems(WindowSystem("Collisions", 1280, 720, BLACK),
                                CreatePlayerSystem(), PlayerInputSystem(), LogPlayerInputSystem(),
                                MovementInputSystem(), SpawnCircleSystem(3), MovementSystem(), OutOfBoundsSystem(),
                                DrawCircleSystem());

    std::shared_ptr<raylib::Window> window = application.GetWindow();

    while (!window->ShouldClose()) {
        BeginDrawing();
        application.UpdateSystems();
        EndDrawing();
    }

    return 0;
}
