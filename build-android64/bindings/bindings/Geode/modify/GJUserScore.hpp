#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJUserScore.hpp>
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

	#ifndef GEODE_STATICS_isCurrentUser
		#define GEODE_STATICS_isCurrentUser
		GEODE_AS_STATIC_FUNCTION(isCurrentUser) 
	#endif

	#ifndef GEODE_STATICS_mergeWithScore
		#define GEODE_STATICS_mergeWithScore
		GEODE_AS_STATIC_FUNCTION(mergeWithScore) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isCurrentUser
		#define GEODE_CONCEPT_CHECK_isCurrentUser
		GEODE_CONCEPT_FUNCTION_CHECK(isCurrentUser) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_mergeWithScore
		#define GEODE_CONCEPT_CHECK_mergeWithScore
		GEODE_CONCEPT_FUNCTION_CHECK(mergeWithScore) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJUserScore> : ModifyBase<ModifyDerive<Der, GJUserScore>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJUserScore>>;
		using ModifyBase<ModifyDerive<Der, GJUserScore>>::ModifyBase;
		using Base = GJUserScore;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJUserScoreC2Ev")), Default, GJUserScore, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCDictionary*>::func(&GJUserScore::create)), Default, GJUserScore, create, cocos2d::CCDictionary*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&GJUserScore::create)), Default, GJUserScore, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&GJUserScore::init)), Default, GJUserScore, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&GJUserScore::isCurrentUser)), Default, GJUserScore, isCurrentUser, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GJUserScore*>::func(&GJUserScore::mergeWithScore)), Default, GJUserScore, mergeWithScore, GJUserScore*)
		}
	};
}
