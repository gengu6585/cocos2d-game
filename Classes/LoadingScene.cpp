#include "LoadingScene.h"
#include "GameMenu.h"
using namespace cocos2d;
#include "SimpleAudioEngine.h"
#include "GameData.h"
using namespace CocosDenshion;
USING_NS_CC;
// ��������

CCScene* LoadingScene::scene()
{
	//����һ������
	CCScene* pscene =CCScene::create();
	//����һ����ǰ���͵Ĳ�
	LoadingScene* player = LoadingScene::create();
	//������Ϊ�ӽڵ���ӵ�����
	pscene->addChild(player);
	//������ָ�뷵��
	return pscene;
}
//��ʼ��
 bool LoadingScene::init()
{

	
	//��������ʼ��ʧ�� ����false
	if ( !CCLayer::init() )
	{
		return false;
	}

	GameData::returnDefault();

	/*

	�����￪ʼ��Ӵ���
	*/
	//����:��Ӿ���
	CCSprite* pLogo = CCSprite::create("game_LOGO.png");
	pLogo->setPosition(ccp(1334/2,750/2));
	//��������Ϊ�ӽڵ���ӵ���
	this->addChild(pLogo); //this ָ���ǲ㱾��
	
	CCSprite* pLogo1 = CCSprite::create("bug.jpg");
	pLogo1->setPosition(ccp(1334/2,750/2));
	this->addChild(pLogo1);

	pLogo1->setOpacity(0);
	CCFadeTo* fadeIn = CCFadeTo::create(2,255);
	CCFadeTo* fadeOut= CCFadeTo::create(2,0);
	pLogo1->runAction(fadeOut);
	CCSequence* Seq = CCSequence::create(fadeIn,fadeOut,NULL);
	pLogo1->runAction(Seq);
	


	/*       
		�л�����:
		1 �����л�: �����ť
		2 �����л�: �߼�����

	*/
	/*
		������ť��Ӳ���
		1 �����˵���ť
		2 ����λ��
		3 �����˵�
		4 ���˵�����λ��
		5 �Ѳ˵���Ϊ�ӽڵ���ӵ���
	*/
	// ����һ���л���HelloWorld����İ�ť
	// ����: 1û�е��ʱ��״̬ͼ 2���ʱ��״̬ͼ 3this 4�ص�����
	// �ص�����:��ť���»�ִ�еĺ���
	//1 �����˵���ť


	NoTouchJunpOver = CCSprite::create("JumpOver.png");
	OnTouchJunpOver = CCSprite::create("game_blink,png");
	JunpOver = CCMenuItemSprite::create(
		NoTouchJunpOver,
		OnTouchJunpOver,
		this,
		menu_selector(LoadingScene::ChangeSceneMenu1));
	JunpOver->setAnchorPoint(ccp(1,1));

	JunpOver->setPosition(ccp(1334,750));

	 pMenu = CCMenu::create(JunpOver, NULL);
	pMenu->setPosition(CCPointZero);
	// 6 ����ӽڵ�
	this->addChild(pMenu);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("wengweng.mp3",true);
	CCSprite* pSprite = CCSprite::create("fly.png");
	pSprite->setPosition(ccp(1500,1500));
	pSprite->setScale(1.3f);
	pSprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(pSprite);
	CCMoveTo* Moveto1 = CCMoveTo::create(0.5f,ccp(2000,800));
	CCMoveTo* Moveto2 = CCMoveTo::create(0.5f,ccp(2500,700));
	CCMoveTo* Moveto3 = CCMoveTo::create(0.5f,ccp(2500,800));
	CCMoveTo* Moveto4 = CCMoveTo::create(0.5f,ccp(2500,900));
	CCMoveTo* Moveto5 = CCMoveTo::create(0.2f,ccp(2000,1000));
	CCMoveTo* Moveto6 = CCMoveTo::create(0.2f,ccp(500,700));
	CCMoveTo* Moveto7 = CCMoveTo::create(0.2f,ccp(240,40));
	CCMoveTo* Moveto8 = CCMoveTo::create(0.2f,ccp(-500,800));
	CCMoveTo* Moveto9 = CCMoveTo::create(0.2f,ccp(800,10));
	CCMoveTo* Moveto10 = CCMoveTo::create(0.2f,ccp(1200,400));
	CCMoveTo* Moveto11 = CCMoveTo::create(0.2f,ccp(300,870));
	CCMoveTo* Moveto12 = CCMoveTo::create(0.2f,ccp(0,395));
	CCMoveTo* Moveto13 = CCMoveTo::create(0.2f,ccp(342,920));
	CCMoveTo* Moveto14 = CCMoveTo::create(0.2f,ccp(22,402));
	CCMoveTo* Moveto15 = CCMoveTo::create(0.2f,ccp(675,395));
	//CCMoveTo* Moveto16 = CCMoveTo::create(0.33f,ccp(444,444));
	//CCMoveTo* Moveto17 = CCMoveTo::create(0.33f,ccp(222,750));
	//CCMoveTo* Moveto18 = CCMoveTo::create(0.33f,ccp(675,395));
	CCSequence* seq   = CCSequence::create(Moveto1,Moveto2,Moveto3,Moveto4,Moveto5,
		Moveto6,Moveto7,Moveto8,Moveto9,Moveto10,Moveto11,Moveto12,Moveto13,Moveto14,
																   Moveto15,/*Moveto16,Moveto17,Moveto18,*/NULL);
	/*start->runAction(seq);*/
	
	// ����һ����ҫ
	// ����һ�����ж��� ����ʱ ��MoveTo ���л�
	/*CCSequence* seq = CCSequence::create(MoveTo1,MoveTo2,MoveTo3,MoveTo4,NULL);*/
	CCSequence* seqAct = CCSequence::create(

	seq,
	//��ص�����
	CCCallFunc::create(this,callfunc_selector(LoadingScene::seqChangeScene)),NULL);
	
	pSprite->runAction(seqAct);


	
	return true;
}

 void LoadingScene::seqChangeScene()
 {
	 SimpleAudioEngine::sharedEngine()->playEffect("ohyeah.mp3");
	 SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	 // 1 �������ļ�
	 // 1 �ҵ���
	 CCDirector* director1 = CCDirector::sharedDirector();
	 // 2 ��Ҫ��ת���ĳ���
	 CCScene* Loadingscene = GameMenu::scene();
	 // �л�Ч�� ���� 1��תʱ�� 2�л�Ŀ�곡��
	 CCTransitionFade* ptran1 = CCTransitionFade::create(2.0f,Loadingscene);
	 // 3 ����ָ����ת
	 director1->replaceScene(ptran1);
 }
  void LoadingScene::ChangeSceneMenu1(CCObject* pSender)
  {
	  SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	  SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	  // 1 �ҵ���
	  CCDirector* director1 = CCDirector::sharedDirector();
	  // 2 ��Ҫ��ת���ĳ���
	  CCScene* Loadingscene = GameMenu::scene();
	  // �л�Ч�� ���� 1��תʱ�� 2�л�Ŀ�곡��
	  CCTransitionFade* ptran1 = CCTransitionFade::create(2.0f,Loadingscene);
	  // 3 ����ָ����ת
	  director1->replaceScene(ptran1);

  }
 



