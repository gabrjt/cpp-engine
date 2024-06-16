#include <cstring>
#include <iostream>
#include "cppengine.h"

class WindowSystem final : public Engine::System {
private:
    std::shared_ptr<raylib::Window> m_Window;
    raylib::Color m_ClearBackgroundColor;
public:
    WindowSystem() : m_Window(Engine::Application::Get().OpenWindow("CPP ENGINE", 1920, 1080)),
                     m_ClearBackgroundColor(BLACK) {}

    WindowSystem(const char *title, int width, int height, raylib::Color clearBackgroundColor) : m_Window(
            Engine::Application::Get().OpenWindow(title, width, height)), m_ClearBackgroundColor(clearBackgroundColor) {
    }

    void Update() override {
        static const char *text = "WELCOME TO CPP ENGINE";
        static const int length = strlen(text);

        m_Window->ClearBackground(m_ClearBackgroundColor);

        DrawText(text, (m_Window->GetWidth() / 2) - (length * 60 / 3), m_Window->GetHeight() / 2, 60, RAYWHITE);
    }
};

struct Position {
    raylib::Vector2 Value;
};

struct Circle {
    float Radius{};
    raylib::Color Color;

    static entt::entity Create(entt::registry &registry, Circle &&circle, Position &&position) {
        const entt::entity entity = registry.create();
        registry.emplace<Circle>(entity, circle);
        registry.emplace<Position>(entity, position);

        return entity;
    }
};

class SpawnCircleSystem : public Engine::System {
public:
    SpawnCircleSystem() {
        Circle::Create(Engine::Application::Get().GetRegistry(), {25, BLUE}, {{64, 64}});
    }

    void Update() override {}
};

class DrawCircleSystem : public Engine::System {
public:
    void Update() override {
        static entt::registry &registry = Engine::Application::Get().GetRegistry();
        auto view = registry.view<const Circle, const Position>();

        view.each([](const Circle &circle, const Position &position) {
            DrawCircle(position.Value.x, position.Value.y, circle.Radius, circle.Color);
        });
    }
};

struct Input {
    raylib::Vector2 Joystick;
};

struct Player {
    static entt::entity Create(entt::registry &registry) {
        const entt::entity entity = registry.create();

        registry.emplace<Player>(entity);
        registry.emplace<Input>(entity);

        return entity;
    }
};

class CreatePlayerSystem : public Engine::System {
public:
    CreatePlayerSystem() {
        Player::Create(Engine::Application::Get().GetRegistry());
    }

    void Update() override {}
};

class PlayerInputSystem : public Engine::System {
public:
    void Update() override {
        static entt::registry &registry = Engine::Application::Get().GetRegistry();
        auto view = registry.view<const Player, Input>();

        view.each([](Input &input) {
            float x = 0, y = 0;

            if (IsKeyDown(KEY_A)) {
                x = -1;
            } else if (IsKeyDown(KEY_D)) {
                x = 1;
            }

            if (IsKeyDown(KEY_W)) {
                y = -1;
            } else if (IsKeyDown(KEY_S)) {
                y = 1;
            }

            input.Joystick = raylib::Vector2(x, y);
        });
    }
};

class LogPlayerInputSystem : public Engine::System {
public:
    void Update() override {
        static entt::registry &registry = Engine::Application::Get().GetRegistry();
        auto view = registry.view<const Player, const Input>();

        view.each([](const Input &input) {
            std::cout << "Player Input: " << input.Joystick.ToString() << std::endl;
        });
    }
};

int main() {
    Engine::Application &application = Engine::Application::Get();
    application.RegisterSystems(WindowSystem(), CreatePlayerSystem(), PlayerInputSystem(), LogPlayerInputSystem(),
                                SpawnCircleSystem(), DrawCircleSystem());

    std::shared_ptr<raylib::Window> window = application.GetWindow();

    while (!window->ShouldClose()) {
        BeginDrawing();
        application.UpdateSystems();
        EndDrawing();
    }

    return 0;
}
