#pragma once    //��֤����Ĵ���ִֻ��һ��
#include "cocos2d.h"
using namespace cocos2d;
class LoadingScene: public cocos2d::CCLayer 
{
public:
	
	// ��������
	static cocos2d::CCScene* scene();
	
	// ��ʼ��
	virtual bool init();
	

	// ������
	CREATE_FUNC(LoadingScene);

	//�л���Hello����İ�ť�Ļص�����
	// void ������(CCObject* pSender);
	void seqChangeScene();
	void ChangeSceneMenu1(CCObject* pSender);
private:
	CCMenuItemImage* ToHello;
	
	CCMenuItemSprite* JunpOver;			//������ť
	CCSprite*        NoTouchJunpOver;   //ToScene1û�а��µ�״̬
	CCSprite*        OnTouchJunpOver;   //ToScene1���µ�״̬
	CCMenu*			 pMenu;
};

