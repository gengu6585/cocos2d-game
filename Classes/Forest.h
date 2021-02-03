#pragma once    //��֤����Ĵ���ִֻ��һ��
#include "cocos2d.h"
#include "GameMap.h"
#include "Player.h"
using namespace cocos2d;
class forest: public cocos2d::CCLayerColor 
{
public:

	// ��������
	static cocos2d::CCScene* scene();
	// ��ʼ��
	virtual bool init();
	// ������




	CREATE_FUNC(forest);
	// Ĭ�ϵ�����
	void update(float dt);
	
	//�����ײ
	//����:��Ҫ�����Ķ��� �ڵ�*
	bool playerCOllision1(CCNode* obj);

	void Button(CCObject* pSender);
	//��д�����update����
	//����:float date
	/*void update(float date)override;

	void Mydate(float date);*/
	virtual void registerWithTouchDispatcher(void);
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
private:
	Player*			 player; 
	CCActionInterval* createRFAnimation2(const char *frameName, int frameNum, float frameTime);
	CCMenuItemSprite* Reback;			//��ת��ToDesert�İ�ť
	CCSprite*        NoTouchReback;   //ToDesertû�а��µ�״̬
	CCSprite*        OnTouchReback;   //ToDesert���µ�״̬

	CCMenuItemSprite* ReStart;			//��ת��ToDesert�İ�ť
	CCSprite*        NoTouchReStart;   //ToDesertû�а��µ�״̬
	CCSprite*        OnTouchReStart;

	CCMenuItemSprite* ToNext;			
	CCSprite*        NoTouchToNext;   
	CCSprite*        OnTouchToNext;

	CCMenuItemSprite* ReStart1;			//��ת��ToDesert�İ�ť
	CCSprite*        NoTouchReStart1;   //ToDesertû�а��µ�״̬
	CCSprite*        OnTouchReStart1;

	CCMenu*			 IconMenu;


	cocos2d::CCSprite* m_player;

	int				m_iBoxCount;  //��ȡ���ı�������

	CCLabelAtlas*	m_boxCountAtlas; //

	CCSprite*	    spBoxState;

	CCSize			 visibleSize;  //���������С
	CCSprite*		 GameBg;	   //��Ϸ���汳��
	CCSprite*        m_key;		   //Կ�׾���
	CCSprite*		 m_exit;	   //���ھ���
	CCSprite*		 m_box[3];	   //��������
	CCSprite*		 m_trap[20];    //��������
	CCSprite*		 m_Monster[10]; //��������
	CCSprite*		 m_Transfer[20][20];//����������
	bool			 isgetkey;		//�Ƿ���Կ��
	GameMap*		 p_Map;		   //��Ϸ��ͼ
	//���Ǿ���
	CCPoint			 playerPos;	   //��������


	void GameInitObject_0();		   //��ʼ��Ӣ��
	void GameInitObject_1();		   //��ʼ��Կ�׺���
	void GameInitObject_2();		   //��ʼ������	
	void GameInitObject_3();		   //��ʼ������	 
	void GameInitObject_4();	       //��ʼ������
	void GameInitObject_5();		   //��ʼ��������



};