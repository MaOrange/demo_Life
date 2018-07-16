#pragma once



#ifndef LIFE
#define LIFE
#include"cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;



class Life:public Node
{
public:
	Life();

	void damage(float x);

	void recover(float x);

	void restart(float x);

	CC_SYNTHESIZE(float,percent,Percnet);
	CC_SYNTHESIZE(float, maxLife, MaxLife);
	CC_SYNTHESIZE(float, currentLife, CurrentLife);

	CREATE_FUNC(Life);

	static Life* creatWithMaxLife(float max);

	bool initWithMaxLife(float max);

	bool init();

protected:
	/*float percent;
	float maxLife;
	float currentLife;*/

	const std::string backgournd = "lifeBackground_P";
	const std::string effect = "lifeEffect_LB";
	const std::string onShow = "lifeOnShow_LB";
	const std::string frame = "lifeFrame_P";
	const std::string root = "lifeRootNode";

	ui::LoadingBar* onShowLD;

	ui::LoadingBar* effectLD;

	Node* rootNode;

	void damageEffectCB(float dt);

	const float effectSpeed=20;

	inline void percentUpdate();

	inline void currentLifeCheck();
};

#endif // !LIFE
