#include <cppengine.h>
#include "Systems.h"

using namespace Engine::Examples::Collision;

int main() {
    Engine::Application &application = Engine::Application::Get();

    // By creating systems as lvalues, outside the RegisterSystems function call, it's possible to ensure that constructors will be called in order.
    // Function params order is undefined behaviour.
    WindowSystem windowSystem("Collisions", 1280, 720, BLACK);
    CreatePlayerSystem createPlayerSystem(application.GetWindow(), application.GetRegistry());
    PlayerInputSystem playerInputSystem(application.GetRegistry());
    LogPlayerInputSystem logPlayerInputSystem(application.GetRegistry());
    PlayerMovementInputSystem playerMovementInputSystem(application.GetRegistry());
    AIMovementInputSystem aiMovementInputSystem(application.GetWindow(), application.GetRegistry());
    SpawnCircleSystem spawnCircleSystem(16, application.GetWindow(), application.GetRegistry());
    MovementSystem movementSystem(application.GetRegistry());
    OutOfBoundsSystem outOfBoundsSystem(application.GetWindow(), application.GetRegistry());
    DrawCircleSystem drawCircleSystem(application.GetRegistry());

    application.RegisterSystems(windowSystem, createPlayerSystem, playerInputSystem, logPlayerInputSystem,
                                playerMovementInputSystem, aiMovementInputSystem, spawnCircleSystem, movementSystem,
                                outOfBoundsSystem, drawCircleSystem);

    while (!application.GetWindow()->ShouldClose()) {
        BeginDrawing();
        application.UpdateSystems();
        EndDrawing();
    }

    return 0;
}
