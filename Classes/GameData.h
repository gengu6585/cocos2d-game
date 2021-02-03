#ifndef _GameData_H_
#define _GameData_H_
#include "cocos2d.h"
using namespace cocos2d;
class GameData
{
public:
	// 当前大关
	static int s_iCurBigLevel;
	// 当前关卡
	static int s_iCurLvevel;
	// 存档（星星的数量）。参数：大关，小关，星星数量
	static void saveStarNum(int bigIdx, int smallIdx, int starNum);
	// 读档.参数：大关，小关
	static int getStarNum(int bigIdx, int smallIdx);
	// 已过过关的数量
	static int getPassCount(int bigIdx);
	// 设置过关的数量
	static void setPassCount(int bigIdx, int passCount);

	static void returnDefault();
};
#endif