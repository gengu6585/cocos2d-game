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

// 创建一个(带层的)场景
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
	//可视区域大小 = 导演::获取实例->获取可视区域大小
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//坐标起始点 =  导演::获取实例->获取坐标起始点
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();





	//添加精灵:
	//1 创建一个精灵
	CCSprite* Man = CCSprite::create("startMenu/background.png");
	//2 设置精灵位置
	Man->setScaleX(1);
	Man->setScaleY(0.7f);
	Man->setPosition(visibleSize/2);
	
	//3 将精灵作为子节点添加到层 层级
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
	//添加按钮
	// 1 给精灵准备图片

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
	// 2 按钮
	ToLoading = CCMenuItemSprite::create(
		NoTouchToLoading,
		OnTouchToLoading,
		this,
		menu_selector(GameMenu::ChangeSceneMenu)); 
	// 3 设置位置
	ToLoading->setAnchorPoint(ccp(0,1));
	ToLoading->setScale(0.3f);
	ToLoading->setPosition(ccp(0,750));
	// 4 设置编号
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
	// 5 创建菜单
	ChangeScene_ = CCMenu::create(Closebutton,ToLoading,StartGame,BackGround,CloseMusic,BBUG2,BBUG5 ,NULL);
	ChangeScene_->setPosition(CCPointZero);
	// 6 添加子节点
	this->addChild(ChangeScene_);


 
    return true;
}


void GameMenu::ChangeSceneMenu(CCObject* pSender)
{
	// 1 找导演
	CCDirector* director1 = CCDirector::sharedDirector();
	// 2 将要跳转到的场景
	CCScene* Loadingscene = LoadingScene::scene();
	// 切换效果 参数 1旋转时长 2切换目标场景
	// 切换方式* 指针名 = 切换方式::create(时长,目标场景的指针)
	CCTransitionRotoZoom* ptran1 = CCTransitionRotoZoom::create(1.0f,Loadingscene);
	// 3 导演指挥跳转

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
		// 设置Tag值为1的按钮相应的逻辑
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