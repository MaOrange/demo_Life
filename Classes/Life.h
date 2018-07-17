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

	virtual void damage(float x);

	virtual void recover(float x);

	void restart(float x);

	CC_SYNTHESIZE(float,percent,Percnet);
	CC_SYNTHESIZE(float, maxLife, MaxLife);
	CC_SYNTHESIZE(float, currentLife, CurrentLife);

	CREATE_FUNC(Life);

	static Life* creatWithMaxLife(float max, const std::string fileName);

	virtual bool initWithMaxLife(float max, const std::string fileName);

	virtual bool init();

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

	virtual inline void percentUpdate();

	inline void currentLifeCheck();
};


class LifePlus:public Life
{
public:
	void addShield(float x);
	
	void removeAllShield();

	void percentUpdate() override;

	void damage(float x) override;


	static LifePlus* creatWithMaxLife(float max, const std::string fileName);

	bool initWithMaxLife(float max, const std::string fileName);


protected:

	CREATE_FUNC(LifePlus);

	float currentShield=0;

	static std::string shield;

	ui::LoadingBar * shieldLB;

	bool init()override;

	void shieldUpdate();

};



#endif // !LIFE
