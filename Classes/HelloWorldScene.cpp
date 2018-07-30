#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	/**  you can create scene with following comment code instead of using csb file.
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
										   "CloseNormal.png",
										   "CloseSelected.png",
										   CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
								origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	
	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	
	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width/2,
							origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	**/
	
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}
	
	Node* rootNode = CSLoader::createNode("Life/demoLifeScene.csb");

	addChild(rootNode);

	//my code:
	newNode = Life::creatWithMaxLife(5000.0,"Life/Life.csb");

	this->addChild(newNode,3);

	newNode->setPosition(size.width/2,size.height/2);

	//
	lifePlus = LifePlus::creatWithMaxLife(5000.0f, "Life/LifePlus.csb");
	
	this->addChild(lifePlus,3);

	lifePlus->setPosition(size.width/2,size.height*0.4);

	//tester
	ui::Button * damageButton=(ui::Button*)(rootNode->getChildByName("Button_1"));

	ui::Button * recoverButton = (ui::Button*)(rootNode->getChildByName("Button_2"));

	damageButton->addClickEventListener(CC_CALLBACK_1(HelloWorld::damageCB,this));

	recoverButton->addClickEventListener(CC_CALLBACK_1(HelloWorld::recoverCB, this));

	//
	//test button for plus
	ui::Button * damageButtonP = (ui::Button*)(rootNode->getChildByName("Button_damage"));

	ui::Button * recoverButtonP = (ui::Button*)(rootNode->getChildByName("Button_recover"));

	ui::Button * addShieldButtonP = (ui::Button*)(rootNode->getChildByName("Button_shield"));

	ui::Button * addMaxButtonP = (ui::Button*)(rootNode->getChildByName("Button_addMax"));

	damageButtonP->addClickEventListener(CC_CALLBACK_1(HelloWorld::damageCB2, this));

	recoverButtonP->addClickEventListener(CC_CALLBACK_1(HelloWorld::recoverCB2, this));

	addShieldButtonP->addClickEventListener(CC_CALLBACK_1(HelloWorld::addShield, this));

	addMaxButtonP->addClickEventListener(CC_CALLBACK_1(HelloWorld::addMax, this));

	return true;
}

void HelloWorld::damageCB(Ref * psender)
{
	newNode->damage(500);
	log("damage!");
}

void HelloWorld::recoverCB(Ref * psender)
{
	newNode->recover(100);
	log("cover!");

}


void HelloWorld::damageCB2(Ref * psender)
{
	lifePlus->damage(500);
	log("damage1!");
}

void HelloWorld::recoverCB2(Ref * psender)
{
	lifePlus->recover(500);
	log("recover1!");

}

void HelloWorld::addShield(Ref * psender)
{
	lifePlus->addShield(260);
}

void HelloWorld::addMax(Ref * psender)
{
	lifePlus->addMaxLife(300);
}
