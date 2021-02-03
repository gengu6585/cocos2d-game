#include "LoadingScene.h"
#include "GameMenu.h"
#include "Scene2.h"
#include "SimpleAudioEngine.h"
#include "Icon.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// 创建场景
CCScene* Scene2::scene()
{
	//创建一个场景
	CCScene* pscene =CCScene::create();
	//创建一个当前类型的层
	Scene2* player = Scene2::create();
	//将层作为子节点添加到场景
	pscene->addChild(player);
	//将场景指针返回
	return pscene;
}
//初始化
bool Scene2::init()
{


	//如果父类初始化失败 返回false
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

	// 1 找导演
	CCDirector* director = CCDirector::sharedDirector();
	// 2 将要跳转到的场景
	CCScene* ToGameMenu = GameMenu::scene();
	// 切换效果 参数 1旋转时长 2切换目标场景
	// 切换方式* 指针名 = 切换方式::create(时长,目标场景的指针)
	CCTransitionPageTurn* ptran = CCTransitionPageTurn::create(1.0f,ToGameMenu,true);




	// 3 导演指挥跳转
	//lev->getTag(); //获得编号 知道是谁被按下
	switch(lev->getTag())
	{
	case 1:
		director->replaceScene(ptran);
		break;
	default:
		break;
	}
}
