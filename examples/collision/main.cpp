#include <cppengine.h>
#include "Systems.h"

using namespace Engine::Examples::Collision;

int main() {
    Engine::Application &application = Engine::Application::Get();

    application.RegisterSystems(
            WindowSystem("Collisions", 1280, 720, BLACK),
            CreatePlayerSystem(application.GetWindow(), application.GetRegistry()),
            PlayerInputSystem(application.GetRegistry()),
            LogPlayerInputSystem(application.GetRegistry()),
            PlayerMovementInputSystem(application.GetRegistry()),
            AIMovementInputSystem(application.GetWindow(), application.GetRegistry()),
            SpawnCircleSystem(16, application.GetWindow(), application.GetRegistry()),
            MovementSystem(application.GetRegistry()),
            OutOfBoundsSystem(application.GetWindow(), application.GetRegistry()),
            DrawCircleSystem(application.GetRegistry()));

    while (!application.GetWindow()->ShouldClose()) {
        BeginDrawing();
        application.UpdateSystems();
        EndDrawing();
    }

    return 0;
}
