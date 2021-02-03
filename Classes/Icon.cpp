#include "Icon.h"
#include "SimpleAudioEngine.h"
#include "Playscene.h"
#include "GameMenu.h"
#include "DesertScene.h"
#include "LvChoiceLayer.h"
#include "GameData.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// ��������
CCScene* Icon::scene()
{

	//����һ������
	CCScene* pscene =CCScene::create();
	//����һ����ǰ���͵Ĳ�
	Icon* player = Icon::create();
	//������Ϊ�ӽڵ���ӵ�����
	pscene->addChild(player);
	//������ָ�뷵��
	return pscene;
}
//��ʼ��
bool Icon::init()
{


	//��������ʼ��ʧ�� ����false
	if ( !CCLayer::init() )
	{
		return false;
	}
	/*visibleSize = CCDirector::sharedDirector()->getVisibleSize();
*/
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(3.0f);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game04.mp3");

	CCSprite* bgground = CCSprite::create("bg.png");
	bgground->setPosition(ccp(1334/2,750/2));
	bgground->setScaleX(1.3f);
	bgground->setScaleY(0.74f);
	this->addChild(bgground);
	

	NoTouchToGrass = CCSprite::create("choicebg/choicebg2.png");
	OnTouchToGrass = CCSprite::create("game_blink.png");
	ToGrass = CCMenuItemSprite::create(
		NoTouchToGrass,
		OnTouchToGrass,
		this,
		menu_selector(Icon::ChangeSceneMenu_B)); 
	ToGrass->setAnchorPoint(ccp(1,0));
	ToGrass->setScale(0.3f);
	ToGrass->setPosition(ccp(350,375));
	ToGrass->setTag(1);

	NoTouchToDesert = CCSprite::create("choicebg/choicebg1.png");
	OnTouchToDesert = CCSprite::create("game_blink.png");
	ToDesert = CCMenuItemSprite::create(
		NoTouchToDesert,
		OnTouchToDesert,
		this,
		menu_selector(Icon::ChangeSceneMenu_B)); 
	ToDesert->setAnchorPoint(ccp(1,0));
	ToDesert->setScale(0.3f);
	ToDesert->setPosition(ccp(800,375));
	ToDesert->setTag(2);

	NoTouchToSnow = CCSprite::create("choicebg/choicebg3.png");
	OnTouchToSnow = CCSprite::create("game_blink.png");
	ToSnow = CCMenuItemSprite::create(
		NoTouchToSnow,
		OnTouchToSnow,
		this,
		menu_selector(Icon::ChangeSceneMenu_B)); 
	ToSnow->setAnchorPoint(ccp(1,0));
	ToSnow->setScale(0.3f);
	ToSnow->setPosition(ccp(1334-150,375));
	ToSnow->setTag(5);

	NoTouchReback = CCSprite::create("reback1.png");
	OnTouchReback = CCSprite::create("game_blink.png");
	Reback = CCMenuItemSprite::create(
		NoTouchReback,
		OnTouchReback,
		this,
		menu_selector(Icon::ChangeSceneMenu_B)); 
	Reback->setAnchorPoint(ccp(0,1));
	Reback->setScale(0.3f);
	Reback->setPosition(ccp(0,750));
	Reback->setTag(3);

	NoTouchCloseMusic = CCSprite::create("closemusic.png");
	OnTouchCloseMusic = CCSprite::create("game_blink.png");
	CloseMusic = CCMenuItemSprite::create(
		NoTouchCloseMusic,
		OnTouchCloseMusic,
		this,
		menu_selector(Icon::ChangeSceneMenu_B)); 
	CloseMusic->setAnchorPoint(ccp(1,1));
	CloseMusic->setScale(0.75);
	CloseMusic->setPosition(ccp(1334,750));
	CloseMusic->setTag(4);

	IconMenu = CCMenu::create(ToGrass,ToDesert,Reback,CloseMusic,ToSnow,NULL);
	IconMenu->setPosition(CCPointZero);
	this->addChild(IconMenu);
	
	return true;
}
void Icon::ChangeSceneMenu_B(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	CCMenuItemSprite* lev = (CCMenuItemSprite*)pSender;

	// 1 �ҵ���
	CCDirector* director = CCDirector::sharedDirector();
	// 2 ��Ҫ��ת���ĳ���
	

	
	//�ظ��ĳ���
	


	// 3 ����ָ����ת
	//lev->getTag(); //��ñ�� ֪����˭������
	switch(lev->getTag())
	{
	case 1:
		GameData::s_iCurBigLevel = 1;
		director->replaceScene(CCTransitionFadeTR ::create(1.0f,LvChoiceLayer::scene()));
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("lvchoice.mp3");
		break;
	case 2:
		GameData::s_iCurBigLevel =2;
		director->replaceScene(CCTransitionFadeTR ::create(1.0f,LvChoiceLayer::scene()));
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("lvchoice.mp3");
		break;
	case 3:
		director->replaceScene(CCTransitionFadeTR ::create(1.0f,GameMenu::scene()));
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game03.mp3");
		
		break;
	case 4:
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		break;
	case 5:
		GameData::s_iCurBigLevel = 3;
		director->replaceScene(CCTransitionFadeTR ::create(1.0f,LvChoiceLayer::scene()));
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game03.mp3");
		break;
	default:
		break;
	}
}