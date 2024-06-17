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
    void CreatePlayerSystem::Initialize() {
        Engine::Application &application = Engine::Application::Get();
        std::shared_ptr<raylib::Window> window = application.GetWindow();
        entt::registry &registry = application.GetRegistry();
        const int width = window->GetWidth();
        const int height = window->GetHeight();
        const Circle circle(25, BLUE);
        const Position position{raylib::Vector2(GetRandomValue(circle.Radius, width - circle.Radius),
                                                GetRandomValue(circle.Radius, height - circle.Radius))};
        const Speed speed{256};
        const entt::entity playerEntity = Player::Create(registry);
        const entt::entity circleEntity = Circle::CreatePlayer(registry, {playerEntity}, circle, position, speed);
    }

    void CreatePlayerSystem::Update() {}
}
