// Ԥ���봦����ֹͷ�ļ����ظ�����
#ifndef __LvChoiceLayer_H__
#define __LvChoiceLayer_H__
#include "cocos2d.h"
using namespace cocos2d;

class LvChoiceLayer : public cocos2d::CCLayer
{
private:
	CCMenuItemSprite* Reback;			//��ת��ToSnow�İ�ť
	CCSprite*        NoTouchReback;   //ToSnowû�а��µ�״̬
	CCSprite*        OnTouchReback;   //ToSnow���µ�״̬

	CCMenu*			 IconMenu;

	CCSprite* spBg1;
	// �ؿ����������
	CCPoint lvPos[30];
public:

	void choiceIcon(CCObject* pSender);
	// ��ʼ��
	virtual bool init();
	// ��������
	static cocos2d::CCScene* scene();
	// ��ģ�崴��������󣺺��
	CREATE_FUNC(LvChoiceLayer);


	// ע�ᴥ��
	virtual void registerWithTouchDispatcher(void);
	// ������ʼ
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	// �����ƶ�
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	// ��������
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	// �ؿ���ť�ص�
	void lvBtnCallback(CCObject* obj);
};
#endif
