#pragma once

#include <GLFW/glfw3.h>

#include <functional>

#include "UI/MainView.hh"

namespace Quill 
{
    class Application
    {
    public:
        Application();
        ~Application();

        static Application& Get();

        void Run();
        void Close();
        void GetTime();
    private:
        void Init();
        void Shutdown();
    private:
        GLFWwindow* window    = nullptr;
        bool        isRunning = false;

        float timeStep      = 0.0f;
        float frameTime     = 0.0f;
        float lastFrameTime = 0.0f;

        MainView mainView;
    };
};
