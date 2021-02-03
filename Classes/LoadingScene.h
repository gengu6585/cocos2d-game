#pragma once    //保证后面的代码只执行一次
#include "cocos2d.h"
using namespace cocos2d;
class LoadingScene: public cocos2d::CCLayer 
{
public:
	
	// 创建场景
	static cocos2d::CCScene* scene();
	
	// 初始化
	virtual bool init();
	

	// 创建层
	CREATE_FUNC(LoadingScene);

	//切换到Hello界面的按钮的回调函数
	// void 函数名(CCObject* pSender);
	void seqChangeScene();
	void ChangeSceneMenu1(CCObject* pSender);
private:
	CCMenuItemImage* ToHello;
	
	CCMenuItemSprite* JunpOver;			//跳过按钮
	CCSprite*        NoTouchJunpOver;   //ToScene1没有按下的状态
	CCSprite*        OnTouchJunpOver;   //ToScene1按下的状态
	CCMenu*			 pMenu;
};

