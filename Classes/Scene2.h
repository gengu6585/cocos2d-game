#pragma once    //��֤����Ĵ���ִֻ��һ��
#include "cocos2d.h"
#include "textScrollEffects.h"
using namespace cocos2d;
class Scene2: public cocos2d::CCLayerColor 
{
public:

	// ��������
	static cocos2d::CCScene* scene();

	// ��ʼ��
	virtual bool init();


	// ������
	CREATE_FUNC(Scene2);

	//�л���Hello����İ�ť�Ļص�����
	// void ������(CCObjec pSender);
	void ChangeSceneMenu(CCObject* pSender);
	void RebackMenu(CCObject* pSender);
	//��д�����update����
	//����:float date
	/*void update(float date)override;

	void Mydate(float date);*/
private:
	
	CCMenuItemSprite* Reback;			//��ת��ToDesert�İ�ť
	CCSprite*        NoTouchReback;   //ToDesertû�а��µ�״̬
	CCSprite*        OnTouchReback;   //ToDesert���µ�״̬
	CCMenu*			 IconReback;


};