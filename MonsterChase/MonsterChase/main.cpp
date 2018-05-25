#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <Windows.h>

#if defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif // _DEBUG
#include "Engine.h"
#include "../GLib/GLib.h"
#include <iostream>
#include "Timer.h"
#include "ConsolePrint.h"
#include "Matrix4.h"

int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow)
{

	bool isSuccess = Engine::EngineMain::getInstance()->init(i_hInstance, i_hPrevInstance,i_lpCmdLine,i_nCmdShow);
	bool bQuit = false;
	Engine::Timer timer;
	timer.setFrequencyForSystem();
	double dt = 16.0f;
	DWORD word = 10;


    while (true && !bQuit)
	{
		timer.startTimer();
		GLib::Service(bQuit);
		Engine::EngineMain::getInstance()->run(dt);
		timer.calculateFrameTimeInMs();
		dt = timer.getframeTimeInMs();
		
	}

	Engine::EngineMain::getInstance()->shutDown();

#if defined _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG
	return 0;
}