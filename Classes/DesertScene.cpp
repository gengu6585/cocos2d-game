#include "LoadingScene.h"
#include "GameMenu.h"
#include "Scene2.h"
#include "SimpleAudioEngine.h"
#include "Icon.h"
#include "textScrollEffects.h"
#include "DesertScene.h"
#include "GameData.h"
#include "LvChoiceLayer.h"
#include "LvButton.h"
#include "Player.h"
#include "Playscene.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// 创建场景
CCScene* DesertScene::scene()
{
	//创建一个场景
	CCScene* pscene =CCScene::create();
	//创建一个当前类型的层
	DesertScene* player = DesertScene::create();
	//将层作为子节点添加到场景
	pscene->addChild(player);
	//将场景指针返回
	return pscene;
}
//初始化
bool DesertScene::init()
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
		menu_selector(DesertScene::Button)); 
	Reback->setAnchorPoint(ccp(1,1));
	Reback->setScale(0.3f);
	Reback->setPosition(ccp(1230,750));
	Reback->setTag(1);

	NoTouchReStart1 = CCSprite::create("restart.png");
	OnTouchReStart1 = CCSprite::create("game_blink.png");
	ReStart1 = CCMenuItemSprite::create(
		NoTouchReStart1,
		OnTouchReStart1,
		this,
		menu_selector(DesertScene::Button)); 
	ReStart1->setAnchorPoint(ccp(1,1));
	ReStart1->setScale(0.8f);
	ReStart1->setPosition(ccp(1334,750));
	ReStart1->setTag(2);


	IconMenu = CCMenu::create(Reback,ReStart1,NULL);
	IconMenu->setPosition(CCPointZero);
	this->addChild(IconMenu);

	char str[32] = {0};
	
	sprintf(str,"Map/map%d_%d.tmx",GameData::s_iCurBigLevel,GameData::s_iCurLvevel);
	CCLog("str");
	p_Map = GameMap::create(str);
	p_Map->setPosition(ccp(25,25));
	this->addChild(p_Map);

	CCParticleRain* rain = CCParticleRain::create();
	rain->setScale(1.5);
	this->addChild(rain);

	CCParticleSnow* snow = CCParticleSnow::create();
	snow->setScale(1.5);
	this->addChild(snow);
	// 获得宝箱数量状态栏
	spBoxState = CCSprite::create("UI_GoldBoxNum.png");
	this->addChild(spBoxState);
	spBoxState->setPosition(ccp(1334-90,480));
	//初始化变量
	m_iBoxCount = 0;
	// 根据获得的宝箱数量加载宝箱数
	const char* strBoxCount = CCString::createWithFormat(
		"%d",m_iBoxCount)->getCString();
	m_boxCountAtlas = CCLabelAtlas::create(strBoxCount,
		"level_num.png",
		37,
		37,
		'0');
	spBoxState->addChild(m_boxCountAtlas);
	m_boxCountAtlas->setPosition(ccp(30.0f,10.f));




	scheduleUpdate();


	this->GameInitObject_0();
	this->GameInitObject_1();
	this->GameInitObject_2();
	this->GameInitObject_3();
	MonsterFactory(monster);
	/*this->GameInitObject_4();*/
	this->GameInitObject_5();
	this->setTouchEnabled(true);




	return true;
}

void DesertScene::Button(CCObject* pSender)
{


	SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	CCMenuItemSprite* lev = (CCMenuItemSprite*)pSender;
	int a =lev->getTag();

	CCDirector* director = CCDirector::sharedDirector();
	

	






	// 3 导演指挥跳转
	//lev->getTag(); //获得编号 知道是谁被按下
	switch(lev->getTag())
	{
	case 1:
		director->replaceScene(CCTransitionRotoZoom::create(1.0f,LvChoiceLayer::scene()));
		break;
	case 2:
		
		director->replaceScene(CCTransitionFade::create(1.0f,DesertScene::scene()));
		   
		
		break;
	case 3:
		GameData::s_iCurLvevel=GameData::s_iCurLvevel+1;
		director->replaceScene(CCTransitionFade::create(1.0f,DesertScene::scene()));
		
		break;
	default:
		break;
	}
}







//初始化主角
void DesertScene::GameInitObject_0()
{
	//加载英雄
	//先判断是否存在英雄对象数据. 参数:对象组名字;对象名字
	if (p_Map->getObjectForName("object0","player"))
	{
		playerPos = p_Map->getObjectPositionForName("object0","player");

		// 创建精灵设置位置 作为主角
		player = Player::create("mushianimation/mushimushi2_00001.png");
		player->setPosition(playerPos);

		this->addChild(player);
		//CCAnimation* m_animation = CCAnimation::create();
		// //3给创建的动画添加帧
		//m_animation->addSpriteFrameWithFileName("PlayerRight_00.png");
		//m_animation->addSpriteFrameWithFileName("PlayerRight_01.png");
		//m_animation->addSpriteFrameWithFileName("PlayerRight_02.png");
		//m_animation->addSpriteFrameWithFileName("PlayerRight_03.png");
		//m_animation->addSpriteFrameWithFileName("PlayerRight_04.png");
		//m_animation->addSpriteFrameWithFileName("PlayerRight_05.png");
		///*m_animation->addSpriteFrameWithFileName("PlayerRight_06.png");*/
		// //4.1 间隔时间 播放次数: 参数(无符号整数)无负数

		//m_animation->setDelayPerUnit(0.2f);
		//m_animation->setLoops(-1); //负数时为无限重复 数据溢出
		// //5将动画转换成动作
		//CCAnimate* m_animate = CCAnimate::create(m_animation);
		// //6精灵执行动画(动作)
		//m_player->runAction(m_animate);
		//

		/*	m_player->setScale(0.6f);*/
	}
}
//初始化钥匙和门
void DesertScene::GameInitObject_1()
{
	//初始化钥匙
	//先判断是否存在英雄对象数据. 参数:对象组名字;对象名字
	if (p_Map->getObjectForName("object1","key"))
	{
		playerPos = p_Map->getObjectPositionForName("object1","key");

		// 创建精灵设置位置 作为主角
		m_key = CCSprite::create("key.png");
		m_key->setScaleX(0.58f);
		m_key->setScaleY(0.648f);
		m_key->setPosition(playerPos);

		this->addChild(m_key);

	}
	//防止出现 野指针 空指针
	else{
		m_key = NULL;
	}

	//初始化门
	//先判断是否存在英雄对象数据. 参数:对象组名字;对象名字
	if (p_Map->getObjectForName("object1","exit"))
	{
		playerPos = p_Map->getObjectPositionForName("object1","exit");

		// 创建精灵设置位置 作为主角
		m_exit = CCSprite::create("exit.png");
		m_exit->setScaleX(0.198f);
		m_exit->setScaleY(0.198f);
		m_exit->setPosition(playerPos);

		this->addChild(m_exit);

	}
	//防止出现 野指针 空指针
	else{
		m_key = NULL;
	}
}
//初始化宝箱
void DesertScene::GameInitObject_2()
{
	char boxName[32] = {0};
	for (int i=0;i<3;++i)
	{
		sprintf(boxName,"box_%d",i+1);
		//判断是否存在对象
		if (p_Map->getObjectForName("object2",boxName))
		{
			m_box[i] = CCSprite::create("goalBox/box_0.png");
			m_box[i]->setPosition(p_Map->getObjectPositionForName("object2",boxName));
			m_box[i]->setScaleX(1.1f);
			m_box[i]->setScaleY(1.1f);
			// 1添加一个精灵
			// 2创建一个动画
			CCAnimation* m_animation = CCAnimation::create();
			// 3给创建的动画添加帧
			m_animation->addSpriteFrameWithFileName("goalBox/box_1.png");
			m_animation->addSpriteFrameWithFileName("goalBox/box_2.png");
			m_animation->addSpriteFrameWithFileName("goalBox/box_3.png");
			// 4.1 间隔时间 播放次数: 参数(无符号整数)无负数
			m_animation->setDelayPerUnit(0.2f);
			m_animation->setLoops(-1); //负数时为无限重复 数据溢出
			// 5将动画转换成动作
			CCAnimate* m_animate = CCAnimate::create(m_animation);
			// 6精灵执行动画(动作)
			m_box[i]->runAction(m_animate);
			m_box[i]->runAction(
				CCRepeatForever::create(
				CCSequence::create(
				CCScaleTo::create(0.5,1.1f),
				CCScaleTo::create(0.5,0.9f),
				NULL))
				);
			this->addChild(m_box[i]);
		}
	}

}
//初始化陷阱
void DesertScene::GameInitObject_3()
{
	//sizeof() 作用:求内存大小
	for (int i=0;i<(sizeof(m_trap)/sizeof(m_trap[0]));i++)
	{
		m_trap[i] = NULL;
		char trapName[32] = {0};
		sprintf(trapName,"trap_%d",i+1);
		//判断是否存在对象
		if (p_Map->getObjectForName("object3",trapName))
		{
			m_trap[i] = CCSprite::create("trap_0.png");
			m_trap[i]->setPosition(p_Map->getObjectPositionForName("object3",trapName));
			//CCAnimation* m_animation1 = CCAnimation::create();
			//// 3给创建的动画添加帧
			//m_animation1->addSpriteFrameWithFileName("trap_1.png");
			//m_animation1->addSpriteFrameWithFileName("trap_2.png");
			//m_animation1->addSpriteFrameWithFileName("trap_3.png");
			//// 4.1 间隔时间 播放次数: 参数(无符号整数)无负数
			//m_animation1->setDelayPerUnit(0.2f);
			//m_animation1->setLoops(-1); //负数时为无限重复 数据溢出
			//// 5将动画转换成动作
			//CCAnimate* m_animate = CCAnimate::create(m_animation1);
			//// 6精灵执行动画(动作)
			/*m_box[i]->runAction(m_animate);*/
			this->addChild(m_trap[i]);
			//添加动作

		}
	}

}
//初始化怪物
void DesertScene::GameInitObject_4()
{
	//sizeof() 作用:求内存大小
	for (int i=0;i<(sizeof(m_Monster)/sizeof(m_Monster[0]));i++)
	{
		m_Monster[i] = NULL;
		char MonName[32] = {0};
		sprintf(MonName,"monster_%d",i);
		//判断是否存在对象
		if (p_Map->getObjectForName("object4",MonName))
		{
			m_Monster[i] = CCSprite::create("monster/monster_0.png");
			m_Monster[i]->setPosition(p_Map->getObjectPositionForName("object4",MonName));
			this->addChild(m_Monster[i]);
			m_Monster[i]->setScale(1.5);
			//获取方向向量
			const int DIR_X = p_Map->getCustomStr("object4",MonName,"dirX")->intValue();
			const int DIR_Y = p_Map->getCustomStr("object4",MonName,"dirY")->intValue();
			//获取格子数量
			const int DISCOUNT = p_Map->getCustomStr("object4",MonName,"dis")->intValue();
			//获取时间
			float distance = DISCOUNT*p_Map->getTileSize().width;
			float speed = p_Map->getCustomStr("object4",MonName,"speed")->floatValue();
			float t = distance / speed;
			float xx = distance*DIR_X;
			float yy = DISCOUNT*p_Map->getTileSize().width*DIR_Y;
			//添加动作
			m_Monster[i]->runAction(
				CCRepeatForever::create(
				CCSequence::create(
				CCMoveBy::create(t,ccp(xx,yy)),
				CCMoveBy::create(t,ccp(-xx,-yy)),
				NULL))
				);
		}
	}

}
//初始化传送门
void DesertScene::GameInitObject_5()
{
	int len = sizeof(m_Transfer)/sizeof(m_Transfer[0]);
	for(int i = 0; i < len ;i++)
	{
		for(int j = 0; j < 2 ; j++)
		{
			m_Transfer[i][j] = NULL;
			char objectName[32] = { 0 };
			sprintf(objectName,"transfer%d_%d",j,i);
			if(p_Map->getObjectForName("object5",objectName))
			{
				char filename[32] = { 0 };
				sprintf(filename,"transferdoor/transfer%d.png",j);
				m_Transfer[i][j] = CCSprite::create(filename);
				m_Transfer[i][j]->setTag(999);
				this->addChild(m_Transfer[i][j]);
				m_Transfer[i][j]->setScale(0.7f);
				m_Transfer[i][j]->setPosition(p_Map->getObjectPositionForName("object5",objectName));
				CCAnimation* m_animation1 = CCAnimation::create();
				m_animation1->addSpriteFrameWithFileName("transferdoor/transfer0.png");
				m_animation1->addSpriteFrameWithFileName("transferdoor/transfer1.png");
				m_animation1->addSpriteFrameWithFileName("transferdoor/transfer2.png");
				m_animation1->addSpriteFrameWithFileName("transferdoor/transfer3.png");
				m_animation1->setDelayPerUnit(0.3f);
				m_animation1->setLoops(-1);
				CCAnimate* m_animate1 = CCAnimate::create(m_animation1);
				m_Transfer[i][j]->runAction(m_animate1);
			}
		}
	}
}
//检测碰撞
bool DesertScene::playerCOllision1(CCNode* obj)
{
	// 使用指针:首先判断是否有指向
	if (obj!=NULL)
	{
		float xDis = player->getPositionX()-obj->getPositionX();
		float yDis = player->getPositionY()-obj->getPositionY();

		float w = p_Map->getTileSize().width; //图块宽
		float h = p_Map->getTileSize().height;//图块高
		if (abs(xDis)<w && abs(yDis) <h)
		{
			return true;
		}
	}
	return false;

}

//调度器检测
void DesertScene::update(float dt)
{
	int sum =0;	
	isgetkey = false;
	//判断钥匙碰撞检测
	if (playerCOllision1(m_key))
	{

		this->removeChild(m_key);
		m_key =NULL;
		isgetkey = true;
	}
	//判断门碰撞检测
	if(playerCOllision1(m_exit))
	{
		if(m_key == NULL)
		{
			//读档
			int oldNum = GameData::getStarNum(GameData::s_iCurBigLevel,GameData::s_iCurLvevel);
			//读已过的关卡数量(修改界面数据)
			int passCount = GameData::getPassCount(GameData::s_iCurBigLevel);
			if (GameData::s_iCurLvevel >= passCount)
			{
				
				GameData::setPassCount(GameData::s_iCurBigLevel,++passCount);
			}
			m_exit =NULL;
			//判断是否高于历史最大存档
			if (m_iBoxCount > oldNum)
			{
				GameData::saveStarNum(GameData::s_iCurBigLevel,GameData::s_iCurLvevel,m_iBoxCount);
				
			}
			
			
			/*GameData::saveStarNum(GameData::s_iCurBigLevel,GameData::s_iCurLvevel,m_iBoxCount);*/
			/*CCDirector::sharedDirector()->replaceScene(Playscene::scene());*/

			for(int i = 0 ; i < 3 ; i++)
			{
				if(m_box[i] == NULL)
				{
					sum=sum+1;
				}
			}
			NoTouchReStart = CCSprite::create("restart.png");
			OnTouchReStart = CCSprite::create("game_blink.png");
			ReStart = CCMenuItemSprite::create(
				NoTouchReStart,
				OnTouchReStart,
				this,
				menu_selector(DesertScene::Button)); 
			ReStart->setAnchorPoint(ccp(1,1));
			ReStart->setScale(0.8f);
			ReStart->setPosition(ccp(600,350));
			ReStart->setTag(2);

			NoTouchToNext = CCSprite::create("next.png");
			OnTouchToNext = CCSprite::create("next.png");
			ToNext = CCMenuItemSprite::create(
				NoTouchToNext,
				OnTouchToNext,
				this,
				menu_selector(DesertScene::Button));
			ToNext->setAnchorPoint(ccp(1,1));
			ToNext->setScale(0.8f);
			ToNext->setPosition(ccp(800,350));
			ToNext->setTag(3);

			IconMenu = CCMenu::create(ReStart,ToNext,NULL);
			IconMenu->setPosition(CCPointZero);
			this->addChild(IconMenu);

			CCSprite* win_bg = CCSprite::create("star/win_bg.png");
			win_bg->setPosition(ccp(1334/2,750/2));
			this->addChild(win_bg);

			CCSprite* star_bg1 = CCSprite::create("star/StarGray1.png");
			star_bg1->setPosition(ccp(550,750/1.8));
			this->addChild(star_bg1);

			CCSprite* star_bg2 = CCSprite::create("star/StarGray1.png");
			star_bg2->setPosition(ccp(650,750/1.8));
			this->addChild(star_bg2);

			CCSprite* star_bg3 = CCSprite::create("star/StarGray1.png");
			star_bg3->setPosition(ccp(750,750/1.8));
			this->addChild(star_bg3);

			CCSprite* star_bg4 = CCSprite::create("star/StarBright1.png");
			star_bg4->setOpacity(0);
			CCFadeTo* fadeIn = CCFadeTo::create(3,255);

			star_bg4->runAction(fadeIn);
			star_bg4->setPosition(ccp(550,750/1.8));


			CCSprite* star_bg5 = CCSprite::create("star/StarBright1.png");
			star_bg5->setPosition(ccp(650,750/1.8));
			star_bg5->setOpacity(0);
			CCFadeTo* fadeIn1 = CCFadeTo::create(3,255);
			star_bg5->runAction(fadeIn1);


			CCSprite* star_bg6 = CCSprite::create("star/StarBright1.png");
			star_bg6->setPosition(ccp(750,750/1.8));
			star_bg6->setOpacity(0);
			CCFadeTo* fadeIn2 = CCFadeTo::create(3,255);
			star_bg6->runAction(fadeIn2);


	
			switch(sum)
			{
			case 0:
		
				break;
			case 1:
				
				this->addChild(star_bg4);
				break;
			case 2:
				
				this->addChild(star_bg4);
				this->addChild(star_bg5);
				break;
			case 3:
				
				this->addChild(star_bg4);
				this->addChild(star_bg5);
				this->addChild(star_bg6);
				break;
			default:
				break;
			}
		}
		else //如果没有带钥匙
		{
			player->setPlayerState(HERO_STAY);
			//通过人来的方向修改人的坐标
			switch(player->HERODIR)
			{
			case HEROMOVEDIR_DOWN:
				player->setPositionY(m_exit->getPositionY()+70);
				break;
			case HEROMOVEDIR_UP:
				player->setPositionY(m_exit->getPositionY()-70);
				break;
			case HEROMOVEDIR_LEFT:
				player->setPositionX(m_exit->getPositionX()+70);
				break;
			case HEROMOVEDIR_RIGHT:
				player->setPositionX(m_exit->getPositionX()-70);
				break;
			}
		}

	}

	//宝箱检测
	for (int i=0;i<3;++i)
	{
		if (playerCOllision1((m_box[i])))
		{


			m_iBoxCount++;
			// 更新ui状态栏
			const char* strBoxCount = CCString::createWithFormat(
				"%d",m_iBoxCount)->getCString();
			m_boxCountAtlas->setString(strBoxCount);
			this->removeChild(m_box[i]);

			m_box[i]=NULL;
		}

	}
	//陷阱检测
	for (int i=0;i<sizeof(m_trap)/sizeof(m_trap[0]);++i)
	{
		if (m_trap[i] != NULL)
		{
			if (playerCOllision1(m_trap[i]))
			{
				CCDirector::sharedDirector()->replaceScene(DesertScene::scene());
	
				m_trap[i] = NULL;
			}
		}
	}
	////怪物检测
	//for (int i=0;i<sizeof(m_Monster)/sizeof(m_Monster[0]);++i)
	//{
	//	if (m_Monster[i] != NULL)
	//	{
	//		if (playerCOllision1(m_Monster[i]))
	//		{
	//			CCDirector::sharedDirector()->replaceScene(Playscene::scene());
	//	

	//			m_Monster[i] = NULL;
	//		}
	//	}
	//}

	//怪物检测

	for (int i=0;i<monster.size();i++)
	{
		/*playerCollosion(monster[0])*/
		CCLog("fsdfsd");
		if (playerCOllision1(monster[i]))
		{
			CCDirector::sharedDirector()->replaceScene(DesertScene::scene());
			monster[i] = NULL;
			/*	player->bIsStay;
			player->stopActionByTag(1);

			player->setPosition(p_Map->getObjectPositionForName("object","yang"));

			hero->setHp(hero->getHp()-1);*/
			/*player->bIsStay;
			player->stopActionByTag(1);

			player->setPosition(p_Map->getObjectPositionForName("object","yang"));

			hero->setHp(hero->getHp()-1);*/
			/*monster[i]->setvisible(false);*/


		}
	}


	int len1 = sizeof(m_Transfer)/sizeof(m_Transfer[0]);
	for(int i = 0 ; i < len1 ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			if(m_Transfer[i][j]!=NULL)
			{
				if(playerCOllision1(m_Transfer[i][j]))
				{
					if(999 == m_Transfer[i][j]->getTag())
					{
						player->setPlayerState(HERO_STAY);
						m_Transfer[i][(1+j)%2]->setTag(1000);
						player->setPosition(m_Transfer[i][(1+j)%2]->getPosition());
					}
				}
				else
				{
					m_Transfer[i][j]->setTag(999);
				}
			}
		}
	}


}
//动画加载
CCActionInterval* createRFAnimation1(const char *frameName, int frameNum, float frameTime)
{
	CCAnimation *animation = CCAnimation::create();

	for (int i = 0; i<frameNum; i++)
	{
		// 字符数组 存储每一帧的文件名
		char szName[128] = { 0 };
		sprintf(szName, "%s%d.png", frameName, i);
		animation->addSpriteFrameWithFileName(szName);
	}
	animation->setDelayPerUnit(frameTime);
	animation->setRestoreOriginalFrame(true);

	return CCRepeatForever::create(CCAnimate::create(animation));
}

void DesertScene::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}

bool DesertScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	// 1 获取触摸点
	CCPoint touchPos = pTouch->getLocation();
	// 英雄移动 参数:地图,碰撞检测的图层,
	// 2 获取
	CCPoint heroPos = player->getPosition();
	// 3 求坐标差值
	float xDis = touchPos.x -heroPos.x;
	float yDis = touchPos.y -heroPos.y;
	//4判断哪一边更远 选择向哪一边走
	//通过求平方判断
	//5如果X轴反向上差值大 向左或向右走
	if (xDis*xDis > yDis*yDis)
	{
		player->move(p_Map,"walkLayer",xDis<0?HEROMOVEDIR_LEFT:HEROMOVEDIR_RIGHT);
	}
	else //否则向上或向下走
	{
		player->move(p_Map,"walkLayer",yDis<0?HEROMOVEDIR_DOWN:HEROMOVEDIR_UP);
	}
	return true;
}




void DesertScene::MonsterFactory(std::vector<CCSprite*> &monster){
	CCArray *array =p_Map->getObjectsForGroupName("object4");
	if (!array)
	{
		return;
	}
	const char*FatherPath;
	CCString* CCpath=p_Map->getObjectGroupForName("object4")->propertyNamed("path");
	if (CCpath)
	{
	FatherPath=CCpath->getCString();
	}
	
	CCDictionary *pDict = NULL;

	for (int i=0;i<array->count();i++)
	{
		pDict=(CCDictionary*)array->objectAtIndex(i);
		const char *path;

		const char* Childpath=((CCString*)pDict->objectForKey("path"))->getCString();
		if (NULL!=Childpath)
		{
			path=Childpath;
		}else{
			path=FatherPath;
		}

		std::string str=path;
		str="monster/"+str;
		path=str.c_str();

		
		CCString* C_dir_X=(CCString*)pDict->objectForKey("dirX");
		CCString*C_dir_Y=(CCString*)pDict->objectForKey("dirY");
		if (C_dir_Y&&C_dir_X)
		{
			monster.push_back(CCSprite::create(path));
			CCPoint pos=p_Map->getObjectPositionForDictionary(pDict);

			monster[i]->setPosition(pos);
			this->addChild(monster[i]);

			const int dir_X=C_dir_X->intValue();
			const int dir_Y=C_dir_Y->intValue();
			CCString* C_speed=(CCString*)pDict->objectForKey("speed");
			CCString*C_distance=(CCString*)pDict->objectForKey("distance");
			float speed=0;
			float distance=0;
			if (C_speed&&(C_distance)){
				distance=C_distance->intValue()*p_Map->getTileSize().width;
				speed=C_speed->floatValue();
				float time=distance/speed;


				//设置怪物反向
				CCString* _reverse=(CCString*)pDict->objectForKey("reverse");
				monster[i]->setTag(999);
				if (_reverse)
				{
					if (abs(dir_X)>abs(dir_Y))
					{
						monster[i]->setTag(_reverse->intValue());
					}else{
						monster[i]->setTag(_reverse->intValue()*2);
					}
					
				}

				//设置怪物动画
				CCString* _animatioin=(CCString*)pDict->objectForKey("animation");
				if (_animatioin)
				{
					if (_animatioin->intValue()==1)
					{
						std::string s_path=path;
						s_path = s_path.substr(0, s_path.length() - 6);

						
						monster[i]->runAction(createRFAnimation(s_path.c_str(), 6, 0.12f));
					}
				}

				monster[i]->runAction(CCRepeatForever::create(CCSequence::create(
					CCMoveBy::create(time,ccp(dir_X*distance,dir_Y*distance)), 
					CCCallFuncN::create(this, callfuncN_selector(DesertScene::switch_flipX)),
					CCMoveBy::create(time,ccp(-dir_X*distance,-dir_Y*distance)),
					CCCallFuncN::create(this, callfuncN_selector(DesertScene::_switch_flipX)),
					NULL)));



			}else if (C_speed&&(!C_distance))
			{
				speed=C_speed->floatValue();
				CCPoint first=p_Map->getTargetPosForCurPos("walkLayer",pos,ccp(dir_X,dir_Y));
				int a=first.x;
				int b=first.y;
				int c=pos.x;
				int d=pos.y;
				CCString* _reverse=(CCString*)pDict->objectForKey("reverse");
				monster[i]->setTag(999);
				if (_reverse)
				{
					if (abs(dir_X)>abs(dir_Y))
					{
						monster[i]->setTag(_reverse->intValue());
					}else{
						monster[i]->setTag(_reverse->intValue()*2);
					}

				}
				CCPoint last=p_Map->getTargetPosForCurPos("walkLayer",first,ccp(-dir_X,-dir_Y));
				int e=last.x;
				int f=last.y;
				CCLog("%d %d %d %d %d %d",a,b,c,d,e,f);
				float timeFirst=pos.getDistance(first)/speed;

				float timeLast =first.getDistance(last)/speed;
				/*datas data_;
				data_.timeLast=timeLast;
				data_.last=last;
				data_.monster=monster;
				data_.i=i;*/
				

				/*void * dd=&data_;*/
				


				
				/*
				void * fdf;
				fdf=&data_;*/

				/*	monster[i]->runAction(CCSequence::create(CCMoveTo::create(timeFirst,first),CCCallFuncND::create(this,SEL_CallFuncND(&DesertScene::repeatRecall),dd),NULL));*/
				monster[i]->runAction(CCRepeatForever::create(CCSequence::create(
					CCMoveTo::create(timeFirst,last), 
					CCCallFuncN::create(this, callfuncN_selector(DesertScene::switch_flipX)),
					CCMoveTo::create(timeFirst,first),
					CCCallFuncN::create(this, callfuncN_selector(DesertScene::_switch_flipX)),
					NULL)));


			}else if ((!C_speed)&&C_distance)

			{
				CCString* _reverse=(CCString*)pDict->objectForKey("reverse");
				monster[i]->setTag(999);
				if (_reverse)
				{
					if (abs(dir_X)>abs(dir_Y))
					{
						monster[i]->setTag(_reverse->intValue());
					}else{
						monster[i]->setTag(_reverse->intValue()*2);
					}

				}
				speed=500.0;
				distance=C_distance->intValue()*p_Map->getTileSize().width;
				float time=distance/speed;

				monster[i]->runAction(CCRepeatForever::create(CCSequence::create(
					CCMoveBy::create(time,ccp(dir_X*distance,dir_Y*distance)), 
					CCCallFuncN::create(this, callfuncN_selector(DesertScene::switch_flipX)),
					CCMoveBy::create(time,ccp(-dir_X*distance,-dir_Y*distance)),
					CCCallFuncN::create(this, callfuncN_selector(DesertScene::_switch_flipX)),
					NULL)));
			}else{}
						
		}
	

	}
};


void DesertScene::switch_flipX(CCNode *pSender){
	
	
	
	if (abs(((CCSprite*)pSender)->getTag())==1)
	{
		if (((CCSprite*)pSender)->getTag()>0)
		{
			((CCSprite*)pSender)->setFlipX(false);
		}else{
			((CCSprite*)pSender)->setFlipX(true);
		}
		
	}else  
	{
		if (((CCSprite*)pSender)->getTag()>0)
		{
			((CCSprite*)pSender)->setFlipY(false);
		}else{
			((CCSprite*)pSender)->setFlipY(true);
		}
		
	}
	

}
void DesertScene::_switch_flipX(CCNode *pSender){
	
	if (abs(((CCSprite*)pSender)->getTag())==1)
	{
		if (((CCSprite*)pSender)->getTag()>0)
		{
			((CCSprite*)pSender)->setFlipX(true);
		}else{
			((CCSprite*)pSender)->setFlipX(false);
		}

	}else if (((CCSprite*)pSender)->getTag()==999)
	{
	}
	else 
	{
		if (((CCSprite*)pSender)->getTag()>0)
		{
			((CCSprite*)pSender)->setFlipY(true);
		}else{
			((CCSprite*)pSender)->setFlipY(false);
		}

	}

}
//void DesertScene::repeatRecall(CCNode * pSenser ,void *data){
//	
//		
//		datas dataa=static_cast<datas>(data);
//		float timeLast=dataa.timeLast;
//		CCPoint last=dataa.last;
//		CCPoint first=dataa.first;
//		std::vector<CCSprite*> monster=dataa.monster;
//		int i=dataa.i;
//		monster[i]->runAction(CCRepeatForever::create(CCSequence::create(
//			CCMoveTo::create(timeLast,last), 
//			CCCallFuncN::create(this, callfuncN_selector(DesertScene::switch_flipX)),
//			CCMoveTo::create(timeLast,first),
//			CCCallFuncN::create(this, callfuncN_selector(DesertScene::_switch_flipX)),
//			NULL)));
//	}

CCActionInterval* DesertScene::createRFAnimation(const char *frameName, int frameNum, float frameTime)
{
	CCAnimation *animation = CCAnimation::create();

	for (int i = 1; i<frameNum; i++)
	{
		// 字符数组 存储每一帧的文件名
		char szName[128] = { 0 };
		sprintf(szName, "%s%02d.png", frameName, i);
		animation->addSpriteFrameWithFileName(szName);
	}
	animation->setDelayPerUnit(frameTime);
	animation->setRestoreOriginalFrame(true);

	return CCRepeatForever::create(CCAnimate::create(animation));
}