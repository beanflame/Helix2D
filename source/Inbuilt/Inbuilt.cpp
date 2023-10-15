#include "h2dInbuilt.h"
#include "h2dBase.h"
#include "h2dImage.h"
#include <iostream>
#include <thread>
#include <mutex>
using namespace helix2d::Inbuilt;

Initialize Initialize::init;
bool Initialize::bGameDone = false;

void helix2d::Inbuilt::Initialize::function(void)
{
	//��֤�ļ���������lib
}

Initialize::Initialize()
{
	auto hr = CoInitializeEx(
		NULL,
		COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE
	);

	Renderer::createDeviceIndependentResources();
}

helix2d::Inbuilt::Initialize::~Initialize()
{
	bGameDone = true;
	Window::bAllWindowDone = true;

	//�ȴ������߳̾���ر�
	Sleep(1);
	
	Window::uninit();
	//Image::uninit();		//��Ȼ�ҽ���������⣬�Ǿ��ò���ϵͳȥ�����~~~
}