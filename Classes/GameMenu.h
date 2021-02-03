#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;
USING_NS_CC;

class GameMenu : public cocos2d::CCLayerColor  //helloworld �ǲ�Ķ���
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);


    
    // implement the "static node()" method manually
	// �ֶ�ʵ��"static node()"����
	// ����һ����
    CREATE_FUNC(GameMenu);
	void ChangeSceneMenu(CCObject* pSender);
	/*void seqChangeScene();*/
private:
	

	CCMenuItemSprite* ToScene1;			//��ת��Scene1�İ�ť
	CCSprite*        NoTouchToScene1;   //ToScene1û�а��µ�״̬
	CCSprite*        OnTouchToScene1;   //ToScene1���µ�״̬
	

	CCMenuItemSprite* ToHello_;			//��ת��ToHello_�İ�ť
	CCSprite*        NoTouchToHello_;   //ToHello_û�а��µ�״̬
	CCSprite*        OnTouchToHello_;   //ToHello_���µ�״̬

	CCMenuItemSprite* ToLoading;			//��ת��ToLoading�İ�ť
	CCSprite*        NoTouchToLoading;   //ToLoadingû�а��µ�״̬
	CCSprite*        OnTouchToLoading;   //ToLoading���µ�״̬

	CCMenuItemSprite* ToLevel;			//��ת��ToLevel�İ�ť
	CCSprite*        NoTouchToLevel;   //ToLevelû�а��µ�״̬
	CCSprite*        OnTouchToLevel;   //ToLevel���µ�״̬

	CCMenuItemSprite* ToQuit;			//��ת��ToSet�İ�ť
	CCSprite*        NoTouchToQuit;   //ToSetû�а��µ�״̬
	CCSprite*        OnTouchToQuit;   //ToSet���µ�״̬

	CCMenuItemSprite* Closebutton;			//��ת��Closebutton�İ�ť
	CCSprite*        NoTouchClosebutton;   //Closebuttonû�а��µ�״̬
	CCSprite*        OnTouchClosebutton;   //Closebutton���µ�״̬

	CCMenuItemSprite* StartGame;			//��ת��Closebutton�İ�ť
	CCSprite*        NoTouchStartGame;   //Closebuttonû�а��µ�״̬
	CCSprite*        OnTouchStartGame;   //Closebutton���µ�״̬


	CCMenuItemSprite*	BackGround;			//��ת��Closebutton�İ�ť
	CCSprite*        NoTouchBackGround;   //Closebuttonû�а��µ�״̬
	CCSprite*        OnTouchBackGround;   //Closebutton���µ�״̬


	CCMenuItemSprite* CloseMusic;			//��ת��ToDesert�İ�ť
	CCSprite*        NoTouchCloseMusic;   //ToDesertû�а��µ�״̬
	CCSprite*        OnTouchCloseMusic;   //ToDesert���µ�״̬


	CCMenu*			 ChangeScene_;		//��ť�˵�


};

#endif // __HELLOWORLD_SCENE_H__
