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

	if (effectLD->getPercent()<percent)
	{
		effectLD->setPercent(percent);
	}

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

	tempScene->release();
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

bool Life::init()
{
	if (!Node::init())
	{
		return false;
	}

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

//LifePllus

std::string LifePlus::shield = "lifeShield_LB";

void LifePlus::addShield(float x)
{
	currentShield += x;
	shieldUpdate();
}

void LifePlus::removeAllShield()
{
	currentShield = 0;
	shieldUpdate();
}

void LifePlus::percentUpdate()
{
	percent = (currentLife+currentShield) / (maxLife+currentShield) * 100;
}

void LifePlus::damage(float x)
{
	if (x<currentShield)//the damage is no enough to break the shield
	{
		currentShield -= x;
		shieldUpdate();
	} 
	else// shield break through and damage(x-currtentShield)
	{
		removeAllShield();
		Life::damage(x-currentShield);
	}
	
}


LifePlus * LifePlus::creatWithMaxLife(float max, const std::string fileName)
{
	LifePlus* newLifeBar = LifePlus::create();

	if (!newLifeBar || !newLifeBar->initWithMaxLife(max,fileName))
	{
		CC_SAFE_DELETE(newLifeBar);
		return nullptr;
	} 
	
	return newLifeBar;
}

bool LifePlus::initWithMaxLife(float max, const std::string fileName)
{
	if (!Life::initWithMaxLife(max, fileName))
	{
		return false;
	}

	//hold handle
	shieldLB = static_cast<ui::LoadingBar*>(this->getChildren().at(0)->getChildByName(shield));


	return true;
}

bool LifePlus::init()
{
	shieldLB = static_cast<ui::LoadingBar*>(this->getChildren().at(0)->getChildByName(shield));
	return Life::init();

}



void LifePlus::shieldUpdate()
{
	percentUpdate();
	shieldLB->setPercent(percent + (currentShield) / (maxLife));
	onShowLD->setPercent(percent);
}
