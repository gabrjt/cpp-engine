//
// Created by Gabriel on 16/06/2024.
//

#include <cppengine.h>
#include "Circle.h"
#include "Position.h"
#include "SpawnCircleSystem.h"

namespace Engine::Examples::Collision {
    SpawnCircleSystem::SpawnCircleSystem() {
        Circle::Create(Engine::Application::Get().GetRegistry(), {25, BLUE}, {{64, 64}});
    }
}
