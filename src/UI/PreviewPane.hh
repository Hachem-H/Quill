#pragma once

#include "UIView.hh"

namespace Quill
{
    class PreviewPane
        : public UI::View
    {
    public:
        void OnRender() override;

        void EdgesDetectionTab();
        void VectorizationTab();
        void AnimationTab();
    };
};
