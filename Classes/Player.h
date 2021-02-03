#ifndef __Alibaba__Player__
#define __Alibaba__Player__

#include "cocos2d.h"
using namespace cocos2d;
#include "GameMap.h"

// 主角移动方向
enum HEROMOVEDIR
{
	HEROMOVEDIR_UP,
	HEROMOVEDIR_DOWN,
	HEROMOVEDIR_LEFT,
	HEROMOVEDIR_RIGHT,
	HERO_STAY
};

class Player : public CCSprite
{
private:
	// 移动速度
	float fSpeed;
	// 是否停止状态
	bool bIsStay;
private:
	// 创建一个循环动画，直接加载图片：帧名字，帧数，每一帧停留时间
	CCActionInterval* createRFAnimation(const char *frameName, int frameNum, float frameTime);
	// 动作执行完回调函数切换状态
	void moveOverCallback();
public:

	HEROMOVEDIR HERODIR;
	static Player* create(const char *pszFileName);
	bool init(const char *pszFileName);
	// 切换主角状态
	void setPlayerState(const HEROMOVEDIR& dir);
	// 移动 map1_1  参数 哪个地图,移动层,方向
	void move(GameMap* map, const char *layerName, const HEROMOVEDIR& dir);
};

#endif /* defined(__Alibaba__Player__) */