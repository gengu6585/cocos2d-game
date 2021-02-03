#pragma once    //��֤����Ĵ���ִֻ��һ��
#include "cocos2d.h"
#include "GameMap.h"
using namespace cocos2d;
class Icon: public cocos2d::CCLayer 
{
public:

	// ��������
	static cocos2d::CCScene* scene();

	// ��ʼ��
	virtual bool init();


	// ������
	CREATE_FUNC(Icon);

	void ChangeSceneMenu_B(CCObject* pSender);
	//��д�����update����
	//����:float date
	/*void update(float date)override;

	void Mydate(float date);*/
private:
	CCSize			 visibleSize;  //���������С
	CCSprite*		 GameBg;	   //��Ϸ���汳��

	GameMap*		 Grass_Map;		   //��Ϸ��ͼ
	/*Player*			 player;*/	   //���Ǿ���
	CCPoint			 playerPos;	   //��������

	CCMenuItemSprite* ToGrass;			//��ת��ToGrass�İ�ť
	CCSprite*        NoTouchToGrass;   //ToGrassû�а��µ�״̬
	CCSprite*        OnTouchToGrass;   //ToGrass���µ�״̬

	CCMenuItemSprite* ToDesert;			//��ת��ToDesert�İ�ť
	CCSprite*        NoTouchToDesert;   //ToDesertû�а��µ�״̬
	CCSprite*        OnTouchToDesert;   //ToDesert���µ�״̬

	CCMenuItemSprite* Reback;			//��ת��Reback�İ�ť
	CCSprite*        NoTouchReback;   //Rebackû�а��µ�״̬
	CCSprite*        OnTouchReback;   //Reback���µ�״̬

	CCMenuItemSprite* CloseMusic;			//��ת��CloseMusic�İ�ť
	CCSprite*        NoTouchCloseMusic;   //CloseMusicû�а��µ�״̬
	CCSprite*        OnTouchCloseMusic;   //CloseMusic���µ�״̬

	CCMenuItemSprite* ToSnow;			//��ת��ToSnow�İ�ť
	CCSprite*        NoTouchToSnow;   //ToSnowû�а��µ�״̬
	CCSprite*        OnTouchToSnow;   //ToSnow���µ�״̬

	CCMenu*			 IconMenu;

};