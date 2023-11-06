#include "PreviewPane.hh"


namespace Quill
{
    void PreviewPane::OnRender()
    {
        ImGui::Begin("Previews");
        if (ImGui::BeginTabBar("Previews"))
        {
            if (ImGui::BeginTabItem("Edges"))
            {
                EdgesDetectionTab();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Vectorization"))
            {
                VectorizationTab();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Animation"))
            {
                AnimationTab();
                ImGui::EndTabItem();
            }


            ImGui::Spacing();
            ImGui::EndTabBar();
        }

        ImGui::End();
    }

    void PreviewPane::AnimationTab()      { ImGui::Text("Animation Tab"); }
    void PreviewPane::VectorizationTab()  { ImGui::Text("Vectorization Tab"); }
    void PreviewPane::EdgesDetectionTab() { ImGui::Text("Edges Detection Tab"); }
};
