#include "MainView.hh"
#include "Core/Application.hh"

namespace Quill
{
    void MainView::MenuBarCallback()
    {
        if (ImGui::BeginMenu("File"))
        {
            ImGui::MenuItem("Load File");
            ImGui::MenuItem("Export as");
            ImGui::MenuItem("Preferences");

            if (ImGui::MenuItem("Exit"))
                Application::Get().Close();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help"))
        {
            ImGui::MenuItem("Project Wiki");
            ImGui::MenuItem("About");

            ImGui::EndMenu();
        }
    }

    void MainView::OnRender()
    {
        static ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;
        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar               |
                                       ImGuiWindowFlags_NoDocking             |
                                       ImGuiWindowFlags_NoCollapse            |
                                       ImGuiWindowFlags_NoBackground          |
                                       ImGuiWindowFlags_NoResize              |
                                       ImGuiWindowFlags_NoMove                |
                                       ImGuiWindowFlags_NoBringToFrontOnFocus |
                                       ImGuiWindowFlags_NoNavFocus            |
                                       ImGuiWindowFlags_NoTitleBar;

        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);

        ImGui::Begin("MainView", nullptr, windowFlags);

        ImGui::DockSpace(ImGui::GetID("dockspace"), ImVec2(0, 0), dockspaceFlags);
    
        ImGui::BeginMenuBar();
        MenuBarCallback();
        ImGui::EndMenuBar();

        ImGui::End();
    }
};
