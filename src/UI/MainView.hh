#pragma once

#include "UIView.hh"
#include "PreviewPane.hh"

namespace Quill
{
    class MainView
        : public UI::View
    {
    public:
        void OnRender() override;
        void MenuBarCallback();
    private:
        PreviewPane previewPane;
    };
};
