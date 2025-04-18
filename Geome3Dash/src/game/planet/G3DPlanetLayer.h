#pragma once

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

#include "engine/sus3d/Model.h"
#include "engine/sus3d/Mesh.h"

#include "game/component/G3DBaseNode.h"

namespace g3d
{
    class G3DPlanetLayer;
    class G3DPlanetBaseNode : public G3DBaseNode 
    {
    public:
        G3DPlanetLayer* planetLayer;
        ~G3DPlanetBaseNode() override = default;
        virtual void draw() override;
        static G3DPlanetBaseNode* create();
    };

    class PlanetModel;
    class CloudModel;
    class G3DBaseNode;
    class CocosShaderProgram;
    class G3DRegionNameOverlay;
    class G3DPlanetLayer
        : public CCLayer
        , public CustomKeyboardDelegate
        , public CustomMouseDelegate
        , public CustomTouchDelegate 
    {
        enum MusicType 
        {
            Default,
            Plains,
            Ice,
            Desert
        };

        MusicType musicType = MusicType::Default;

        void setMusicType(MusicType newMT) 
        {
            if (newMT != musicType) 
            {
                musicType = newMT;
                playNewSongType();
            }
        }

        void detectBiomeMusic();

        G3DRegionNameOverlay* overlay;
        G3DPlanetBaseNode* layer3d;

        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;

        void updatePlanetRotation(const float delta);
        
        std::filesystem::path songPath;
        void playMusicDelayed(const float delta);

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override;
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override;
        virtual void scrollWheel(float y, float x) override;
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override;
    private:
        bool init() override;
        void onBack(CCObject*);
        virtual void keyBackClicked(void) override;
        virtual void onEnter() override;
    public:
        PlanetModel* planetModel;
        PlanetModel* planetWaterModel;
        CloudModel* cloudModel;

        static bool insideThePlanetLayerFlag;
        static G3DPlanetLayer* create();
        void playNewSongType();
    };

    class G3DRegionNameOverlay : public CCNode
    {
    public:
        CCLabelBMFont* m_regionTitle;
        CCLabelBMFont* m_musicTitle;

        template <class T>
        void show(T* child, GLubyte opacity = 255)
        {
            child->stopAllActions();
            child->setOpacity(opacity);
            child->runAction(CCSequence::create(
                CCDelayTime::create(1.f),
                CCFadeTo::create(2.f, 0), nullptr));
        }
        void show(const std::string& region, const std::string& music);

        virtual bool init() override;
        static G3DRegionNameOverlay* create();
    };
}