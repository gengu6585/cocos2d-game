#pragma once    //��֤����Ĵ���ִֻ��һ��
#include "cocos2d.h"
using namespace cocos2d;
class SetScene: public cocos2d::CCLayer 
{
public:

	// ��������
	static cocos2d::CCScene* scene();

	// ��ʼ��
	virtual bool init();


	// ������
	CREATE_FUNC(SetScene);

	//�л���Hello����İ�ť�Ļص�����
	// void ������(CCObjec pSender);
	void ChangeSceneMenu(CCObject* pSender);
	//��д�����update����
	//����:float date
	/*void update(float date)override;*/

	void MyUpdate(float date);
private:
	CCMenuItemSprite* ToHello;			//��ת��Scene1�İ�ť
	CCSprite*        NoTouchToHello;   //ToScene1û�а��µ�״̬
	CCSprite*        OnTouchToHello;   //ToScene1���µ�״̬
	CCMenuItemSprite* CloseMusic;			//��ת��ToDesert�İ�ť
	CCSprite*        NoTouchCloseMusic;   //ToDesertû�а��µ�״̬
	CCSprite*        OnTouchCloseMusic;   //ToDesert���µ�״̬

	cocos2d::CCSprite* Bug;

	

	CCMenu*			 ChangeScene_A;
	

};
/*
������:
1 Ĭ�ϵ�����:����֮��ÿһ֡�������һ��

2 �Զ��������:���Կ��Ƶ��õĴ�����ʱ����
	����һ�� д��һ��������
		����ͷ�ļ���������.h
		void ��������(float date);
		����Դ�ļ�ʵ���������.cpp
		void ����::��������(float date)
		{
			������:
		}
	������� ʹ�õ�����
3 ���ε�����������֮��ֻ����һ��
	
*/

/*
�����Ƶ�ļ�:����Ƶ����
1 ��������
	���� ����:�����ļ�·��,�Ƿ��ظ�����
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/MenuMusic.mp3",true)
	��ͣ
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic()
	ֹͣ
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic()
	�ָ�
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic()
	����
	��������
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.8f);
2 ��Ч
	SimpleAudioEngine::sharedEngine()->playEffect("");


*/