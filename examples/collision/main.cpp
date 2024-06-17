#include <cppengine.h>
#include "Systems.h"

using namespace Engine::Examples::Collision;

int main() {
    Engine::Application &application = Engine::Application::Get();

    // Constructing systems in the function call does not guarantee order. Maybe it's better to just pass an array after all...
    WindowSystem windowSystem("Collisions", 1280, 720, BLACK);

    application.RegisterSystems(std::move(windowSystem), CreatePlayerSystem(), PlayerInputSystem(),
                                LogPlayerInputSystem(), PlayerMovementInputSystem(), AIMovementInputSystem(),
                                SpawnCircleSystem(16), MovementSystem(), OutOfBoundsSystem(), DrawCircleSystem());

    std::shared_ptr<raylib::Window> window = application.GetWindow();

    while (!window->ShouldClose()) {
        BeginDrawing();
        application.UpdateSystems();
        EndDrawing();
    }

    return 0;
}
