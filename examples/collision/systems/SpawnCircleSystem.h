//
// Created by Gabriel on 16/06/2024.
//

#ifndef CPP_ENGINE_SPAWNCIRCLESYSTEM_H
#define CPP_ENGINE_SPAWNCIRCLESYSTEM_H

namespace Engine::Examples::Collision {
    class SpawnCircleSystem final : public Engine::System {
    private:
        int m_Count;

    public:
        SpawnCircleSystem(int count);

        void Initialize() override;

        void Update() override;
    };
}

#endif //CPP_ENGINE_SPAWNCIRCLESYSTEM_H
