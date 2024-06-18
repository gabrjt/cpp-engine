#include "cppengine.h"

namespace Engine {
    raylib::Vector2 RandomVector2(const int minX, const int maxX, const int minY, const int maxY) {
        const float x = GetRandomValue(minX, maxX);
        const float y = GetRandomValue(minY, maxY);

        return {x, y};
    }
}
