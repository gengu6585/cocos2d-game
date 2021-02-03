#pragma once    //保证后面的代码只执行一次
#include "cocos2d.h"

using namespace cocos2d;
class choiceGrass: public cocos2d::CCLayer 
{
public:

	// 创建场景
	static cocos2d::CCScene* scene();

	// 初始化
	virtual bool init();
	// 创建层
	CREATE_FUNC(choiceGrass);

	// 注册触摸·
	virtual void registerWithTouchDispatcher(void);

	/*virtual void */
private:
	CCSprite* bgpicture1;
	
	CCPoint lvPos[20];



	
};