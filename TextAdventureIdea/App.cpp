#include "pch.h"
#include "MapManager.h"
#include "Menu.h"
#include "GameManager.h"
#include <iostream>

using namespace std;

void Run()
{
	bool running = true;

	GameManager::GetInstance()->Init();

	while (running)
	{
		Menu::GetInstance()->setIsQuitting(false);
		int menuResult;
		do
		{
			menuResult = Menu::GetInstance()->Run();
		} while (menuResult == 1);

		while (GameManager::GetInstance()->getGameOverStatus() == false)
		{
			GameManager::GetInstance()->StartPlayerTurn();
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