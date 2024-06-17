//
// Created by Gabriel on 17/06/2024.
//

#include <cppengine.h>
#include "Circle.h"
#include "MovementInput.h"
#include "PlayerRef.h"
#include "Position.h"
#include "AIMovementInputSystem.h"

namespace Engine::Examples::Collision {
    void AIMovementInputSystem::Update() {
        static Engine::Application &application = Engine::Application::Get();
        static entt::registry &registry = application.GetRegistry();
        std::shared_ptr<raylib::Window> window = application.GetWindow();
        const int width = window->GetWidth();
        const int height = window->GetHeight();
        const Rectangle rectangleLeft(0, 0, 1, height);
        const Rectangle rectangleRight(width, 0, 1, height);
        const Rectangle rectangleTop(0, 0, width, 1);
        const Rectangle rectangleBottom(0, height, width, 1);
        auto view = registry.view<const Circle, const Position, MovementInput>(entt::exclude<PlayerRef>);

        view.each([&](const Circle &circle, const Position &position, MovementInput &movementInput) {
            if (!CheckCollisionCircleRec(position.Value, circle.Radius, rectangleLeft) &&
                !CheckCollisionCircleRec(position.Value, circle.Radius, rectangleRight) &&
                !CheckCollisionCircleRec(position.Value, circle.Radius, rectangleTop) &&
                !CheckCollisionCircleRec(position.Value, circle.Radius, rectangleBottom) &&
                movementInput.Direction != raylib::Vector2::Zero()) {
                return;
            }

            movementInput.Direction =
                    movementInput.Direction == raylib::Vector2::Zero() ? raylib::Vector2(GetRandomValue(-1, 1),
                                                                                         GetRandomValue(-1,
                                                                                                        1)).Normalize()
                                                                       : (-movementInput.Direction +
                                                                          movementInput.Direction.Rotate(
                                                                                  GetRandomValue(-60, 60))).Normalize();

        });
    }
}
