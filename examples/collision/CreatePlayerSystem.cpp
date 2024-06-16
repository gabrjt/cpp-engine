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
    CreatePlayerSystem::CreatePlayerSystem() {
        entt::registry &registry = Engine::Application::Get().GetRegistry();
        entt::entity playerEntity = Player::Create(registry);
        entt::entity circleEntity = Circle::CreatePlayer(registry, {playerEntity}, {25, RED}, {{128, 128}}, {256});
    }
}
