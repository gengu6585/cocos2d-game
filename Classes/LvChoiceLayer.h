// 预编译处理：防止头文件被重复引用
#ifndef __LvChoiceLayer_H__
#define __LvChoiceLayer_H__
#include "cocos2d.h"
using namespace cocos2d;

class LvChoiceLayer : public cocos2d::CCLayer
{
private:
	CCMenuItemSprite* Reback;			//跳转到ToSnow的按钮
	CCSprite*        NoTouchReback;   //ToSnow没有按下的状态
	CCSprite*        OnTouchReback;   //ToSnow按下的状态

	CCMenu*			 IconMenu;

	CCSprite* spBg1;
	// 关卡坐标的数组
	CCPoint lvPos[30];
public:

	void choiceIcon(CCObject* pSender);
	// 初始化
	virtual bool init();
	// 创建场景
	static cocos2d::CCScene* scene();
	// 宏模板创建本类对象：宏参
	CREATE_FUNC(LvChoiceLayer);


	// 注册触摸
	virtual void registerWithTouchDispatcher(void);
	// 触摸开始
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	// 触摸移动
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	// 触摸结束
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	// 关卡按钮回调
	void lvBtnCallback(CCObject* obj);
};
#endif
