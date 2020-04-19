#include "pch.h"
#include "MapManager.h"
#include "Menu.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Run()
{
	bool running = true;

	Game::GetInstance()->Init();

	while (running)
	{
		Menu::GetInstance()->setIsQuitting(false);
		int menuResult;
		do
		{
			menuResult = Menu::GetInstance()->Run();
		} while (menuResult == 1);

		while (Game::GetInstance()->getGameOverStatus() == false)
		{
			Game::GetInstance()->StartPlayerTurn();
		}

		if (Menu::GetInstance()->getIsQuitting() == true)
		{
			running = false;
		}
	}
}

int main()
{
	Run();
}