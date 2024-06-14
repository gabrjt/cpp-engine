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
    raylib::Window &window = application.OpenWindow("oie", 640, 480);

    REQUIRE(!window.ShouldClose());
}

TEST_CASE("Application GetWindow return same reference", "[application-get-window-valid-reference]") {
    Engine::Application &application = Engine::Application::Get();
    raylib::Window *window1 = &application.OpenWindow("oie", 640, 480);
    raylib::Window *window2 = &application.GetWindow();

    // Different pointers
    REQUIRE(&window1 != &window2);

    // Pointing to the same address
    REQUIRE(window1 == window2);
}

TEST_CASE("Application GetWindow return nullptr if not open", "[application-get-window-invalid-reference]") {
    Engine::Application &application = Engine::Application::Get();
    raylib::Window *window = &application.GetWindow();

    REQUIRE(window == nullptr);
}

TEST_CASE("Application Window should close if not open", "[application-get-window-invalid-instance]") {
    Engine::Application &application = Engine::Application::Get();
    raylib::Window &window = application.GetWindow();

    REQUIRE(window.ShouldClose());
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

TEST_CASE("Application RegisterSystems", "[application-register-systems]") {
    Engine::Application &application = Engine::Application::Get();
    std::array<Engine::System, 2> systems{};
    application.RegisterSystems(systems);

    REQUIRE(application.GetSystemsCount() == 2);
}

TEST_CASE("Application RegisterSystems expand capacity", "[application-register-systems-expand-capacity]") {
    Engine::Application &application = Engine::Application::Get();
    std::array<Engine::System, 2> systems1{};
    application.RegisterSystems(systems1);

    REQUIRE(application.GetSystemsCount() == 2);

    std::array<Engine::System, 3> systems2{};
    application.RegisterSystems(systems2);

    REQUIRE(application.GetSystemsCount() == 5);
}
