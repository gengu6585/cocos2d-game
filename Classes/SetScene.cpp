#include "LoadingScene.h"
#include "GameMenu.h"
#include "SetScene.h"
#include <assert.h>
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// 创建场景
CCScene* SetScene::scene()
{
	assert(true);
	//创建一个场景
	CCScene* pscene =CCScene::create();
	//创建一个当前类型的层
	SetScene* player = SetScene::create();
	//将层作为子节点添加到场景
	pscene->addChild(player);
	//将场景指针返回
	return pscene;
}
//初始化
bool SetScene::init()
{


	//如果父类初始化失败 返回false
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

	//精灵:巡逻
	//1 使用动作
	//2 使用调度器:默认调度器:开启后 每一帧都会调用的一个函数
	
	// 1添加一个精灵
	Bug = CCSprite::create("PlayerUp_0.png");
	Bug->setPosition(ccp(1334/2,750/2));
	this->addChild(Bug);
	/*Bug->runAction(rep);*/
	// 2创建一个动画
	CCAnimation* m_animation = CCAnimation::create();
	// 3给创建的动画添加帧
	m_animation->addSpriteFrameWithFileName("PlayerUp_0.png");
	m_animation->addSpriteFrameWithFileName("PlayerUp_1.png");
	m_animation->addSpriteFrameWithFileName("PlayerUp_2.png");
	m_animation->addSpriteFrameWithFileName("PlayerUp_3.png");
	//m_animation->addSpriteFrameWithFileName("PlayerUp_4.png");
	//m_animation->addSpriteFrameWithFileName("PlayerUp_5.png");
	/*m_animation->addSpriteFrameWithFileName("PlayerRight_06.png");*/
	// 4.1 间隔时间 播放次数: 参数(无符号整数)无负数
	
	m_animation->setDelayPerUnit(0.2f);
	m_animation->setLoops(-1); //负数时为无限重复 数据溢出
	// 5将动画转换成动作
	CCAnimate* m_animate = CCAnimate::create(m_animation);
	// 6精灵执行动画(动作)
	Bug->runAction(m_animate);

	//开启默认调度器
	//只需要开启一次:写在init()
	/*scheduleUpdate();*/
	schedule(
		schedule_selector(SetScene::MyUpdate), //相应函数
		1.0f, //每次调用的时间间隔
		9,    //次数  真实次数为6次
		1);   //首次调用延时
	return true;
}
void SetScene::ChangeSceneMenu(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	CCMenuItemSprite* lev = (CCMenuItemSprite*)pSender;

	// 1 找导演
	CCDirector* director = CCDirector::sharedDirector();
	// 2 将要跳转到的场景
	CCScene* ToGameMenu = GameMenu::scene();
	// 切换效果 参数 1旋转时长 2切换目标场景
	// 切换方式* 指针名 = 切换方式::create(时长,目标场景的指针)
	CCTransitionRotoZoom* ptran = CCTransitionRotoZoom::create(1.0f,ToGameMenu);

	
	// 3 导演指挥跳转
	//lev->getTag(); //获得编号 知道是谁被按下
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
//	//写巡逻逻辑
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