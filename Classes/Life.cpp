#include "Life.h"

Life::Life() {
	
}

void Life::damage(float x)
{
	currentLife-=x;
	currentLife = (currentLife>0) ? (currentLife) : (currentLife=0);

	onShowLD->setPercent(currentLife/maxLife*100);

	schedule(schedule_selector(Life::damageEffectCB), 1.0f / 60);

}

Life* Life::creatWithMaxLife(float max)
{
	auto newLife = Life::create();

	newLife->initWithMaxLife(max);
	
	return newLife;
}

bool Life::initWithMaxLife(float max)
{
	maxLife = max;

	currentLife = max;

	percent = currentLife / maxLife*100;

	onShowLD= ((ui::LoadingBar*)rootNode->getChildByName(onShow));
		
	onShowLD->setPercent(percent);

	effectLD = ((ui::LoadingBar*)rootNode->getChildByName(effect));
	effectLD->setPercent(percent);

	return true;
}

bool Life::init()
{
	if (!Node::init())
	{
		return false;
	}

	auto tempScene = CSLoader::createNode("demoLifeScene.csb"); 

	Node* lifeRootNode = tempScene->getChildByName(root);

	this->addChild(lifeRootNode);

	rootNode = this->getChildren().at(0);

	tempScene->release();

	return true;
}

void Life::damageEffectCB(float dt)
{
	if (onShowLD->getPercent()<effectLD->getPercent())
	{
		effectLD->setPercent(effectLD->getPercent()-dt*effectSpeed);
	} 
	else
	{
		unschedule(schedule_selector(Life::damageEffectCB));
	}
	
}
