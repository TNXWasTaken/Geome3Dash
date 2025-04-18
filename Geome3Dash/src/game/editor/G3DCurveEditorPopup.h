#pragma once

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

#include "transformer/GomtSpline.h"
#include "transformer/PomtSpline.h"
#include "transformer/PomtSplineCamera.h"

#include "model/GameObjectModel.h"

namespace sus3d
{
	class Model;
	class ShaderProgram;
}

namespace g3d
{
	class G3DBaseNode;
	class Spline;

	class G3DCurveEditorLoader;

	class G3DCurveEditorPopup 
		: public geode::Popup<G3DCurveEditorLoader*>
		, public CustomKeyboardDelegate
		, public CustomMouseDelegate
		, public CustomTouchDelegate 
	{
	protected:
		G3DCurveEditorLoader* cel;

		int selected = -1;

		bool isPressingControl = false;
		bool isPressingShift = false;
		bool isRightClicking = false;
		bool isRightClickingGetPos = false;
		float lastMouseX = 0.0;
		float lastMouseY = 0.0;

		GomtSpline* splineTr;
		std::vector<GameObjectModel> blocks;

		virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override;
		virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override;
		virtual void scrollWheel(float y, float x) override;
		virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override;

		bool setup(G3DCurveEditorLoader* cel) override;

		void draw() override;

		void onAddSegment(CCObject*);
		void onRemoveSegment(CCObject*);

		void onClose(CCObject* obj) override;
	public:
		static G3DCurveEditorPopup* create(G3DCurveEditorLoader* cel);

		~G3DCurveEditorPopup()
		{
			delete splineTr;
		}
	};
}