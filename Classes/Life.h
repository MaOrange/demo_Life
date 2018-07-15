#pragma once



#ifndef LIFE
#define LIFE
#include"cocos2d.h"
USING_NS_CC;



class Life:public Node
{
public:
	Life();

	void setPercent(float x);

	void damage(float x);

	void recover(float x);

	void restart(float x);

protected:

};

#endif // !LIFE
