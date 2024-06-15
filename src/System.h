//
// Created by Gabriel on 14/06/2024.
//

#ifndef CPP_ENGINE_SYSTEM_H
#define CPP_ENGINE_SYSTEM_H

namespace Engine {
    class System {
    public:
        virtual ~System() = default;

        virtual void Update(entt::registry &simulation) {}
    };
}

#endif //CPP_ENGINE_SYSTEM_H
