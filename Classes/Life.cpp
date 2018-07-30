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

void Life::recover(float x)
{
	currentLife += x;
	currentLifeCheck();
	percentUpdate();

	onShowLD->setPercent(percent);

	effectCheck();

}

Life* Life::creatWithMaxLife(float max, const std::string fileName)
{
	auto newLife = Life::create();

	newLife->initWithMaxLife(max,fileName);
	
	return newLife;
}

bool Life::initWithMaxLife(float max, const std::string fileName)
{
	//
	auto tempScene = CSLoader::createNode(fileName);

	Node* lifeRootNode = tempScene->getChildByName(root);

	lifeRootNode->removeFromParent();

	lifeRootNode->setPosition(Point::ZERO);

	this->addChild(lifeRootNode);

	rootNode = this->getChildren().at(0);

	//

	maxLife = max;

	currentLife = max;

	percentUpdate();

	onShowLD= ((ui::LoadingBar*)rootNode->getChildByName(onShow));
		
	onShowLD->setPercent(percent);

	effectLD = ((ui::LoadingBar*)rootNode->getChildByName(effect));
	effectLD->setPercent(percent);

	return true;
}

void Life::effectCheck()
{
	if (effectLD->getPercent() < percent)
	{
		effectLD->setPercent(percent);
	}
}

//bool Life::init()
//{
//	if (!Node::init())
//	{
//		return false;
//	}
//
//	return true;
//}

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

void Life::percentUpdate()
{
	percent = currentLife / maxLife * 100;
}

inline void Life::currentLifeCheck()
{
	if (currentLife>maxLife)
	{
		currentLife = maxLife;
	} 
	else if(currentLife<0)
	{
		currentLife = 0;
	}
}


