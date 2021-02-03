#pragma once    //保证后面的代码只执行一次
#include "cocos2d.h"
#include "GameMap.h"
#include "Player.h"
#include "textScrollEffects.h"
using namespace cocos2d;
class Playscene: public cocos2d::CCLayerColor
{
public:
	// 创建场景
	static cocos2d::CCScene* scene();
	// 初始化
	virtual bool init();
	// 创建层
	CREATE_FUNC(Playscene);
	// 默认调度器
	void update(float dt);
	
	//检测碰撞
	//参数:需要被检测的对象 节点*
	bool playerCOllision(CCNode* obj);

	void Button(CCObject* pSender);
	//重写父类的update方法
	//参数:float date
	/*void update(float date)override;

	void Mydate(float date);*/
	virtual void registerWithTouchDispatcher(void);
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
private:
	Player*			 player; 
	CCActionInterval* createRFAnimation(const char *frameName, int frameNum, float frameTime);
	CCMenuItemSprite* Reback;			//跳转到ToDesert的按钮
	CCSprite*        NoTouchReback;   //ToDesert没有按下的状态
	CCSprite*        OnTouchReback;   //ToDesert按下的状态

	CCMenuItemSprite* ReStart;			//跳转到ToDesert的按钮
	CCSprite*        NoTouchReStart;   //ToDesert没有按下的状态
	CCSprite*        OnTouchReStart;

	CCMenuItemSprite* ToNext;			
	CCSprite*        NoTouchToNext;   
	CCSprite*        OnTouchToNext;

	CCMenuItemSprite* ReStart1;			//跳转到ToDesert的按钮
	CCSprite*        NoTouchReStart1;   //ToDesert没有按下的状态
	CCSprite*        OnTouchReStart1;


	CCMenu*			 IconMenu;


	cocos2d::CCSprite* m_player;

	int				m_iBoxCount;  //获取到的宝箱数量

	CCLabelAtlas*	m_boxCountAtlas; //

	CCSprite*	    spBoxState;

	CCSize			 visibleSize;  //可视区域大小
	CCSprite*		 GameBg;	   //游戏界面背景
	CCSprite*        m_key;		   //钥匙精灵
	CCSprite*		 m_exit;	   //出口精灵
	CCSprite*		 m_box[3];	   //宝箱数组
	CCSprite*		 m_trap[20];    //陷阱数组
	CCSprite*		 m_Monster[10]; //怪物数组
	CCSprite*		 m_Transfer[20][20];//传送门数组
	bool			 isgetkey;		//是否获得钥匙
	GameMap*		 p_Map;		   //游戏地图
	  //主角精灵
	CCPoint			 playerPos;	   //主角坐标


	void GameInitObject0();		   //初始化英雄
	void GameInitObject1();		   //初始化钥匙和门
	void GameInitObject2();		   //初始化宝箱	
	void GameInitObject3();		   //初始化陷阱	 
	void GameInitObject4();	       //初始化怪物
	void GameInitObject5();		   //初始化传送门
	/*
	添加钥匙 添加出口 拾取钥匙
	1 添加对象  (初始化钥匙和门)
		①添加一个对象层object1
		②添加钥匙 是一个对象key 70*70像素
		③添加出口 是一个对象exit 70*70像素
	2 检测主角和钥匙之间的碰撞 (写一个通用的方法)
		①检测方法实现
		②不断检测是否碰撞 ==> 在默认调度器中开启检测方法(帧调度器)
		③开启默认调度器
		④检测碰撞
	*/

	/*
	粒子系统:
	下雨 下雪
	*/

	/*
	游戏数据处理:
	1 宝箱,钥匙,血量,护盾...
	  
	2 
	*/
};