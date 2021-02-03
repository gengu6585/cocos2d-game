#include "LvChoiceLayer.h"
#include "LvButton.h"
#include "PlayScene.h"
#include "GameData.h"
#include "DesertScene.h"
#include "SimpleAudioEngine.h"
#include "Icon.h"
using namespace CocosDenshion;
// 创建场景
CCScene* LvChoiceLayer::scene()
{
	// 创建场景
	CCScene *scene = CCScene::create();
	// 创建层
	LvChoiceLayer *layer = LvChoiceLayer::create();
	// 把层添加到场景
	scene->addChild(layer);
	// 返回场景
	return scene;
}
// 初始化层
bool LvChoiceLayer::init()
{
	// 初始化层父类
	if (!CCLayer::init())
	{
		return false;
	}
	// 音量
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(3.0f);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("lvchoice.mp3");
	
	

	if (GameData::s_iCurBigLevel == 1)
	{
		//初始化第一关背景

		lvPos[0] = ccp(-300, 250);
		lvPos[1] = ccp(-150, 250);
		lvPos[2] = ccp(0, 250);
		lvPos[3] = ccp(150, 250);
		lvPos[4] = ccp(300, 250);
		lvPos[5] = ccp(-300, 100);
		lvPos[6] = ccp(-150, 100);
		lvPos[7] = ccp(0, 100);
		lvPos[8] = ccp(150, 100);
		lvPos[9] = ccp(300, 100);
		lvPos[10] = ccp(-300, -50);
		lvPos[11] = ccp(-150,-50);
		lvPos[12] = ccp(0,-50);
		lvPos[13] = ccp(150,-50);
		lvPos[14] = ccp(300,-50);
		lvPos[15] = ccp(-300,-200);
		lvPos[16] = ccp(-150,-200);
		lvPos[17] = ccp(0,-200);
		lvPos[18] = ccp(150,-200);
		lvPos[19] = ccp(300,-200);
		lvPos[20] = ccp(600,250);
		lvPos[21] = ccp(750,250);
		lvPos[22] = ccp(900,250);
		lvPos[23] = ccp(1050,250);
		lvPos[24] = ccp(1200,250);
		lvPos[25] = ccp(600,100);
		lvPos[26] = ccp(750,100);
		lvPos[27] = ccp(900,100);
		lvPos[28] = ccp(1050,100);
		lvPos[29] = ccp(1200,100);
	
	}
	else if (GameData::s_iCurBigLevel == 2)
	{
		//初始化第二关背景
		lvPos[0] = ccp(-300, 250);
		lvPos[1] = ccp(-150, 250);
		lvPos[2] = ccp(0, 250);
		lvPos[3] = ccp(150, 250);
		lvPos[4] = ccp(300, 250);
		lvPos[5] = ccp(-300, 100);
		lvPos[6] = ccp(-150, 100);
		lvPos[7] = ccp(0, 100);
		lvPos[8] = ccp(150, 100);
		lvPos[9] = ccp(300, 100);
		lvPos[10] = ccp(-300, -50);
		lvPos[11] = ccp(-150,-50);
		lvPos[12] = ccp(0,-50);
		lvPos[13] = ccp(150,-50);
		lvPos[14] = ccp(300,-50);
		lvPos[15] = ccp(-300,-200);
		lvPos[16] = ccp(-150,-200);
		lvPos[17] = ccp(0,-200);
		lvPos[18] = ccp(150,-200);
		lvPos[19] = ccp(300,-200);
		lvPos[20] = ccp(600,250);
		lvPos[21] = ccp(750,250);
		lvPos[22] = ccp(900,250);
		lvPos[23] = ccp(1050,250);
		lvPos[24] = ccp(1200,250);
		lvPos[25] = ccp(600,100);
		lvPos[26] = ccp(750,100);
		lvPos[27] = ccp(900,100);
		lvPos[28] = ccp(1050,100);
		lvPos[29] = ccp(1200,100);
	
		
		
	}
	else
	{
		//初始化默认关背景

		lvPos[0] = ccp(-300, 250);
		lvPos[1] = ccp(-150, 250);
		lvPos[2] = ccp(0, 250);
		lvPos[3] = ccp(150, 250);
		lvPos[4] = ccp(300, 250);
		lvPos[5] = ccp(-300, 100);
		lvPos[6] = ccp(-150, 100);
		lvPos[7] = ccp(0, 100);
		lvPos[8] = ccp(150, 100);
		lvPos[9] = ccp(300, 100);
		lvPos[10] = ccp(-300, -50);
		lvPos[11] = ccp(-150,-50);
		lvPos[12] = ccp(0,-50);
		lvPos[13] = ccp(150,-50);
		lvPos[14] = ccp(300,-50);
		lvPos[15] = ccp(-300,-200);
		lvPos[16] = ccp(-150,-200);
		lvPos[17] = ccp(0,-200);
		lvPos[18] = ccp(150,-200);
		lvPos[19] = ccp(300,-200);
		lvPos[20] = ccp(600,250);
		lvPos[21] = ccp(750,250);
		lvPos[22] = ccp(900,250);
		lvPos[23] = ccp(1050,250);
		lvPos[24] = ccp(1200,250);
		lvPos[25] = ccp(600,100);
		lvPos[26] = ccp(750,100);
		lvPos[27] = ccp(900,100);
		lvPos[28] = ccp(1050,100);
		lvPos[29] = ccp(1200,100);
	}

	char filename[64] = { 0 };
	sprintf(filename,"levelchoicebg/LevelChoice_%d_0.png",GameData::s_iCurBigLevel);

	spBg1 = CCSprite::create(filename);
	this->addChild(spBg1);
	spBg1->setPosition(ccp(winSize.width / 2, winSize.height/2));

	sprintf(filename, "levelchoicebg/LevelChoice_%d_1.png", GameData::s_iCurBigLevel);
	CCSprite* spBg2 = CCSprite::create(filename);
	spBg1->addChild(spBg2);
	//节点坐标系，以父节点的左下角为原点
	spBg2->setPosition(ccp(winSize.width * 1.5f, winSize.height / 2));

	sprintf(filename, "levelchoicebg/LevelChoice_%d_2.png", GameData::s_iCurBigLevel);
	CCSprite* spBg3 = CCSprite::create(filename);
	spBg1->addChild(spBg3);
	//节点坐标系，以父节点的左下角为原点
	spBg3->setPosition(ccp(winSize.width * 2.5f, winSize.height / 2));

	NoTouchReback = CCSprite::create("reback1.png");
	OnTouchReback = CCSprite::create("reback1.png");
	Reback = CCMenuItemSprite::create(
		NoTouchReback,
		OnTouchReback,
		this,
		menu_selector(LvChoiceLayer::choiceIcon));
	Reback->setAnchorPoint(ccp(0,1));
	Reback->setScale(0.5f);
	Reback->setPosition(ccp(0,750));
	Reback->setTag(1);

	IconMenu = CCMenu::create(Reback,NULL);
	IconMenu->setPosition(CCPointZero);
	this->addChild(IconMenu);

	int passCount = GameData::getPassCount(GameData::s_iCurBigLevel);
	// 创建按钮数组
	CCArray* array = CCArray::create();
	for (int i = 0; i < 30; i++)
	{
		// 读档，读星星的数量
		int starNum = GameData::getStarNum(GameData::s_iCurBigLevel, i + 1);//读档
		// 读取已过过关的数量
		
		// 是否过关
		LvButton* btn = LvButton::create(
			i<passCount ? true : false,
			starNum,
			1+i,
			passCount,
			"smallstar/BoxOpen.png",
			"smallstar/BoxClose.png",
			"smallstar/BoxLock.png",
			"smallstar/StarBright.png",
			"smallstar/StarGray.png",
			this,
			menu_selector(LvChoiceLayer::lvBtnCallback));
		btn->setPosition(i<30?lvPos[i]:ccp(i*150,0));
		array->addObject(btn);
		//设置关卡
		btn->setTag(i + 1);
	}
	// 通过数组创建菜单
	CCMenu* menu = CCMenu::createWithArray(array);
	spBg1->addChild(menu);


	// 开启触摸
	this->setTouchEnabled(true);
	return true;
}

void LvChoiceLayer::choiceIcon(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(1); 
	SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	CCMenuItemSprite* lev = (CCMenuItemSprite*)pSender;

	CCDirector* director = CCDirector::sharedDirector();
	
	switch(lev->getTag())
	{
	case 1:
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("lvchoice.mp3");
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		director->replaceScene(CCTransitionFadeTR::create(1.0f,Icon::scene()));
		break;
	default:
		break;
	}
}

// 关卡按钮回调
void LvChoiceLayer::lvBtnCallback(CCObject* obj)
{

	/************************************************************************/
	/* obj:指针 谁调用当前函数 obj指向该按钮						        */
	/************************************************************************/
	LvButton* btn = (LvButton*)obj;
	// 给当前关卡赋值
	GameData::s_iCurLvevel = btn->getTag();

	// 实现场景跳转
	
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	CCDirector::sharedDirector()->replaceScene(DesertScene::scene());
	
	
	
	
}

// 注册触摸
void LvChoiceLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}
// 触摸开始
bool LvChoiceLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}
// 触摸移动
void LvChoiceLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	// 根据触摸点的位置设置背景图的位置
	spBg1->setPositionX(spBg1->getPositionX()+pTouch->getDelta().x);
	// 最小值
	float min = -spBg1->getContentSize().width*1.5f;
	float max = spBg1->getContentSize().width / 2;
	if (spBg1->getPositionX() < min)
	{
		spBg1->setPositionX(min);
	}
	else if (spBg1->getPositionX() > max)
	{
		spBg1->setPositionX(max);
	}
}
// 触摸结束
void LvChoiceLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
}