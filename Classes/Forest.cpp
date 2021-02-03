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
#include "forest.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// ��������
CCScene* forest::scene()
{
	//����һ������
	CCScene* pscene =CCScene::create();
	//����һ����ǰ���͵Ĳ�
	forest* player = forest::create();
	//������Ϊ�ӽڵ���ӵ�����
	pscene->addChild(player);
	//������ָ�뷵��
	return pscene;
}
//��ʼ��
bool forest::init()
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
		menu_selector(forest::Button)); 
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
		menu_selector(forest::Button)); 
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
	// ��ñ�������״̬��
	spBoxState = CCSprite::create("UI_GoldBoxNum.png");
	this->addChild(spBoxState);
	spBoxState->setPosition(ccp(1334-90,480));
	//��ʼ������
	m_iBoxCount = 0;
	// ���ݻ�õı����������ر�����
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
	this->GameInitObject_4();
	this->GameInitObject_5();
	this->setTouchEnabled(true);




	return true;
}

void forest::Button(CCObject* pSender)
{


	SimpleAudioEngine::sharedEngine()->playEffect("game02.mp3");
	CCMenuItemSprite* lev = (CCMenuItemSprite*)pSender;
	int a =lev->getTag();

	CCDirector* director = CCDirector::sharedDirector();


	// 3 ����ָ����ת
	//lev->getTag(); //��ñ�� ֪����˭������
	switch(lev->getTag())
	{
	case 1:
		director->replaceScene(CCTransitionRotoZoom::create(1.0f,LvChoiceLayer::scene()));
		break;
	case 2:

		director->replaceScene(CCTransitionFade::create(1.0f,forest::scene()));


		break;
	case 3:
		GameData::s_iCurLvevel=GameData::s_iCurLvevel+1;
		director->replaceScene(CCTransitionFade::create(1.0f,forest::scene()));

		break;
	default:
		break;
	}
}







//��ʼ������
void forest::GameInitObject_0()
{
	//����Ӣ��
	//���ж��Ƿ����Ӣ�۶�������. ����:����������;��������
	if (p_Map->getObjectForName("object0","player"))
	{
		playerPos = p_Map->getObjectPositionForName("object0","player");

		// ������������λ�� ��Ϊ����
		player = Player::create("PlayerUp_0.png");
		player->setPosition(playerPos);

		this->addChild(player);

	}
}
//��ʼ��Կ�׺���
void forest::GameInitObject_1()
{
	//��ʼ��Կ��
	//���ж��Ƿ����Ӣ�۶�������. ����:����������;��������
	if (p_Map->getObjectForName("object1","key"))
	{
		playerPos = p_Map->getObjectPositionForName("object1","key");

		// ������������λ�� ��Ϊ����
		m_key = CCSprite::create("key.png");
		m_key->setScaleX(0.58f);
		m_key->setScaleY(0.648f);
		m_key->setPosition(playerPos);

		this->addChild(m_key);

	}
	//��ֹ���� Ұָ�� ��ָ��
	else{
		m_key = NULL;
	}

	//��ʼ����
	//���ж��Ƿ����Ӣ�۶�������. ����:����������;��������
	if (p_Map->getObjectForName("object1","exit"))
	{
		playerPos = p_Map->getObjectPositionForName("object1","exit");

		// ������������λ�� ��Ϊ����
		m_exit = CCSprite::create("exit.png");
		m_exit->setScaleX(0.198f);
		m_exit->setScaleY(0.198f);
		m_exit->setPosition(playerPos);

		this->addChild(m_exit);

	}
	//��ֹ���� Ұָ�� ��ָ��
	else{
		m_key = NULL;
	}
}
//��ʼ������
void forest::GameInitObject_2()
{
	char boxName[32] = {0};
	for (int i=0;i<3;++i)
	{
		sprintf(boxName,"box_%d",i+1);
		//�ж��Ƿ���ڶ���
		if (p_Map->getObjectForName("object2",boxName))
		{
			m_box[i] = CCSprite::create("box_0.png");
			m_box[i]->setPosition(p_Map->getObjectPositionForName("object2",boxName));
			m_box[i]->setScaleX(1.1f);
			m_box[i]->setScaleY(1.1f);
			// 1���һ������
			// 2����һ������
			CCAnimation* m_animation = CCAnimation::create();
			// 3�������Ķ������֡
			m_animation->addSpriteFrameWithFileName("box_1.png");
			m_animation->addSpriteFrameWithFileName("box_2.png");
			m_animation->addSpriteFrameWithFileName("box_3.png");
			// 4.1 ���ʱ�� ���Ŵ���: ����(�޷�������)�޸���
			m_animation->setDelayPerUnit(0.2f);
			m_animation->setLoops(-1); //����ʱΪ�����ظ� �������
			// 5������ת���ɶ���
			CCAnimate* m_animate = CCAnimate::create(m_animation);
			// 6����ִ�ж���(����)
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
//��ʼ������
void forest::GameInitObject_3()
{
	//sizeof() ����:���ڴ��С
	for (int i=0;i<(sizeof(m_trap)/sizeof(m_trap[0]));i++)
	{
		m_trap[i] = NULL;
		char trapName[32] = {0};
		sprintf(trapName,"trap_%d",i+1);
		//�ж��Ƿ���ڶ���
		if (p_Map->getObjectForName("object3",trapName))
		{
			m_trap[i] = CCSprite::create("trap_0.png");
			m_trap[i]->setPosition(p_Map->getObjectPositionForName("object3",trapName));

			this->addChild(m_trap[i]);
			//��Ӷ���

		}
	}

}
//��ʼ������
void forest::GameInitObject_4()
{
	//sizeof() ����:���ڴ��С
	for (int i=0;i<(sizeof(m_Monster)/sizeof(m_Monster[0]));i++)
	{
		m_Monster[i] = NULL;
		char MonName[32] = {0};
		sprintf(MonName,"monster_%d",i);
		//�ж��Ƿ���ڶ���
		if (p_Map->getObjectForName("object4",MonName))
		{
			m_Monster[i] = CCSprite::create("monster_0.png");
			m_Monster[i]->setPosition(p_Map->getObjectPositionForName("object4",MonName));
			this->addChild(m_Monster[i]);
			m_Monster[i]->setScale(1.5);
			//��ȡ��������
			const int DIR_X = p_Map->getCustomStr("object4",MonName,"dirX")->intValue();
			const int DIR_Y = p_Map->getCustomStr("object4",MonName,"dirY")->intValue();
			//��ȡ��������
			const int DISCOUNT = p_Map->getCustomStr("object4",MonName,"dis")->intValue();
			//��ȡʱ��
			float distance = DISCOUNT*p_Map->getTileSize().width;
			float speed = p_Map->getCustomStr("object4",MonName,"speed")->floatValue();
			float t = distance / speed;
			float xx = distance*DIR_X;
			float yy = DISCOUNT*p_Map->getTileSize().width*DIR_Y;
			//��Ӷ���
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
//��ʼ��������
void forest::GameInitObject_5()
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
				sprintf(filename,"transfer%d.png",j);
				m_Transfer[i][j] = CCSprite::create(filename);
				m_Transfer[i][j]->setTag(999);
				this->addChild(m_Transfer[i][j]);
				m_Transfer[i][j]->setScale(0.7f);
				m_Transfer[i][j]->setPosition(p_Map->getObjectPositionForName("object5",objectName));
				CCAnimation* m_animation1 = CCAnimation::create();
				m_animation1->addSpriteFrameWithFileName("transfer0.png");
				m_animation1->addSpriteFrameWithFileName("transfer1.png");
				m_animation1->addSpriteFrameWithFileName("transfer2.png");
				m_animation1->addSpriteFrameWithFileName("transfer3.png");
				m_animation1->setDelayPerUnit(0.3f);
				m_animation1->setLoops(-1);
				CCAnimate* m_animate1 = CCAnimate::create(m_animation1);
				m_Transfer[i][j]->runAction(m_animate1);
			}
		}
	}
}
//�����ײ
bool forest::playerCOllision1(CCNode* obj)
{
	// ʹ��ָ��:�����ж��Ƿ���ָ��
	if (obj!=NULL)
	{
		float xDis = player->getPositionX()-obj->getPositionX();
		float yDis = player->getPositionY()-obj->getPositionY();

		float w = p_Map->getTileSize().width; //ͼ���
		float h = p_Map->getTileSize().height;//ͼ���
		if (abs(xDis)<w && abs(yDis) <h)
		{
			return true;
		}
	}
	return false;

}

//���������
void forest::update(float dt)
{
	int sum =0;	
	isgetkey = false;
	//�ж�Կ����ײ���
	if (playerCOllision1(m_key))
	{

		this->removeChild(m_key);
		m_key =NULL;
		isgetkey = true;
	}
	//�ж�����ײ���
	if(playerCOllision1(m_exit))
	{
		if(m_key == NULL)
		{
			//����
			int oldNum = GameData::getStarNum(GameData::s_iCurBigLevel,GameData::s_iCurLvevel);
			//���ѹ��Ĺؿ�����(�޸Ľ�������)
			int passCount = GameData::getPassCount(GameData::s_iCurBigLevel);
			if (GameData::s_iCurLvevel >= passCount)
			{

				GameData::setPassCount(GameData::s_iCurBigLevel,++passCount);
			}
			m_exit =NULL;
			//�ж��Ƿ������ʷ���浵
			if (m_iBoxCount > oldNum)
			{
				GameData::saveStarNum(GameData::s_iCurBigLevel,GameData::s_iCurLvevel,m_iBoxCount);

			}

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
				menu_selector(forest::Button)); 
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
				menu_selector(forest::Button));
			ToNext->setAnchorPoint(ccp(1,1));
			ToNext->setScale(0.8f);
			ToNext->setPosition(ccp(800,350));
			ToNext->setTag(3);

			IconMenu = CCMenu::create(ReStart,ToNext,NULL);
			IconMenu->setPosition(CCPointZero);
			this->addChild(IconMenu);

			CCSprite* win_bg = CCSprite::create("win_bg.png");
			win_bg->setPosition(ccp(1334/2,750/2));
			this->addChild(win_bg);

			CCSprite* star_bg1 = CCSprite::create("StarGray.png");
			star_bg1->setPosition(ccp(550,750/1.8));
			this->addChild(star_bg1);

			CCSprite* star_bg2 = CCSprite::create("StarGray.png");
			star_bg2->setPosition(ccp(650,750/1.8));
			this->addChild(star_bg2);

			CCSprite* star_bg3 = CCSprite::create("StarGray.png");
			star_bg3->setPosition(ccp(750,750/1.8));
			this->addChild(star_bg3);

			CCSprite* star_bg4 = CCSprite::create("StarBright.png");
			star_bg4->setOpacity(0);
			CCFadeTo* fadeIn = CCFadeTo::create(3,255);

			star_bg4->runAction(fadeIn);
			star_bg4->setPosition(ccp(550,750/1.8));


			CCSprite* star_bg5 = CCSprite::create("StarBright.png");
			star_bg5->setPosition(ccp(650,750/1.8));
			star_bg5->setOpacity(0);
			CCFadeTo* fadeIn1 = CCFadeTo::create(3,255);
			star_bg5->runAction(fadeIn1);


			CCSprite* star_bg6 = CCSprite::create("StarBright.png");
			star_bg6->setPosition(ccp(750,750/1.8));
			star_bg6->setOpacity(0);
			CCFadeTo* fadeIn2 = CCFadeTo::create(3,255);
			star_bg6->runAction(fadeIn2);


			CCSprite* winmessage1 = CCSprite::create("victory0.png");
			winmessage1->setScale(0.5f);
			winmessage1->setPosition(ccp(1334/2-100,750/2));
			this->addChild(winmessage1);
			winmessage1->setVisible(false);
			CCSprite* winmessage2 = CCSprite::create("victory1.png");
			winmessage2->setScale(0.8f);
			winmessage2->setPosition(ccp(1334/2,750/1.5));
			this->addChild(winmessage2);
			winmessage2->setVisible(false);
			CCSprite* winmessage3 = CCSprite::create("victory2.png");
			winmessage3->setScale(0.8f);
			winmessage3->setPosition(ccp(1334/2,750/1.5));
			this->addChild(winmessage3);
			winmessage3->setVisible(false);
			CCSprite* winmessage4 = CCSprite::create("victory3.png");
			winmessage4->setScale(0.8f);
			winmessage4->setPosition(ccp(1334/2,750/1.5));
			this->addChild(winmessage4);
			winmessage4->setVisible(false);
			switch(sum)
			{
			case 0:
				winmessage1->setVisible(true);
				break;
			case 1:
				winmessage2->setVisible(true);
				this->addChild(star_bg4);
				break;
			case 2:
				winmessage3->setVisible(true);
				this->addChild(star_bg4);
				this->addChild(star_bg5);
				break;
			case 3:
				winmessage4->setVisible(true);
				this->addChild(star_bg4);
				this->addChild(star_bg5);
				this->addChild(star_bg6);
				break;
			default:
				break;
			}
		}
		else //���û�д�Կ��
		{
			player->setPlayerState(HERO_STAY);
			//ͨ�������ķ����޸��˵�����
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

	//������
	for (int i=0;i<3;++i)
	{
		if (playerCOllision1((m_box[i])))
		{


			m_iBoxCount++;
			// ����ui״̬��
			const char* strBoxCount = CCString::createWithFormat(
				"%d",m_iBoxCount)->getCString();
			m_boxCountAtlas->setString(strBoxCount);
			this->removeChild(m_box[i]);

			m_box[i]=NULL;
		}

	}
	/*������*/
	for (int i=0;i<sizeof(m_trap)/sizeof(m_trap[0]);++i)
	{
		if (m_trap[i] != NULL)
		{
			if (playerCOllision1(m_trap[i]))
			{
				CCDirector::sharedDirector()->replaceScene(Playscene::scene());

				m_trap[i] = NULL;
			}
		}
	}
	//������
	for (int i=0;i<sizeof(m_Monster)/sizeof(m_Monster[0]);++i)
	{
		if (m_Monster[i] != NULL)
		{
			if (playerCOllision1(m_Monster[i]))
			{
				CCDirector::sharedDirector()->replaceScene(Playscene::scene());


				m_Monster[i] = NULL;
			}
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
//��������
CCActionInterval* createRFAnimation2(const char *frameName, int frameNum, float frameTime)
{
	CCAnimation *animation = CCAnimation::create();

	for (int i = 0; i<frameNum; i++)
	{
		// �ַ����� �洢ÿһ֡���ļ���
		char szName[128] = { 0 };
		sprintf(szName, "%s%d.png", frameName, i);
		animation->addSpriteFrameWithFileName(szName);
	}
	animation->setDelayPerUnit(frameTime);
	animation->setRestoreOriginalFrame(true);

	return CCRepeatForever::create(CCAnimate::create(animation));
}

void forest::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}

bool forest::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	// 1 ��ȡ������
	CCPoint touchPos = pTouch->getLocation();
	// Ӣ���ƶ� ����:��ͼ,��ײ����ͼ��,
	// 2 ��ȡ
	CCPoint heroPos = player->getPosition();
	// 3 �������ֵ
	float xDis = touchPos.x -heroPos.x;
	float yDis = touchPos.y -heroPos.y;
	//4�ж���һ�߸�Զ ѡ������һ����
	//ͨ����ƽ���ж�
	//5���X�ᷴ���ϲ�ֵ�� �����������
	if (xDis*xDis > yDis*yDis)
	{
		player->move(p_Map,"walkLayer",xDis<0?HEROMOVEDIR_LEFT:HEROMOVEDIR_RIGHT);
	}
	else //�������ϻ�������
	{
		player->move(p_Map,"walkLayer",yDis<0?HEROMOVEDIR_DOWN:HEROMOVEDIR_UP);
	}
	return true;
}