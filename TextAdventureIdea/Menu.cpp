#include "pch.h"
#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
Menu *Menu::instance = 0;

int Menu::Run()
{
	bIsQuitting = false;

	system("cls");
	cout << "==========================================\n";
	cout << "==           EVAN'S ADVENTURE           ==\n";
	cout << "==========================================\n";
	cout << "      [ by Evan Sullivan (zvan92) ]\n\n";
	cout << "(1) New Game\n(2) Exit Game\n\nEnter choice: ";

	int choice;
	string input;
	getline(cin, input);
	stringstream stream(input);
	stream >> choice;

	switch (choice)
	{
	case 1:
		if (Game::GetInstance()->CreatePlayer() == 1)
		{
			return 1;
		}
		Game::GetInstance()->setGameOverStatus(false);
		break;
	case 2:
		system("cls");
		cout << "Thanks for playing!\n\n";
		system("pause");
		Game::GetInstance()->setGameOverStatus(true);
		Menu::GetInstance()->setIsQuitting(true);
		break;
	default:
		return 1;
		break;
	}

	return 0;
}