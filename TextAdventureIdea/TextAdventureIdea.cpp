#include "pch.h"
#include "Menu.h"
#include "Game.h"
#include <iostream>
using namespace std;

void Run()
{
	bool running = true;
	while (running)
	{
		Menu::Instance()->setQuitting(false);
		int menuResult;
		do
		{
			menuResult = Menu::Instance()->Run();
		} while (menuResult == 1);

		while (Game::Instance()->getGameOverStatus() == false)
		{
			Game::Instance()->ExecuteTurn();
		}

		if (Menu::Instance()->getQuitting() == true)
		{
			running = false;
		}
	}
}

int main()
{
	Run();
}