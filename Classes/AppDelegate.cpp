#include "AppDelegate.h"
#include "GameMenu.h"
#include "LoadingScene.h"
#include "Playscene.h"
#include "Scene2.h"
#include "Icon.h"
#include "choiceGrass.h"
#include "LvChoiceLayer.h"
#include "DesertScene.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector(); //寻找导演
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();



    pDirector->setOpenGLView(pEGLView);
	// 设置屏幕匹配度 **********
	//kResolutionExactFit:分辨率精确匹配
	pEGLView->setDesignResolutionSize(1334,750,kResolutionExactFit);
    // turn on display FPS 

    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	glClearColor(255, 255, 255, 1.0);

    // create a scene. it's an autorelease object
    CCScene *pScene = LoadingScene::scene();

    // run
	// 运行   runWithScene: 运行第一个场景 参数:要运行的场景的指针
    pDirector->runWithScene(pScene); 

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
// 这个函数将在应用程序不活动时调用,当有电话来时也会调用
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
// 当应用程序再次激活时,将调用此函数
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
