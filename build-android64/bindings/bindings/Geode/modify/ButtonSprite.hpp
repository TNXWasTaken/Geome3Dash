#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/ButtonSprite.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_setString
		#define GEODE_STATICS_setString
		GEODE_AS_STATIC_FUNCTION(setString) 
	#endif

	#ifndef GEODE_STATICS_updateBGImage
		#define GEODE_STATICS_updateBGImage
		GEODE_AS_STATIC_FUNCTION(updateBGImage) 
	#endif

	#ifndef GEODE_STATICS_updateSpriteBGSize
		#define GEODE_STATICS_updateSpriteBGSize
		GEODE_AS_STATIC_FUNCTION(updateSpriteBGSize) 
	#endif

	#ifndef GEODE_STATICS_updateSpriteOffset
		#define GEODE_STATICS_updateSpriteOffset
		GEODE_AS_STATIC_FUNCTION(updateSpriteOffset) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setColor
		#define GEODE_CONCEPT_CHECK_setColor
		GEODE_CONCEPT_FUNCTION_CHECK(setColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setString
		#define GEODE_CONCEPT_CHECK_setString
		GEODE_CONCEPT_FUNCTION_CHECK(setString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateBGImage
		#define GEODE_CONCEPT_CHECK_updateBGImage
		GEODE_CONCEPT_FUNCTION_CHECK(updateBGImage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateSpriteBGSize
		#define GEODE_CONCEPT_CHECK_updateSpriteBGSize
		GEODE_CONCEPT_FUNCTION_CHECK(updateSpriteBGSize) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateSpriteOffset
		#define GEODE_CONCEPT_CHECK_updateSpriteOffset
		GEODE_CONCEPT_FUNCTION_CHECK(updateSpriteOffset) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, ButtonSprite> : ModifyBase<ModifyDerive<Der, ButtonSprite>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, ButtonSprite>>;
		using ModifyBase<ModifyDerive<Der, ButtonSprite>>::ModifyBase;
		using Base = ButtonSprite;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12ButtonSpriteC2Ev")), Default, ButtonSprite, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<char const*, int, int, float, bool, char const*, char const*, float>::func(&ButtonSprite::create)), Default, ButtonSprite, create, char const*, int, int, float, bool, char const*, char const*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCSprite*, int, int, float, float, bool, char const*, bool>::func(&ButtonSprite::create)), Default, ButtonSprite, create, cocos2d::CCSprite*, int, int, float, float, bool, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, cocos2d::CCSprite*, int, bool, float, const char*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, const char*, int, bool, const char*, const char*, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, char const*, const char*, const char*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, char const*, const char*, const char*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, char const*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, char const*, int, int, float, bool, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, char const*, int, int, float, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, cocos2d::CCSprite*, int, int, float, float, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, create, cocos2d::CCSprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<char const*, int, int, float, bool, char const*, char const*, float>::func(&ButtonSprite::init)), Default, ButtonSprite, init, char const*, int, int, float, bool, char const*, char const*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCSprite*, int, int, float, float, bool, char const*, bool>::func(&ButtonSprite::init)), Default, ButtonSprite, init, cocos2d::CCSprite*, int, int, float, float, bool, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(ButtonSprite, setColor, cocos2d::ccColor3B)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<char const*>::func(&ButtonSprite::setString)), Default, ButtonSprite, setString, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<char const*>::func(&ButtonSprite::updateBGImage)), Default, ButtonSprite, updateBGImage, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&ButtonSprite::updateSpriteBGSize)), Default, ButtonSprite, updateSpriteBGSize, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCPoint>::func(&ButtonSprite::updateSpriteOffset)), Default, ButtonSprite, updateSpriteOffset, cocos2d::CCPoint)
		}
	};
}
