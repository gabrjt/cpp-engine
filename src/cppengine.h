#ifndef CPP_ENGINE_CPPENGINE_H
#define CPP_ENGINE_CPPENGINE_H

#include <raylib-cpp.hpp>
#include <entt/entt.hpp>
#include "Application.h"
#include "System.h"

namespace Engine {
    raylib::Vector2 RandomVector2(int minX, int maxX, int minY, int maxY);
}

#endif //CPP_ENGINE_CPPENGINE_H
