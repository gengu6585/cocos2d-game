#ifndef _LvButton_H_
#define _LvButton_H_
#include "cocos2d.h"
using namespace cocos2d;
class LvButton : public CCMenuItemSprite
{
private:
	CCPoint m_xxPoint[3];
public:
	// �������Ƿ���أ������������ڼ��أ��Ѿ����˶��ٹأ����ذ�ťͼƬ��û����ťͼƬ����ֹ��ťͼƬ�����ǵ���ͼƬ������δ����ͼƬ��this����ť�ص�����
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