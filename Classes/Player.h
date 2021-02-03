#ifndef __Alibaba__Player__
#define __Alibaba__Player__

#include "cocos2d.h"
using namespace cocos2d;
#include "GameMap.h"

// �����ƶ�����
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
	// �ƶ��ٶ�
	float fSpeed;
	// �Ƿ�ֹͣ״̬
	bool bIsStay;
private:
	// ����һ��ѭ��������ֱ�Ӽ���ͼƬ��֡���֣�֡����ÿһ֡ͣ��ʱ��
	CCActionInterval* createRFAnimation(const char *frameName, int frameNum, float frameTime);
	// ����ִ����ص������л�״̬
	void moveOverCallback();
public:

	HEROMOVEDIR HERODIR;
	static Player* create(const char *pszFileName);
	bool init(const char *pszFileName);
	// �л�����״̬
	void setPlayerState(const HEROMOVEDIR& dir);
	// �ƶ� map1_1  ���� �ĸ���ͼ,�ƶ���,����
	void move(GameMap* map, const char *layerName, const HEROMOVEDIR& dir);
};

#endif /* defined(__Alibaba__Player__) */