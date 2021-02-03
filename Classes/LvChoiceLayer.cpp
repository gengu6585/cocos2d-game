#include "LvChoiceLayer.h"
#include "LvButton.h"
#include "PlayScene.h"
#include "GameData.h"
#include "DesertScene.h"
#include "SimpleAudioEngine.h"
#include "Icon.h"
using namespace CocosDenshion;
// ��������
CCScene* LvChoiceLayer::scene()
{
	// ��������
	CCScene *scene = CCScene::create();
	// ������
	LvChoiceLayer *layer = LvChoiceLayer::create();
	// �Ѳ���ӵ�����
	scene->addChild(layer);
	// ���س���
	return scene;
}
// ��ʼ����
bool LvChoiceLayer::init()
{
	// ��ʼ���㸸��
	if (!CCLayer::init())
	{
		return false;
	}
	// ����
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(3.0f);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("lvchoice.mp3");
	
	

	if (GameData::s_iCurBigLevel == 1)
	{
		//��ʼ����һ�ر���

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
		//��ʼ���ڶ��ر���
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
		//��ʼ��Ĭ�Ϲر���

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
	//�ڵ�����ϵ���Ը��ڵ�����½�Ϊԭ��
	spBg2->setPosition(ccp(winSize.width * 1.5f, winSize.height / 2));

	sprintf(filename, "levelchoicebg/LevelChoice_%d_2.png", GameData::s_iCurBigLevel);
	CCSprite* spBg3 = CCSprite::create(filename);
	spBg1->addChild(spBg3);
	//�ڵ�����ϵ���Ը��ڵ�����½�Ϊԭ��
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
	// ������ť����
	CCArray* array = CCArray::create();
	for (int i = 0; i < 30; i++)
	{
		// �����������ǵ�����
		int starNum = GameData::getStarNum(GameData::s_iCurBigLevel, i + 1);//����
		// ��ȡ�ѹ����ص�����
		
		// �Ƿ����
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
		//���ùؿ�
		btn->setTag(i + 1);
	}
	// ͨ�����鴴���˵�
	CCMenu* menu = CCMenu::createWithArray(array);
	spBg1->addChild(menu);


	// ��������
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

// �ؿ���ť�ص�
void LvChoiceLayer::lvBtnCallback(CCObject* obj)
{

	/************************************************************************/
	/* obj:ָ�� ˭���õ�ǰ���� objָ��ð�ť						        */
	/************************************************************************/
	LvButton* btn = (LvButton*)obj;
	// ����ǰ�ؿ���ֵ
	GameData::s_iCurLvevel = btn->getTag();

	// ʵ�ֳ�����ת
	
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	CCDirector::sharedDirector()->replaceScene(DesertScene::scene());
	
	
	
	
}

// ע�ᴥ��
void LvChoiceLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}
// ������ʼ
bool LvChoiceLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}
// �����ƶ�
void LvChoiceLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	// ���ݴ������λ�����ñ���ͼ��λ��
	spBg1->setPositionX(spBg1->getPositionX()+pTouch->getDelta().x);
	// ��Сֵ
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
// ��������
void LvChoiceLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
}