#pragma once    //��֤����Ĵ���ִֻ��һ��
#include "cocos2d.h"

using namespace cocos2d;
class choiceGrass: public cocos2d::CCLayer 
{
public:

	// ��������
	static cocos2d::CCScene* scene();

	// ��ʼ��
	virtual bool init();
	// ������
	CREATE_FUNC(choiceGrass);

	// ע�ᴥ����
	virtual void registerWithTouchDispatcher(void);

	/*virtual void */
private:
	CCSprite* bgpicture1;
	
	CCPoint lvPos[20];



	
};