#pragma once

#include <string>
#include <cstdint>

#include <GLFW/glfw3.h>

namespace Quill 
{
    class Application
    {
    public:
        Application();
        ~Application();

        static Application& Get();

        void Run();
    private:
        void Init();
        void Shutdown();
    private:
        GLFWwindow* window = nullptr;
    };
};
