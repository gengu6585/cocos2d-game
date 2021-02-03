#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class textScrollEffects
{
public:


	static  void create(CCLayer* layer,CCPoint pos,const char path[]);
	void init(CCLayer* layer,CCPoint pos,const char path[]);
	textScrollEffects();
	~textScrollEffects();
	
private:
	CCLabelTTF *plabelArray[300];  //数组用于存放标签
	int sum;  //行数
	double delay;  //每行文字之间的延迟
};

