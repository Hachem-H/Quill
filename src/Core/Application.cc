#include "Application.hh"
#include "Log.hh"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace Quill
{
    static Application* instance = nullptr;

    Application& Application::Get()
    {
        return *instance;
    }

    Application::Application()
    {
        instance = this;
        Init();
    }

    Application::~Application()
    {
        Shutdown();
        instance = nullptr;
    }

    void Application::Init()
    {
        Logger::Init();
        if (!glfwInit())
            QUILL_ERROR("Could not initialize GLFW.");
        
        window = glfwCreateWindow(1920, 1080, "Quill", nullptr, nullptr);
        glfwMakeContextCurrent(window);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        ImGui::StyleColorsDark();
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");

        isRunning = true;
    }

    void Application::Shutdown()
    {
        isRunning = false;

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Application::GetTime()
    {
        float time    = (float)glfwGetTime();
        frameTime     = time - lastFrameTime;
        timeStep      = std::min(frameTime, 0.0333f);
        lastFrameTime = time;
    }

    void Application::Close()
    {
        isRunning = false;
    }

    void Application::Run()
    {
        while (isRunning)
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            mainView.OnRender();

            ImGui::Begin("Stats");
            ImGui::Text("FPS: %d", (int)(1/frameTime));
            ImGui::Text("dt: %f", timeStep);
            ImGui::End();

            ImGui::Render();

            int windowWidth, windowHeight;
            glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
            glViewport(0, 0, windowWidth, windowHeight);

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            GLFWwindow* backupCurrentContext = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backupCurrentContext);

            glfwSwapBuffers(window);
            glfwPollEvents();
            GetTime();

            if (glfwWindowShouldClose(window))
                Close();
        }
    }
};
