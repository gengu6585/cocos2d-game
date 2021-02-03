#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

USING_NS_CC;   //cocosd 命名空间 using namespace std

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// create the application instance
	// 创建应用程序实例
	AppDelegate app;
	CCEGLView* eglView = CCEGLView::sharedOpenGLView();
	eglView->setViewName("FIRST");   //设置窗口名
	eglView->setFrameSize(1334,750); //设置窗口大小
	return CCApplication::sharedApplication()->run();
}
