#include "LoadingScene.h"
#include "GameMenu.h"
using namespace cocos2d;
#include "SimpleAudioEngine.h"
#include "GameData.h"
using namespace CocosDenshion;
USING_NS_CC;
// 创建场景

CCScene* LoadingScene::scene()
{
	//创建一个场景
	CCScene* pscene =CCScene::create();
	//创建一个当前类型的层
	LoadingScene* player = LoadingScene::create();
	//将层作为子节点添加到场景
	pscene->addChild(player);
	//将场景指针返回
	return pscene;
}
//初始化
 bool LoadingScene::init()
{

	
	//如果父类初始化失败 返回false
	if ( !CCLayer::init() )
	{
		return false;
	}

	GameData::returnDefault();

	/*

	在这里开始添加代码
	*/
	//举例:添加精灵
	CCSprite* pLogo = CCSprite::create("game_LOGO.png");
	pLogo->setPosition(ccp(1334/2,750/2));
	//将精灵作为子节点添加到层
	this->addChild(pLogo); //this 指的是层本身
	
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
		切换场景:
		1 主动切换: 点击按钮
		2 被动切换: 逻辑设置

	*/
	/*
		结束按钮添加步骤
		1 创建菜单按钮
		2 设置位置
		3 创建菜单
		4 给菜单设置位置
		5 把菜单作为子节点添加到层
	*/
	// 创建一个切换到HelloWorld界面的按钮
	// 参数: 1没有点击时的状态图 2点击时的状态图 3this 4回调函数
	// 回调函数:按钮按下会执行的函数
	//1 创建菜单按钮


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
	// 6 添加子节点
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
	
	// 创建一个闪耀
	// 创建一个序列动作 先延时 再MoveTo 再切换
	/*CCSequence* seq = CCSequence::create(MoveTo1,MoveTo2,MoveTo3,MoveTo4,NULL);*/
	CCSequence* seqAct = CCSequence::create(

	seq,
	//真回调函数
	CCCallFunc::create(this,callfunc_selector(LoadingScene::seqChangeScene)),NULL);
	
	pSprite->runAction(seqAct);


	
	return true;
}

 void LoadingScene::seqChangeScene()
 {
	 SimpleAudioEngine::sharedEngine()->playEffect("ohyeah.mp3");
	 SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	 // 1 打开音乐文件
	 // 1 找导演
	 CCDirector* director1 = CCDirector::sharedDirector();
	 // 2 将要跳转到的场景
	 CCScene* Loadingscene = GameMenu::scene();
	 // 切换效果 参数 1旋转时长 2切换目标场景
	 CCTransitionFade* ptran1 = CCTransitionFade::create(2.0f,Loadingscene);
	 // 3 导演指挥跳转
	 director1->replaceScene(ptran1);
 }
  void LoadingScene::ChangeSceneMenu1(CCObject* pSender)
  {
	  SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	  SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	  // 1 找导演
	  CCDirector* director1 = CCDirector::sharedDirector();
	  // 2 将要跳转到的场景
	  CCScene* Loadingscene = GameMenu::scene();
	  // 切换效果 参数 1旋转时长 2切换目标场景
	  CCTransitionFade* ptran1 = CCTransitionFade::create(2.0f,Loadingscene);
	  // 3 导演指挥跳转
	  director1->replaceScene(ptran1);

  }
 



