#include "GameWindows.h"
#include"GGraphic.h"
#include "GInput.h"
#include"GameStateManager.h"
#include <dinput.h>
#include "physic.h"
#include<fmod.hpp>

//	use int main if you want to have a console to print out message
int main()
//	use WinMain if you don't want the console
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	GameWindows* gWin = GameWindows::getInstance();

	gWin->init();

	GGraphic* gGraphic = GGraphic::getInstance();
	GInput* gInput = GInput::getInstance();
	GameStateManager* gameStateManager = GameStateManager::getInstance();

	/*FMOD::System* system = NULL;
	FMOD::System_Create(&system);
	system->init(512, FMOD_INIT_NORMAL, 0);
	FMOD::Sound* sound;
	system->createSound("sound/bgmusic.wav", FMOD_DEFAULT, NULL, &sound);
	bgMusic->setMode(FMOD_LOOP_NORMAL);*/
	/*FMOD::Channel* channel;
	system->playSound(sound, NULL, false, &channel);*/
	


	while (gWin->isWindowsRunning())
	{

		/*system->update();*/
		gInput->update();
		gameStateManager->update();
		gGraphic->begin();
		gameStateManager->draw();
		gGraphic->end();
	}
	/*sound->release();*/
	gameStateManager->releaseInstance();
	gWin->releaseInstance();
	gGraphic->releaseInstance();
	gInput->releaseInstance();
	

	return 0;
}
//--------------------------------------------------------------------

