#include "LoadingScene.h"
#include "GameMenu.h"
#include "SetScene.h"
#include <assert.h>
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// ��������
CCScene* SetScene::scene()
{
	assert(true);
	//����һ������
	CCScene* pscene =CCScene::create();
	//����һ����ǰ���͵Ĳ�
	SetScene* player = SetScene::create();
	//������Ϊ�ӽڵ���ӵ�����
	pscene->addChild(player);
	//������ָ�뷵��
	return pscene;
}
//��ʼ��
bool SetScene::init()
{


	//��������ʼ��ʧ�� ����false
	if ( !CCLayer::init() )
	{
		return false;
	}

	/*CCSprite* First_ = CCSprite::create("game.png");
	First_->setPosition(ccp(1334/2,750/2));
	this->addChild(First_);*/

	NoTouchToHello = CCSprite::create("reback.png");
	OnTouchToHello = CCSprite::create("game_blink.png");
	ToHello = CCMenuItemSprite::create(
		NoTouchToHello,
		NoTouchToHello,
		this,
		menu_selector(SetScene::ChangeSceneMenu));
	ToHello->setAnchorPoint(ccp(0,1));
	ToHello->setScale(0.5);
	ToHello->setPosition(ccp(0,750));
	ToHello->setTag(1);

	//NoTouchCloseMusic = CCSprite::create("closemusic.png");
	//OnTouchCloseMusic = CCSprite::create("game_blink.png");
	//CloseMusic = CCMenuItemSprite::create(
	//	NoTouchCloseMusic,
	//	OnTouchCloseMusic,
	//	this,
	//	menu_selector(HelloWorld::ChangeSceneMenu)); 
	//CloseMusic->setAnchorPoint(ccp(1,1));
	//CloseMusic->setScale(0.75);
	//CloseMusic->setPosition(ccp(1334,750));
	//CloseMusic->setTag(2);


	

	ChangeScene_A = CCMenu::create(ToHello, NULL);
	ChangeScene_A->setPosition(CCPointZero);
	this->addChild(ChangeScene_A);

	//����:Ѳ��
	//1 ʹ�ö���
	//2 ʹ�õ�����:Ĭ�ϵ�����:������ ÿһ֡������õ�һ������
	
	// 1���һ������
	Bug = CCSprite::create("PlayerUp_0.png");
	Bug->setPosition(ccp(1334/2,750/2));
	this->addChild(Bug);
	/*Bug->runAction(rep);*/
	// 2����һ������
	CCAnimation* m_animation = CCAnimation::create();
	// 3�������Ķ������֡
	m_animation->addSpriteFrameWithFileName("PlayerUp_0.png");
	m_animation->addSpriteFrameWithFileName("PlayerUp_1.png");
	m_animation->addSpriteFrameWithFileName("PlayerUp_2.png");
	m_animation->addSpriteFrameWithFileName("PlayerUp_3.png");
	//m_animation->addSpriteFrameWithFileName("PlayerUp_4.png");
	//m_animation->addSpriteFrameWithFileName("PlayerUp_5.png");
	/*m_animation->addSpriteFrameWithFileName("PlayerRight_06.png");*/
	// 4.1 ���ʱ�� ���Ŵ���: ����(�޷�������)�޸���
	
	m_animation->setDelayPerUnit(0.2f);
	m_animation->setLoops(-1); //����ʱΪ�����ظ� �������
	// 5������ת���ɶ���
	CCAnimate* m_animate = CCAnimate::create(m_animation);
	// 6����ִ�ж���(����)
	Bug->runAction(m_animate);

	//����Ĭ�ϵ�����
	//ֻ��Ҫ����һ��:д��init()
	/*scheduleUpdate();*/
	schedule(
		schedule_selector(SetScene::MyUpdate), //��Ӧ����
		1.0f, //ÿ�ε��õ�ʱ����
		9,    //����  ��ʵ����Ϊ6��
		1);   //�״ε�����ʱ
	return true;
}
void SetScene::ChangeSceneMenu(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	CCMenuItemSprite* lev = (CCMenuItemSprite*)pSender;

	// 1 �ҵ���
	CCDirector* director = CCDirector::sharedDirector();
	// 2 ��Ҫ��ת���ĳ���
	CCScene* ToGameMenu = GameMenu::scene();
	// �л�Ч�� ���� 1��תʱ�� 2�л�Ŀ�곡��
	// �л���ʽ* ָ���� = �л���ʽ::create(ʱ��,Ŀ�곡����ָ��)
	CCTransitionRotoZoom* ptran = CCTransitionRotoZoom::create(1.0f,ToGameMenu);

	
	// 3 ����ָ����ת
	//lev->getTag(); //��ñ�� ֪����˭������
	switch(lev->getTag())
	{
	case 1:
		director->replaceScene(ptran);
		break;
	case 2:
		/*SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();*/
		break;
	default:
		break;
	}
}

//void Scene1::update(float date)
//{
//	//дѲ���߼�
//	float speed = 100;
//
//		Bug->setPositionX(Bug->getPositionX()-speed*date);
//	
//	
//}
void SetScene::MyUpdate(float date)
{
	bool turn = true;
	SimpleAudioEngine::sharedEngine()->playEffect("walk.mp3");
	if (turn)
	{
		if (Bug->getPositionX() > 100)
		{
		
		Bug->setPositionX(Bug->getPositionX()-200*date);}
		else turn = false;
	}
	else if (!turn)
	{
		Bug->setPositionX(Bug->getPositionX()+200*date);
	}
	
}