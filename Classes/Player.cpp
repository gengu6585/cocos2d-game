#include "Player.h"

Player* Player::create(const char *pszFileName)
{
	Player *pobSprite = new Player();
	if (pobSprite && pobSprite->init(pszFileName))
	{
		pobSprite->autorelease();
		return pobSprite;
	}
	CC_SAFE_DELETE(pobSprite);
	return NULL;
}

bool Player::init(const char *pszFileName)
{
	if (!initWithFile(pszFileName))
	{
		return false;
	}
	// �����������
	this->setScale(0.60f);
	// ����Ĭ����ҷ���
	this->setPlayerState(HEROMOVEDIR_UP);

	fSpeed = 1000.0f;
	bIsStay = true;

	return true;
}

// �������Ƿ��򣬶����Ǳ�������������֮ǰ����
void Player::setPlayerState(const HEROMOVEDIR& dir)
{
	this->stopAllActions();

	switch (dir)
	{
	case HEROMOVEDIR_UP:
		HERODIR = HEROMOVEDIR_UP;
		this->setFlipY(false);
		this->runAction(createRFAnimation("mushianimation/mushi_up", 1, 0.12f));
		break;
	case HEROMOVEDIR_DOWN:
		HERODIR = HEROMOVEDIR_DOWN;
		this->setFlipY(true);
		this->runAction(createRFAnimation("mushianimation/mushi_up", 1, 1.2f));
		break;
	case HEROMOVEDIR_LEFT:
		HERODIR = HEROMOVEDIR_LEFT;
		this->setFlipY(false);
		this->setFlipX(true);
		this->runAction(createRFAnimation("mushianimation/mushimushi2_000", 30, 1.2f));
		break;
	case HEROMOVEDIR_RIGHT:
		HERODIR = HEROMOVEDIR_RIGHT;
		this->setFlipY(false);
		this->setFlipX(false);
		this->runAction(createRFAnimation("mushianimation/mushimushi2_000", 30, 1.2f));
		break;
	case HERO_STAY:
		bIsStay = true;
		this->setFlipX(true);
		this->runAction(createRFAnimation("mushianimation/mushimushi2_000", 30, 1.2f));
		break;
	default:
		CCLog("setPlayerState() ERROR!!!");
		break;
	}
}
// �ƶ�
void Player::move(GameMap* map, const char *layerName, const HEROMOVEDIR& dir)
{
	if (!bIsStay)
		return;

	// 1 �޸�״̬Ϊ�����ƶ�
	bIsStay = false;
	// 2 �޸ķ���
	setPlayerState(dir);
	CCPoint targetPos = map->getTargetPos(layerName, this->getPosition(), (CHECKEDDIR)dir);
	float dt = targetPos.getDistance(this->getPosition()) / fSpeed;
	this->runAction(CCSequence::create(CCMoveTo::create(dt, targetPos), CCCallFunc::create(this, callfunc_selector(Player::moveOverCallback)), NULL));
}
void Player::moveOverCallback()
{
	bIsStay = true;
}
// ����һ��ѭ��������ֱ�Ӽ���ͼƬ��֡���֣�֡����ÿһ֡ͣ��ʱ��  (һ֡����һ��ͼƬ)
CCActionInterval* Player::createRFAnimation(const char *frameName, int frameNum, float frameTime)
{
	CCAnimation *animation = CCAnimation::create();

	for (int i = 1; i<frameNum+1; i++)
	{
		// �ַ����� �洢ÿһ֡���ļ���
		char szName[128] = { 0 };
		sprintf(szName, "%s%02d.png", frameName, i);
		animation->addSpriteFrameWithFileName(szName);
	}
	animation->setDelayPerUnit(frameTime);
	animation->setRestoreOriginalFrame(true);

	return CCRepeatForever::create(CCAnimate::create(animation));
}