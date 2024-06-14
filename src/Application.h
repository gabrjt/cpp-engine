//
// Created by Gabriel on 12/06/2024.
//

#ifndef CPP_ENGINE_APPLICATION_H
#define CPP_ENGINE_APPLICATION_H

#include <raylib-cpp.hpp>

namespace Engine {
    class Application {
    private:
        int m_FrameRate;
        raylib::Window *m_Window;

    public:
        Application();

        Application(Application &) = delete;

        static Application &Get();

        void SetTargetFrameRate(int frameRate);

        int GetTargetFrameRate() const;

        raylib::Window &OpenWindow(const char *title, int width, int height);

        raylib::Window &GetWindow() const;
    };
}

#endif //CPP_ENGINE_APPLICATION_H
