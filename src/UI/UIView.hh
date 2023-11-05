#pragma once

#include <imgui.h>

namespace Quill
{
    namespace UI
    {
        using namespace ImGui;

        struct View
        {
                     View() { OnAttach(); }
            virtual ~View() { OnDetach(); }
            
            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnRender() {}
        };
    }

};