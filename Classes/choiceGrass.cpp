#include "choiceGrass.h"
#include "Icon.h"
#include "SimpleAudioEngine.h"
#include "Playscene.h"
#include "GameMenu.h"
#include "DesertScene.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// 创建场景
CCScene* choiceGrass::scene()
{
	//创建一个场景
	CCScene* pscene =CCScene::create();
	//创建一个当前类型的层
	choiceGrass* player = choiceGrass::create();
	//将层作为子节点添加到场景
	pscene->addChild(player);
	//将场景指针返回
	return pscene;
}
//初始化
bool choiceGrass::init()
{
	//如果父类初始化失败 返回false
	if ( !CCLayer::init() )
	{
		return false;
	}
	bgpicture1 = CCSprite::create("choicebg/choicebg1.png");
	bgpicture1->setPosition(ccp(1334/2,750/2));
	bgpicture1->setScaleX(1.67f);
	bgpicture1->setScaleY(1.25f);
	this->addChild(bgpicture1);
	CCSprite* bgpicture2 = CCSprite::create("choicebg/choicebg2.png");
	bgpicture2->setPosition(ccp(1334+1334,750/2));
	bgpicture2->setScaleX(1.67f);
	bgpicture2->setScaleY(1.25f);
	this->addChild(bgpicture2);
	CCSprite* bgpicture3 = CCSprite::create("choicebg/choicebg3.png");
	bgpicture3->setPosition(ccp(1334+1334+1334,750/2));
	bgpicture3->setScaleX(1.67f);
	bgpicture3->setScaleY(1.25f);
	this->addChild(bgpicture3);
	return true;
}