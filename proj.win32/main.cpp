#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

USING_NS_CC;   //cocosd �����ռ� using namespace std

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// create the application instance
	// ����Ӧ�ó���ʵ��
	AppDelegate app;
	CCEGLView* eglView = CCEGLView::sharedOpenGLView();
	eglView->setViewName("FIRST");   //���ô�����
	eglView->setFrameSize(1334,750); //���ô��ڴ�С
	return CCApplication::sharedApplication()->run();
}
