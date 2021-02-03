#ifndef _LvButton_H_
#define _LvButton_H_
#include "cocos2d.h"
using namespace cocos2d;
class LvButton : public CCMenuItemSprite
{
private:
	CCPoint m_xxPoint[3];
public:
	// 参数：是否过关；星星数量；第几关；已经过了多少关；过关按钮图片；没过按钮图片；禁止按钮图片；星星点亮图片；星星未点亮图片；this；按钮回调函数
	static LvButton* create(bool isPass,
		int starNum,
		int level, 
		int passLvNum, 
		const char *passImage,
		const char *noPassImage,
		const char *disabledImage,
		const char *starBright,
		const char *starGray, CCObject* target, SEL_MenuHandler selector);
	bool initLvButton(const char *normalImage, const char *selectedImage, const char *disabledImage, CCObject* target, SEL_MenuHandler selector);
	bool initStar(bool isPass, int starNum, int level, int passLvNum,
		const char *starBright,
		const char *starGray);
};
#endif