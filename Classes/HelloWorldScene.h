#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "LifePlus.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void damageCB(Ref* psender);

	void recoverCB(Ref* psender);

	Life* newNode;

	Size size = Director::getInstance()->getVisibleSize();

	void damageCB2(Ref* psender);

	void recoverCB2(Ref* psender);

	void addShield(Ref* psender);

	void addMax(Ref* psender);

	LifePlus* lifePlus;
};

#endif // __HELLOWORLD_SCENE_H__
