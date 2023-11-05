#pragma once

#include "UIView.hh"

namespace Quill
{
    class MainView
        : public UI::View
    {
    public:
        void OnRender() override;

        void MenuBarCallback();
    };
};
