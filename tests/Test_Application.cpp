//
// Created by Gabriel on 12/06/2024.
//
#include <catch2/catch_test_macros.hpp>
#include "cppengine.h"

TEST_CASE("Application is Singleton", "[application-singleton]") {
    Engine::Application *application1 = &Engine::Application::Get();
    Engine::Application *application2 = &Engine::Application::Get();

    // Different pointers
    REQUIRE(&application1 != &application2);

    // Pointing to the same address
    REQUIRE(application1 == application2);
}

TEST_CASE("Application OpenWindow", "[application-open-window]") {
    Engine::Application &application = Engine::Application::Get();
    std::shared_ptr<raylib::Window> window = application.OpenWindow("oie", 640, 480);

    REQUIRE(!window->ShouldClose());
}

TEST_CASE("Application GetWindow return same reference", "[application-get-window-valid-reference]") {
    Engine::Application &application = Engine::Application::Get();
    std::shared_ptr<raylib::Window> window1 = application.OpenWindow("oie", 640, 480);
    std::shared_ptr<raylib::Window> window2 = application.GetWindow();

    // Different pointers
    REQUIRE(&window1 != &window2);

    // Pointing to the same address
    REQUIRE(window1 == window2);

    REQUIRE(window1.use_count() == window2.use_count());
}

TEST_CASE("Application GetWindow return shared ptr", "[application-get-window-shared-ptr]") {
    Engine::Application &application = Engine::Application::Get();
    std::shared_ptr<raylib::Window> window1 = application.OpenWindow("oie", 640, 480);

    REQUIRE(window1.use_count() == 2);

    {
        std::shared_ptr<raylib::Window> window2 = application.GetWindow();

        REQUIRE(window1.use_count() == 3);
    }

    REQUIRE(window1.use_count() == 2);
}

TEST_CASE("Application GetWindow return nullptr if not open", "[application-get-window-invalid-reference]") {
    Engine::Application &application = Engine::Application::Get();
    std::shared_ptr<raylib::Window> window = application.GetWindow();

    REQUIRE(window == nullptr);
    REQUIRE(window.use_count() == 0);
}

TEST_CASE("Application Window should close if not open", "[application-get-window-invalid-instance]") {
    Engine::Application &application = Engine::Application::Get();
    std::shared_ptr<raylib::Window> window = application.GetWindow();

    REQUIRE(window->ShouldClose());
}

TEST_CASE("Application start with 60 FPS", "[application-start-60-fps]") {
    Engine::Application &application = Engine::Application::Get();

    REQUIRE(application.GetTargetFrameRate() == 60);
}

TEST_CASE("Application SetTargetFrameRate", "[application-set-target-fps]") {
    Engine::Application &application = Engine::Application::Get();
    application.SetTargetFrameRate(30);

    REQUIRE(application.GetTargetFrameRate() == 30);
}

class FooSystem : public Engine::System {
public:
    void Initialize() override {}

    void Update() override {}
};

class BarSystem : public Engine::System {
public:
    void Initialize() override {}

    void Update() override {}
};

class FoobarSystem : public Engine::System {
public:
    void Initialize() override {}

    void Update() override {}
};

TEST_CASE("Application RegisterSystems", "[application-register-systems]") {
    Engine::Application &application = Engine::Application::Get();
    application.RegisterSystems(FooSystem(), BarSystem());

    REQUIRE(application.GetSystemsCount() == 2);
}

TEST_CASE("Application RegisterSystems expand capacity", "[application-register-systems-expand-capacity]") {
    Engine::Application &application = Engine::Application::Get();

    application.RegisterSystems(FooSystem(), BarSystem());

    REQUIRE(application.GetSystemsCount() == 2);

    application.RegisterSystems(FooSystem(), BarSystem(), FoobarSystem());

    REQUIRE(application.GetSystemsCount() == 5);
}

TEST_CASE("Application RegisterSystems add systems in order", "[application-register-systems-in-order]") {
    Engine::Application &application = Engine::Application::Get();

    application.RegisterSystems(FooSystem(), FoobarSystem(), BarSystem());

    REQUIRE(application.GetSystemsCount() == 3);

    const std::vector<std::unique_ptr<Engine::System>> &systems = application.GetSystems();

    REQUIRE(dynamic_cast<FooSystem *>(systems[0].get()));
    REQUIRE(dynamic_cast<FoobarSystem *>(systems[1].get()));
    REQUIRE(dynamic_cast<BarSystem *>(systems[2].get()));
}
