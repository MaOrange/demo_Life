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

	void recover(float x);

	//void restart(float x);//abandon

	CC_SYNTHESIZE(float,percent,Percnet);
	CC_SYNTHESIZE(float, maxLife, MaxLife);
	CC_SYNTHESIZE(float, currentLife, CurrentLife);


	static Life* creatWithMaxLife(float max, const std::string fileName);

	bool initWithMaxLife(float max, const std::string fileName);

protected:

	CREATE_FUNC(Life);

	bool init();

	static const std::string backgournd; 
	static const std::string effect;
	static const std::string onShow;
	static const std::string frame;
	static const std::string root;

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

	virtual bool init() override;

	float currentShield=0;

	static std::string shield;

	ui::LoadingBar * shieldLB;

	void shieldUpdate();

};



#endif // !LIFE
