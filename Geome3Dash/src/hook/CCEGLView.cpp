#include "pch.h"

#ifdef GEODE_IS_WINDOWS

#include "manager/ModelManager.h"
#include "delegate/CustomTouch.h"
#include "delegate/CustomKeyboard.h"

#include <Geode/modify/CCEGLView.hpp>

namespace g3d
{
    class $modify(CCEGLView)
    {
        void onGLFWMouseMoveCallBack(GLFWwindow * window, double x, double y)
        {
            CustomTouchManager::onGLFWMouseMoveCallBack(window, x, y);
            CCEGLView::onGLFWMouseMoveCallBack(window, x, y);
        }

        void onGLFWMouseCallBack(GLFWwindow * window, int button, int action, int mods)
        {
            CustomTouchManager::onGLFWMouseCallBack(window, button, action, mods);
            CCEGLView::onGLFWMouseCallBack(window, button, action, mods);
        }

        void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            CustomKeyboardManager::updateDelegates(window, key, scancode, action, mods);
            CCEGLView::onGLFWKeyCallback(window, key, scancode, action, mods);       
        }

        void toggleFullScreen(bool fullscreen, bool borderless, bool fix)
        {
            CCEGLView::toggleFullScreen(fullscreen, borderless, fix);
            ModelManager::get()->shouldReloadShaders = true;
        }
    };
}

#endif