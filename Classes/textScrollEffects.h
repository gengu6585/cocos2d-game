#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class textScrollEffects
{
public:


	static  void create(CCLayer* layer,CCPoint pos,const char path[]);
	void init(CCLayer* layer,CCPoint pos,const char path[]);
	textScrollEffects();
	~textScrollEffects();
	
private:
	CCLabelTTF *plabelArray[300];  //�������ڴ�ű�ǩ
	int sum;  //����
	double delay;  //ÿ������֮����ӳ�
};

