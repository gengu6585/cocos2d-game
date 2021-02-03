#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;
USING_NS_CC;

class GameMenu : public cocos2d::CCLayerColor  //helloworld 是层的儿子
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);


    
    // implement the "static node()" method manually
	// 手动实现"static node()"方法
	// 创建一个层
    CREATE_FUNC(GameMenu);
	void ChangeSceneMenu(CCObject* pSender);
	/*void seqChangeScene();*/
private:
	

	CCMenuItemSprite* ToScene1;			//跳转到Scene1的按钮
	CCSprite*        NoTouchToScene1;   //ToScene1没有按下的状态
	CCSprite*        OnTouchToScene1;   //ToScene1按下的状态
	

	CCMenuItemSprite* ToHello_;			//跳转到ToHello_的按钮
	CCSprite*        NoTouchToHello_;   //ToHello_没有按下的状态
	CCSprite*        OnTouchToHello_;   //ToHello_按下的状态

	CCMenuItemSprite* ToLoading;			//跳转到ToLoading的按钮
	CCSprite*        NoTouchToLoading;   //ToLoading没有按下的状态
	CCSprite*        OnTouchToLoading;   //ToLoading按下的状态

	CCMenuItemSprite* ToLevel;			//跳转到ToLevel的按钮
	CCSprite*        NoTouchToLevel;   //ToLevel没有按下的状态
	CCSprite*        OnTouchToLevel;   //ToLevel按下的状态

	CCMenuItemSprite* ToQuit;			//跳转到ToSet的按钮
	CCSprite*        NoTouchToQuit;   //ToSet没有按下的状态
	CCSprite*        OnTouchToQuit;   //ToSet按下的状态

	CCMenuItemSprite* Closebutton;			//跳转到Closebutton的按钮
	CCSprite*        NoTouchClosebutton;   //Closebutton没有按下的状态
	CCSprite*        OnTouchClosebutton;   //Closebutton按下的状态

	CCMenuItemSprite* StartGame;			//跳转到Closebutton的按钮
	CCSprite*        NoTouchStartGame;   //Closebutton没有按下的状态
	CCSprite*        OnTouchStartGame;   //Closebutton按下的状态


	CCMenuItemSprite*	BackGround;			//跳转到Closebutton的按钮
	CCSprite*        NoTouchBackGround;   //Closebutton没有按下的状态
	CCSprite*        OnTouchBackGround;   //Closebutton按下的状态


	CCMenuItemSprite* CloseMusic;			//跳转到ToDesert的按钮
	CCSprite*        NoTouchCloseMusic;   //ToDesert没有按下的状态
	CCSprite*        OnTouchCloseMusic;   //ToDesert按下的状态


	CCMenu*			 ChangeScene_;		//按钮菜单


};

#endif // __HELLOWORLD_SCENE_H__
