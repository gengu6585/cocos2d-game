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
    CCDirector* pDirector = CCDirector::sharedDirector(); //Ѱ�ҵ���
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();



    pDirector->setOpenGLView(pEGLView);
	// ������Ļƥ��� **********
	//kResolutionExactFit:�ֱ��ʾ�ȷƥ��
	pEGLView->setDesignResolutionSize(1334,750,kResolutionExactFit);
    // turn on display FPS 

    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	glClearColor(255, 255, 255, 1.0);

    // create a scene. it's an autorelease object
    CCScene *pScene = LoadingScene::scene();

    // run
	// ����   runWithScene: ���е�һ������ ����:Ҫ���еĳ�����ָ��
    pDirector->runWithScene(pScene); 

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
// �����������Ӧ�ó��򲻻ʱ����,���е绰��ʱҲ�����
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
// ��Ӧ�ó����ٴμ���ʱ,�����ô˺���
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
