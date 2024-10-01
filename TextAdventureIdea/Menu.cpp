#include "pch.h"
#include "Menu.h"
#include "GameManager.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
Menu *Menu::instance = 0;

int Menu::Run()
{
	bIsQuitting = false;

	system("cls");
	cout << "======================\n";
	cout << "== EVAN'S ADVENTURE ==\n";
	cout << "======================\n";
	cout << "by Evan Sullivan (zvan92)\n\n";
	cout << "(N) New Game\n(Q) Quit Game\n\nEnter choice: ";

	char choice;
	string input;
	getline(cin, input);
	stringstream stream(input);

	if (input.length() == 1)
	{
		stream >> choice;
		switch (choice)
		{
		case 'n':
			if (GameManager::GetInstance()->CreatePlayer() == 1)
			{
				return 1;
			}
			GameManager::GetInstance()->setGameOverStatus(false);
			break;
		case 'N':
			if (GameManager::GetInstance()->CreatePlayer() == 1)
			{
				return 1;
			}
			GameManager::GetInstance()->setGameOverStatus(false);
			break;
		case 'q':
			system("cls");
			cout << "Thanks for playing!\n\n";
			system("pause");
			GameManager::GetInstance()->setGameOverStatus(true);
			Menu::GetInstance()->setIsQuitting(true);
			break;
		case 'Q':
			system("cls");
			cout << "Thanks for playing!\n\n";
			system("pause");
			GameManager::GetInstance()->setGameOverStatus(true);
			Menu::GetInstance()->setIsQuitting(true);
			break;
		default:
			return 1;
			break;
		}
	}
	else
	{
		return 1;
	}

	return 0;
}