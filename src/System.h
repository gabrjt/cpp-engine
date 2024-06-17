//
// Created by Gabriel on 14/06/2024.
//

#ifndef CPP_ENGINE_SYSTEM_H
#define CPP_ENGINE_SYSTEM_H

namespace Engine {
    class System {
    public:
        virtual ~System() = default;

        // Use constructor for self-contained data.
        // Use Initialize for accessing dependencies.
        virtual void Initialize() = 0;

        virtual void Update() = 0;
    };
}

#endif //CPP_ENGINE_SYSTEM_H
