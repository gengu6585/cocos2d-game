#pragma once    //保证后面的代码只执行一次
#include "cocos2d.h"
#include "GameMap.h"
using namespace cocos2d;
class Icon: public cocos2d::CCLayer 
{
public:

	// 创建场景
	static cocos2d::CCScene* scene();

	// 初始化
	virtual bool init();


	// 创建层
	CREATE_FUNC(Icon);

	void ChangeSceneMenu_B(CCObject* pSender);
	//重写父类的update方法
	//参数:float date
	/*void update(float date)override;

	void Mydate(float date);*/
private:
	CCSize			 visibleSize;  //可视区域大小
	CCSprite*		 GameBg;	   //游戏界面背景

	GameMap*		 Grass_Map;		   //游戏地图
	/*Player*			 player;*/	   //主角精灵
	CCPoint			 playerPos;	   //主角坐标

	CCMenuItemSprite* ToGrass;			//跳转到ToGrass的按钮
	CCSprite*        NoTouchToGrass;   //ToGrass没有按下的状态
	CCSprite*        OnTouchToGrass;   //ToGrass按下的状态

	CCMenuItemSprite* ToDesert;			//跳转到ToDesert的按钮
	CCSprite*        NoTouchToDesert;   //ToDesert没有按下的状态
	CCSprite*        OnTouchToDesert;   //ToDesert按下的状态

	CCMenuItemSprite* Reback;			//跳转到Reback的按钮
	CCSprite*        NoTouchReback;   //Reback没有按下的状态
	CCSprite*        OnTouchReback;   //Reback按下的状态

	CCMenuItemSprite* CloseMusic;			//跳转到CloseMusic的按钮
	CCSprite*        NoTouchCloseMusic;   //CloseMusic没有按下的状态
	CCSprite*        OnTouchCloseMusic;   //CloseMusic按下的状态

	CCMenuItemSprite* ToSnow;			//跳转到ToSnow的按钮
	CCSprite*        NoTouchToSnow;   //ToSnow没有按下的状态
	CCSprite*        OnTouchToSnow;   //ToSnow按下的状态

	CCMenu*			 IconMenu;

};