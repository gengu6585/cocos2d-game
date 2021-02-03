#include "LoadingScene.h"
#include "GameMenu.h"
#include "Scene2.h"
#include "SimpleAudioEngine.h"
#include "Icon.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// ��������
CCScene* Scene2::scene()
{
	//����һ������
	CCScene* pscene =CCScene::create();
	//����һ����ǰ���͵Ĳ�
	Scene2* player = Scene2::create();
	//������Ϊ�ӽڵ���ӵ�����
	pscene->addChild(player);
	//������ָ�뷵��
	return pscene;
}
//��ʼ��
bool Scene2::init()
{


	//��������ʼ��ʧ�� ����false
	if (! CCLayerColor::initWithColor(ccc4(0, 0, 0, 255))  )
	{
		return false;
	}


	
	NoTouchReback = CCSprite::create("reback1.png");
	OnTouchReback = CCSprite::create("game_blink.png");
	Reback = CCMenuItemSprite::create(
		NoTouchReback,
		OnTouchReback,
		this,
		menu_selector(Scene2::RebackMenu)); 
	Reback->setAnchorPoint(ccp(0,1));
	Reback->setScale(0.3f);
	Reback->setPosition(ccp(0,750));
	Reback->setTag(1);
	IconReback = CCMenu::create(Reback,NULL);
	IconReback->setPosition(CCPointZero);
	this->addChild(IconReback);
	textScrollEffects::create(this,ccp(1334/2,0),"backgroundstory.txt");



	return true;
}
void Scene2::RebackMenu(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	CCMenuItemSprite* lev = (CCMenuItemSprite*)pSender;

	// 1 �ҵ���
	CCDirector* director = CCDirector::sharedDirector();
	// 2 ��Ҫ��ת���ĳ���
	CCScene* ToGameMenu = GameMenu::scene();
	// �л�Ч�� ���� 1��תʱ�� 2�л�Ŀ�곡��
	// �л���ʽ* ָ���� = �л���ʽ::create(ʱ��,Ŀ�곡����ָ��)
	CCTransitionPageTurn* ptran = CCTransitionPageTurn::create(1.0f,ToGameMenu,true);




	// 3 ����ָ����ת
	//lev->getTag(); //��ñ�� ֪����˭������
	switch(lev->getTag())
	{
	case 1:
		director->replaceScene(ptran);
		break;
	default:
		break;
	}
}
