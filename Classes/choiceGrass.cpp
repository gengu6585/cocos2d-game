#include "choiceGrass.h"
#include "Icon.h"
#include "SimpleAudioEngine.h"
#include "Playscene.h"
#include "GameMenu.h"
#include "DesertScene.h"
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
// ��������
CCScene* choiceGrass::scene()
{
	//����һ������
	CCScene* pscene =CCScene::create();
	//����һ����ǰ���͵Ĳ�
	choiceGrass* player = choiceGrass::create();
	//������Ϊ�ӽڵ���ӵ�����
	pscene->addChild(player);
	//������ָ�뷵��
	return pscene;
}
//��ʼ��
bool choiceGrass::init()
{
	//��������ʼ��ʧ�� ����false
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