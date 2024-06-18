//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Circle.h"
#include "Player.h"
#include "PlayerRef.h"
#include "Position.h"
#include "Speed.h"
#include "CreatePlayerSystem.h"

namespace Engine::Examples::Collision {
    CreatePlayerSystem::CreatePlayerSystem(const std::shared_ptr<raylib::Window> window,
                                           const std::shared_ptr<entt::registry> registry) {
        const int width = window->GetWidth();
        const int height = window->GetHeight();
        const Circle circle(25, BLUE);
        const Position position(raylib::Vector2(GetRandomValue(circle.Radius, width - circle.Radius),GetRandomValue(
                circle.Radius, height - circle.Radius)));
        const Speed speed(256);

        const entt::entity playerEntity = Player::Create(*registry);
        Circle::CreatePlayer(*registry, PlayerRef(playerEntity), circle, position, speed);
    }

    void CreatePlayerSystem::Update() {}
}
