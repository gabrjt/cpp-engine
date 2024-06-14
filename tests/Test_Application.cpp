//
// Created by Gabriel on 12/06/2024.
//
#include <catch2/catch_test_macros.hpp>
#include "Application.h"

TEST_CASE("Application is Singleton", "[application-singleton]") {
    Engine::Application *application1 = &Engine::Application::Get();
    Engine::Application *application2 = &Engine::Application::Get();

    // Different pointers
    REQUIRE(&application1 != &application2);

    // Pointing to the same address
    REQUIRE(application1 == application2);
}

TEST_CASE("Application open Window", "[application-open-window]") {
    Engine::Application &application = Engine::Application::Get();
    raylib::Window &window = application.OpenWindow("oie", 640, 480);

    REQUIRE(!window.ShouldClose());
}

TEST_CASE("Application start with 60 FPS", "[application-start-60-fps]") {
    Engine::Application &application = Engine::Application::Get();

    REQUIRE(application.GetTargetFrameRate() == 60);
}

TEST_CASE("Application set target frame rate", "[application-set-target-fps]") {
    Engine::Application &application = Engine::Application::Get();


    application.SetTargetFrameRate(30);

    REQUIRE(application.GetTargetFrameRate() == 30);
}
