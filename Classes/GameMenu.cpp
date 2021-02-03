#include "Playscene.h"
#include "SetScene.h"
#include "GameMenu.h"
#include "LoadingScene.h"
#include "Scene2.h"
#include "SimpleAudioEngine.h"
#include "GameMap.h"
#include "Icon.h"

using namespace CocosDenshion;
using namespace cocos2d;

USING_NS_CC;

// ����һ��(�����)����
CCScene* GameMenu::scene()
{
	
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameMenu *layer = GameMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameMenu::init()
{
	 SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();

	if (! CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)))
	{
		return false;
	}
	/*if ( !CCLayer::init() )
	{
	return false;
	}*/
	 
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game03.mp3");
	//���������С = ����::��ȡʵ��->��ȡ���������С
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//������ʼ�� =  ����::��ȡʵ��->��ȡ������ʼ��
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();





	//��Ӿ���:
	//1 ����һ������
	CCSprite* Man = CCSprite::create("startMenu/background.png");
	//2 ���þ���λ��
	Man->setScaleX(1);
	Man->setScaleY(0.7f);
	Man->setPosition(visibleSize/2);
	
	//3 ��������Ϊ�ӽڵ���ӵ��� �㼶
	this->addChild(Man);

	

	NoTouchClosebutton = CCSprite::create("startMenu/quit_game.png");
	OnTouchClosebutton = CCSprite::create("game_blink.png");
    Closebutton = CCMenuItemSprite::create(
                                        NoTouchClosebutton,
                                        OnTouchClosebutton,
                                        this,
                                        menu_selector(GameMenu::ChangeSceneMenu));
    Closebutton->setScale(1.5);
	Closebutton->setPosition(ccp(1334/2,200));
	Closebutton->setTag(1);
    // create menu, it's an autorelease object
	//��Ӱ�ť
	// 1 ������׼��ͼƬ

	NoTouchBackGround = CCSprite::create("startMenu/backgroundstory.png");
	OnTouchBackGround = CCSprite::create("game_blink.png");
	BackGround = CCMenuItemSprite::create(
		NoTouchBackGround,
		OnTouchBackGround,
		this,
		menu_selector(GameMenu::ChangeSceneMenu));
	BackGround->setScale(1.5);
	BackGround->setPosition(ccp(1334/2,350));
	BackGround->setTag(2);


	NoTouchStartGame = CCSprite::create("startMenu/startgame.png");
	OnTouchStartGame = CCSprite::create("game_blink.png");
	StartGame = CCMenuItemSprite::create(
		NoTouchStartGame,
		OnTouchStartGame,
		this,
		menu_selector(GameMenu::ChangeSceneMenu));
	StartGame->setScale(1.5);
	StartGame->setPosition(ccp(1334/2,500));
	StartGame->setTag(3);

	NoTouchToLoading = CCSprite::create("reback1.png");
	OnTouchToLoading = CCSprite::create("game_blink.png");
	// 2 ��ť
	ToLoading = CCMenuItemSprite::create(
		NoTouchToLoading,
		OnTouchToLoading,
		this,
		menu_selector(GameMenu::ChangeSceneMenu)); 
	// 3 ����λ��
	ToLoading->setAnchorPoint(ccp(0,1));
	ToLoading->setScale(0.3f);
	ToLoading->setPosition(ccp(0,750));
	// 4 ���ñ��
	ToLoading->setTag(4);
	
	
	NoTouchCloseMusic = CCSprite::create("closemusic.png");
	OnTouchCloseMusic = CCSprite::create("game_blink.png");
	CloseMusic = CCMenuItemSprite::create(
		NoTouchCloseMusic,
		OnTouchCloseMusic,
		this,
		menu_selector(GameMenu::ChangeSceneMenu)); 
	CloseMusic->setAnchorPoint(ccp(1,1));
	CloseMusic->setScale(0.75);
	CloseMusic->setPosition(ccp(1334,750));
	CloseMusic->setTag(5);
	
	CCSprite* BBUG3 = CCSprite::create("bbug.png");
	CCSprite* BBUG4 = CCSprite::create("bbug.png");
	CCMenuItemSprite*	BBUG5= CCMenuItemSprite::create(
		BBUG3,
		BBUG4,
		this,
		menu_selector(GameMenu::ChangeSceneMenu));
	BBUG5->setPosition(ccp(280,170));
	BBUG5->setScale(0.1f);
	CCSprite* BBUG = CCSprite::create("bbug.png");
	CCSprite* BBUG1 = CCSprite::create("bbug.png");
	CCMenuItemSprite*	BBUG2 = CCMenuItemSprite::create(
		BBUG,
		BBUG1,
		this,
		menu_selector(GameMenu::ChangeSceneMenu));
	BBUG2->setScale(0.1f);
	BBUG2->setPosition(ccp(1250,400));
	CCMoveTo* move1 = CCMoveTo::create(2,ccp(1200,500));
	CCMoveTo* move2 = CCMoveTo::create(2,ccp(1150,650));
	CCMoveTo* move3 = CCMoveTo::create(2,ccp(1100,700));
	CCMoveTo* move4 = CCMoveTo::create(2,ccp(1000,750));
	CCMoveTo* move5 = CCMoveTo::create(2,ccp(1150,800));

	CCDelayTime* delayer = CCDelayTime::create(2.0f);
	CCDelayTime* delayer1 = CCDelayTime::create(1.0f);
	CCSequence* bug_seq = CCSequence::create(delayer,move1,delayer,move2,move3,delayer1,move4,move5,NULL);
	BBUG2->runAction(bug_seq);
	Closebutton->setPosition(1334/2,200);
	Closebutton->setTag(6);
	// 5 �����˵�
	ChangeScene_ = CCMenu::create(Closebutton,ToLoading,StartGame,BackGround,CloseMusic,BBUG2,BBUG5 ,NULL);
	ChangeScene_->setPosition(CCPointZero);
	// 6 ����ӽڵ�
	this->addChild(ChangeScene_);


 
    return true;
}


void GameMenu::ChangeSceneMenu(CCObject* pSender)
{
	// 1 �ҵ���
	CCDirector* director1 = CCDirector::sharedDirector();
	// 2 ��Ҫ��ת���ĳ���
	CCScene* Loadingscene = LoadingScene::scene();
	// �л�Ч�� ���� 1��תʱ�� 2�л�Ŀ�곡��
	// �л���ʽ* ָ���� = �л���ʽ::create(ʱ��,Ŀ�곡����ָ��)
	CCTransitionRotoZoom* ptran1 = CCTransitionRotoZoom::create(1.0f,Loadingscene);
	// 3 ����ָ����ת

	CCDirector* director2 = CCDirector::sharedDirector();
	CCScene* ToSetScene = SetScene::scene();
	CCTransitionTurnOffTiles* ptran2 =  CCTransitionTurnOffTiles::create(1.0f,ToSetScene);
	
	CCDirector* director3 = CCDirector::sharedDirector();
	CCScene* ToIcon = Icon::scene();
	CCTransitionTurnOffTiles* ptran3 =  CCTransitionTurnOffTiles::create(1.0f,ToIcon);

	
	

	


	



	CCMenuItemSprite* lev = (CCMenuItemSprite*)pSender;

	
	switch(lev->getTag())
	{
	case 1:
		// ����TagֵΪ1�İ�ť��Ӧ���߼�
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
		CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	#else
		CCDirector::sharedDirector()->end();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
	#endif
	#endif
		break;
	case 2:
		SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		director3->replaceScene(CCTransitionPageTurn::create(1.0f,Scene2::scene(),false));
		break;
	case 3:
		SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("game04.mp3");
		director3->replaceScene(ptran3);
		break;
	case 4:
		SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		director1->replaceScene(ptran1);
		
		break;
	case 5:
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		break;
	default:
		break;
	}
}