#ifndef _GameData_H_
#define _GameData_H_
#include "cocos2d.h"
using namespace cocos2d;
class GameData
{
public:
	// ��ǰ���
	static int s_iCurBigLevel;
	// ��ǰ�ؿ�
	static int s_iCurLvevel;
	// �浵�����ǵ�����������������أ�С�أ���������
	static void saveStarNum(int bigIdx, int smallIdx, int starNum);
	// ����.��������أ�С��
	static int getStarNum(int bigIdx, int smallIdx);
	// �ѹ����ص�����
	static int getPassCount(int bigIdx);
	// ���ù��ص�����
	static void setPassCount(int bigIdx, int passCount);

	static void returnDefault();
};
#endif