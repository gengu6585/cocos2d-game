#pragma once    //保证后面的代码只执行一次
#include "cocos2d.h"
using namespace cocos2d;
class SetScene: public cocos2d::CCLayer 
{
public:

	// 创建场景
	static cocos2d::CCScene* scene();

	// 初始化
	virtual bool init();


	// 创建层
	CREATE_FUNC(SetScene);

	//切换到Hello界面的按钮的回调函数
	// void 函数名(CCObjec pSender);
	void ChangeSceneMenu(CCObject* pSender);
	//重写父类的update方法
	//参数:float date
	/*void update(float date)override;*/

	void MyUpdate(float date);
private:
	CCMenuItemSprite* ToHello;			//跳转到Scene1的按钮
	CCSprite*        NoTouchToHello;   //ToScene1没有按下的状态
	CCSprite*        OnTouchToHello;   //ToScene1按下的状态
	CCMenuItemSprite* CloseMusic;			//跳转到ToDesert的按钮
	CCSprite*        NoTouchCloseMusic;   //ToDesert没有按下的状态
	CCSprite*        OnTouchCloseMusic;   //ToDesert按下的状态

	cocos2d::CCSprite* Bug;

	

	CCMenu*			 ChangeScene_A;
	

};
/*
调度器:
1 默认调度器:开启之后每一帧都会调用一次

2 自定义调度器:可以控制调用的次数、时间间隔
	步骤一： 写好一个调度器
		①在头文件声明方法.h
		void 方法名字(float date);
		②在源文件实现这个方法.cpp
		void 类名::方法名字(float date)
		{
			函数体:
		}
	步骤二： 使用调度器
3 单次调度器：开启之后只调用一次
	
*/

/*
添加音频文件:简单音频引擎
1 背景音乐
	播放 参数:音乐文件路径,是否重复播放
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/MenuMusic.mp3",true)
	暂停
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic()
	停止
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic()
	恢复
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic()
	结束
	设置音量
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.8f);
2 音效
	SimpleAudioEngine::sharedEngine()->playEffect("");


*/