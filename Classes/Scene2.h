#pragma once    //保证后面的代码只执行一次
#include "cocos2d.h"
#include "textScrollEffects.h"
using namespace cocos2d;
class Scene2: public cocos2d::CCLayerColor 
{
public:

	// 创建场景
	static cocos2d::CCScene* scene();

	// 初始化
	virtual bool init();


	// 创建层
	CREATE_FUNC(Scene2);

	//切换到Hello界面的按钮的回调函数
	// void 函数名(CCObjec pSender);
	void ChangeSceneMenu(CCObject* pSender);
	void RebackMenu(CCObject* pSender);
	//重写父类的update方法
	//参数:float date
	/*void update(float date)override;

	void Mydate(float date);*/
private:
	
	CCMenuItemSprite* Reback;			//跳转到ToDesert的按钮
	CCSprite*        NoTouchReback;   //ToDesert没有按下的状态
	CCSprite*        OnTouchReback;   //ToDesert按下的状态
	CCMenu*			 IconReback;


};