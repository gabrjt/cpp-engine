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
    AIMovementInputSystem::AIMovementInputSystem(const std::shared_ptr<raylib::Window> &&window,
                                                 const std::shared_ptr<entt::registry> &&registry) : m_Window(window),
                                                                                                     m_Registry(
                                                                                                             registry) {}

    void AIMovementInputSystem::Update() {
        const int width = m_Window->GetWidth();
        const int height = m_Window->GetHeight();
        const raylib::Rectangle rectangleLeft(0, 0, .05f, height);
        const raylib::Rectangle rectangleRight(width, 0, .05f, height);
        const raylib::Rectangle rectangleTop(0, 0, width, .05f);
        const raylib::Rectangle rectangleBottom(0, height, width, .05f);
        auto view = m_Registry->view<const Circle, const Position, MovementInput>(entt::exclude<PlayerRef>);

        view.each([&](const Circle &circle, const Position &position, MovementInput &movementInput) {
            const bool collisionLeft = CheckCollisionCircleRec(position.Value, circle.Radius, rectangleLeft);
            const bool collisionRight = CheckCollisionCircleRec(position.Value, circle.Radius, rectangleRight);
            const bool collisionTop = CheckCollisionCircleRec(position.Value, circle.Radius, rectangleTop);
            const bool collisionBottom = CheckCollisionCircleRec(position.Value, circle.Radius, rectangleBottom);

            DrawLine(position.Value.x, position.Value.y, position.Value.x + movementInput.Direction.x * circle.Radius * 2,
                     position.Value.y + movementInput.Direction.y * circle.Radius * 2, GREEN);

            if (!collisionLeft &&
                !collisionRight &&
                !collisionTop &&
                !collisionBottom &&
                movementInput.Direction != raylib::Vector2::Zero()) {
                return;
            }

            if (movementInput.Direction == raylib::Vector2::Zero()) {
                movementInput.Direction = raylib::Vector2(GetRandomValue(-1, 1), GetRandomValue(-1, 1)).Normalize();
            } else {
                movementInput.Direction = raylib::Vector2::Zero();

                if (collisionLeft) {
                    movementInput.Direction.x += 1;
                }

                if (collisionRight) {
                    movementInput.Direction.x -= 1;
                }

                if (collisionTop) {
                    movementInput.Direction.y += 1;
                }

                if (collisionBottom) {
                    movementInput.Direction.y -= 1;
                }

                movementInput.Direction = movementInput.Direction.Rotate(DEG2RAD * GetRandomValue(-60, 60)).Normalize();
            }
        });
    }
}
