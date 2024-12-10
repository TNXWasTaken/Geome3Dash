#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_getOriginalTarget
		#define GEODE_STATICS_getOriginalTarget
		GEODE_AS_STATIC_FUNCTION(getOriginalTarget) 
	#endif

	#ifndef GEODE_STATICS_getSpeedMod
		#define GEODE_STATICS_getSpeedMod
		GEODE_AS_STATIC_FUNCTION(getSpeedMod) 
	#endif

	#ifndef GEODE_STATICS_getTag
		#define GEODE_STATICS_getTag
		GEODE_AS_STATIC_FUNCTION(getTag) 
	#endif

	#ifndef GEODE_STATICS_getTarget
		#define GEODE_STATICS_getTarget
		GEODE_AS_STATIC_FUNCTION(getTarget) 
	#endif

	#ifndef GEODE_STATICS_setOriginalTarget
		#define GEODE_STATICS_setOriginalTarget
		GEODE_AS_STATIC_FUNCTION(setOriginalTarget) 
	#endif

	#ifndef GEODE_STATICS_setSpeedMod
		#define GEODE_STATICS_setSpeedMod
		GEODE_AS_STATIC_FUNCTION(setSpeedMod) 
	#endif

	#ifndef GEODE_STATICS_setTarget
		#define GEODE_STATICS_setTarget
		GEODE_AS_STATIC_FUNCTION(setTarget) 
	#endif

	#ifndef GEODE_STATICS_description
		#define GEODE_STATICS_description
		GEODE_AS_STATIC_FUNCTION(description) 
	#endif

	#ifndef GEODE_STATICS_copyWithZone
		#define GEODE_STATICS_copyWithZone
		GEODE_AS_STATIC_FUNCTION(copyWithZone) 
	#endif

	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

	#ifndef GEODE_STATICS_isDone
		#define GEODE_STATICS_isDone
		GEODE_AS_STATIC_FUNCTION(isDone) 
	#endif

	#ifndef GEODE_STATICS_startWithTarget
		#define GEODE_STATICS_startWithTarget
		GEODE_AS_STATIC_FUNCTION(startWithTarget) 
	#endif

	#ifndef GEODE_STATICS_stop
		#define GEODE_STATICS_stop
		GEODE_AS_STATIC_FUNCTION(stop) 
	#endif

	#ifndef GEODE_STATICS_step
		#define GEODE_STATICS_step
		GEODE_AS_STATIC_FUNCTION(step) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getOriginalTarget
		#define GEODE_CONCEPT_CHECK_getOriginalTarget
		GEODE_CONCEPT_FUNCTION_CHECK(getOriginalTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getSpeedMod
		#define GEODE_CONCEPT_CHECK_getSpeedMod
		GEODE_CONCEPT_FUNCTION_CHECK(getSpeedMod) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTag
		#define GEODE_CONCEPT_CHECK_getTag
		GEODE_CONCEPT_FUNCTION_CHECK(getTag) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTarget
		#define GEODE_CONCEPT_CHECK_getTarget
		GEODE_CONCEPT_FUNCTION_CHECK(getTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setOriginalTarget
		#define GEODE_CONCEPT_CHECK_setOriginalTarget
		GEODE_CONCEPT_FUNCTION_CHECK(setOriginalTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setSpeedMod
		#define GEODE_CONCEPT_CHECK_setSpeedMod
		GEODE_CONCEPT_FUNCTION_CHECK(setSpeedMod) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTarget
		#define GEODE_CONCEPT_CHECK_setTarget
		GEODE_CONCEPT_FUNCTION_CHECK(setTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_description
		#define GEODE_CONCEPT_CHECK_description
		GEODE_CONCEPT_FUNCTION_CHECK(description) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_update
		#define GEODE_CONCEPT_CHECK_update
		GEODE_CONCEPT_FUNCTION_CHECK(update) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isDone
		#define GEODE_CONCEPT_CHECK_isDone
		GEODE_CONCEPT_FUNCTION_CHECK(isDone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_startWithTarget
		#define GEODE_CONCEPT_CHECK_startWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(startWithTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stop
		#define GEODE_CONCEPT_CHECK_stop
		GEODE_CONCEPT_FUNCTION_CHECK(stop) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_step
		#define GEODE_CONCEPT_CHECK_step
		GEODE_CONCEPT_FUNCTION_CHECK(step) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCAction> : ModifyBase<ModifyDerive<Der, cocos2d::CCAction>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCAction>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCAction>>::ModifyBase;
		using Base = cocos2d::CCAction;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCAction::create)), Default, cocos2d::CCAction, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCAction::getOriginalTarget)), Default, cocos2d::CCAction, getOriginalTarget, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCAction::getSpeedMod)), Default, cocos2d::CCAction, getSpeedMod, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCAction::getTag)), Default, cocos2d::CCAction, getTag, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCAction::getTarget)), Default, cocos2d::CCAction, getTarget, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCAction::setOriginalTarget)), Default, cocos2d::CCAction, setOriginalTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<float>::func(&cocos2d::CCAction::setSpeedMod)), Default, cocos2d::CCAction, setSpeedMod, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCAction::setTarget)), Default, cocos2d::CCAction, setTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8CCActionC2Ev")), Default, cocos2d::CCAction, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8CCActionD2Ev")), Default, cocos2d::CCAction)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCAction::description)), Default, cocos2d::CCAction, description, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCAction::copyWithZone)), Default, cocos2d::CCAction, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&cocos2d::CCAction::update)), Default, cocos2d::CCAction, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&cocos2d::CCAction::isDone)), Default, cocos2d::CCAction, isDone, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCAction::startWithTarget)), Default, cocos2d::CCAction, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&cocos2d::CCAction::stop)), Default, cocos2d::CCAction, stop, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&cocos2d::CCAction::step)), Default, cocos2d::CCAction, step, float)
		}
	};
}
