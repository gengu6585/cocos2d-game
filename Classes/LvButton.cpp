#include "LvButton.h"

LvButton* LvButton::create(bool isPass, int starNum, int level, int passLvNum, 
	const char *passImage,
	const char *noPassImage,
	const char *disabledImage,
	const char *starBright,
	const char *starGray,
	CCObject* target, SEL_MenuHandler selector)
{
	LvButton* btn = new LvButton();
	if (btn)
	{
		const char * normalImage = (level == passLvNum ? noPassImage : passImage);
		const char * selectedImage = normalImage;

		if (btn->initLvButton(normalImage, selectedImage, disabledImage, target, selector) &&
			btn->initStar(isPass, starNum, level, passLvNum, starBright, starGray))
		{
			btn->autorelease();
			btn->setEnabled(isPass);
			return btn;
		}
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}
bool LvButton::initLvButton(const char *normalImage, const char *selectedImage, const char *disabledImage, CCObject* target, SEL_MenuHandler selector)
{
	CCNode *normalSprite = NULL;
	CCNode *selectedSprite = NULL;
	CCNode *disabledSprite = NULL;

	if (normalImage)
	{
		normalSprite = CCSprite::create(normalImage);
	}

	if (selectedImage)
	{
		float s = 1.1f;
		selectedSprite = CCSprite::create(selectedImage);
		selectedSprite->setScale(s);
		selectedSprite->setPosition(ccp(normalSprite->getContentSize().width*(1-s) / 2.0f,
			normalSprite->getContentSize().height*(1-s) / 2.0f));
	}

	if (disabledImage)
	{
		disabledSprite = CCSprite::create(disabledImage);
	}
	return initWithNormalSprite(normalSprite, selectedSprite, disabledSprite, target, selector);
}
bool LvButton::initStar(bool isPass, int starNum, int level, int passLvNum,
	const char *starBright,
	const char *starGray)
{
	m_xxPoint[0].x = 23;
	m_xxPoint[0].y = 9;

	m_xxPoint[1].x = 48;
	m_xxPoint[1].y = 9;

	m_xxPoint[2].x = 48+25;
	m_xxPoint[2].y = 9;

	if (isPass)
	{
		CCLabelAtlas* levelNum = CCLabelAtlas::create(
			CCString::createWithFormat("%d", level)->getCString(),
			"level_num.png", 37, 37, '0');
		this->addChild(levelNum);
		levelNum->setZOrder(1);
		levelNum->setAnchorPoint(ccp(0.5,0.5));
		levelNum->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2 );

		if (level == passLvNum)
			return true;

		CCSprite* xingxing[3];
		for (int i = 0; i < 3; i++)
		{
			xingxing[i] = CCSprite::create(i<starNum ? starBright : starGray);
			this->addChild(xingxing[i]);
			xingxing[i]->setPosition(m_xxPoint[i]);
			xingxing[i]->setScale(0.7f);
			xingxing[i]->setZOrder(1);
			if (i == 1)
				xingxing[i]->setZOrder(2);
		}
	}
	return true;
}