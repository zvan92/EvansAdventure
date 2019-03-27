#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include "FileManager.h"
#include "MapManager.h"
#include <iostream>
#include <string>

using namespace std;

Game *Game::instance = 0;
bool Game::gameOverStatus = false;

void Game::Init()
{
	MapManager::Instance()->CreateRooms();
}

void Game::ExecuteTurn() 
{
	system("cls");

	int choice = 0;

	while (choice == 0)
	{
		choice = PromptUserChoice();
	}

	switch (choice)
	{
	case 1:
		system("cls");
		PromptForDirection();
		break;
	case 2:
		system("cls");
		LookAround();
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() + 1);
		system("PAUSE");
		break;
	case 3:
		system("cls");
		cout << "(" << Player::Instance()->getPlayerName() << " uses an item)\n\n";
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() + 1);
		system("PAUSE");
		break;
	case 4:
		system("cls");
		DisplayMap();
		break;
	case 5:
		SaveProgress();
		break;
	case 6:
		system("cls");
		cout << "==========================================\n";
		cout << "==           EVAN'S ADVENTURE           ==\n";
		cout << "==========================================\n";
		cout << "               [ End Game ]\n\n";
		char choice;
		cout << "All unsaved progress will be lost.\n\nAre you sure, " << Player::Instance()->getPlayerName() << "? (Y/N): ";
		cin >> choice;
		if (choice == 'n')
		{
			break;
		}

		Player::Instance()->setPlayerName("");
		Player::Instance()->setPlayerHealth(0);

		gameOverStatus = true;
	}
}

int Game::PromptUserChoice()
{
	system("cls");

	int choice;

	cout << "Turns completed: " << Player::Instance()->getTurnsCompleted() << "\n\n";
	cout << "What would you like to do, " << Player::Instance()->getPlayerName() << "?\n\n";
	cout << "(1) Move\n(2) Look Around\n(3) Use Item\n(4) View Map\n(5) Save Progress\n(6) End Game\n\nEnter Choice: ";
	cin >> choice;

	if (choice == 1 ||
		choice == 2 ||
		choice == 3 ||
		choice == 4 ||
		choice == 5 ||
		choice == 6)
	{
		return choice;
	}
	else
	{
		return 0;
	}
}

int Game::CreatePlayer()
{
	system("cls");

	string name;
	char choice;
	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");

		cout << "==========================================\n";
		cout << "==           EVAN'S ADVENTURE           ==\n";
		cout << "==========================================\n";
		cout << "               [ New Game ]\n\n";
		cout << "Enter player name (without spaces)\nor type 'esc' to cancel:\n\n";
		cin >> name;
		if (name == "esc")
		{
			return 1;
		}

		cout << "\nAre you sure? (Y/N): ";
		cin >> choice;
		if (choice == 'y')
		{
			confirmed = true;
		}
	}
	
	Player::Instance()->setPlayerName(name);
	Player::Instance()->setPlayerHealth(100);
	Player::Instance()->setTurnsCompleted(0);
	Player::Instance()->setCurrentGridID("A4");

	return 0;
}

void Game::SaveProgress()
{
	FileManager::Instance()->PromptForSave();
}

void Game::DisplayMap()
{
	system("cls");

	cout << "   EVAN'S ADVENTURE: MAP  \n";
	cout << "===========================\n";
	cout << "  _       _ _             \n";
	cout << " | |  _ _|   |    _   _   \n";
	cout << " | | |  _  | |_ _| |_| |_ \n";
	cout << " | |_| |_ _|_ _ _   _ _ _|\n";
	cout << " |_ _ _ _    |  _| |_ _  |\n";
	cout << " |_ _   _ _| |_   _|_   _|\n";
	cout << " |_    |  _ _|  _ _ _|   |\n";
	cout << "   | |_| |  _ _   _ _| |_ END\n";
	cout << "   |_ _  |_ _ _|_ _ _ _ _|\n";
	cout << "      START               \n";
	cout << "===========================\n\n";

	system("pause");
}

void Game::MoveEast()
{
	string s = Player::Instance()->getCurrentGridID();
	int yValue1 = NULL;
	int yValue2 = NULL;

	//if our first digit is 9, automatically make number = 10
	if (s[1] == '9')
	{
		s[1] = '1';
		s.append("0");
	}
	else
	{
		//if y-coordinate is 2 digit number, make sure first digit is 1
		if (s[2] != NULL)
		{
			yValue1 = 1;
			yValue2 = (int)s[2];
		}
		//and for one digit numbers do this
		else
		{
			yValue1 = (int)s[1];
		}

		//move east on the grid
		if (s[2] != NULL)
		{
			yValue2++;
		}
		else
		{
			yValue1++;
		}

		if (s[2] != NULL)
		{
			s[2] = yValue2;
		}
		else
		{
			s[1] = yValue1;
		}
	}

	Player::Instance()->setCurrentGridID(s);

	cout << Player::Instance()->getPlayerName() << " moved East.\n\n";
	system("pause");
}

void Game::MoveWest()
{
	string s = Player::Instance()->getCurrentGridID();
	int yValue1 = NULL;
	int yValue2 = NULL;

	if (s[1] == '9')
	{
		s[1] = '1';
		s.append("0");
	}
	else
	{
		if (s[2] != NULL)
		{
			yValue1 = 1;
			yValue2 = (int)s[2];
		}
		else
		{
			yValue1 = (int)s[1];
		}

		if (s[2] != NULL)
		{
			yValue2--;
		}
		else
		{
			yValue1--;
		}

		if (s[2] != NULL)
		{
			s[2] = yValue2;
		}
		else
		{
			s[1] = yValue1;
		}
	}

	Player::Instance()->setCurrentGridID(s);

	cout << Player::Instance()->getPlayerName() << " moved West.\n\n";
	system("pause");
}

void Game::MoveNorth()
{
	string s = Player::Instance()->getCurrentGridID();
	char xValue = s[0];

	xValue++;
	s[0] = xValue;

	Player::Instance()->setCurrentGridID(s);

	cout << Player::Instance()->getPlayerName() << " moved North.\n\n";
	system("pause");
}

void Game::MoveSouth()
{
	string s = Player::Instance()->getCurrentGridID();
	char xValue = s[0];

	xValue--;
	s[0] = xValue;

	Player::Instance()->setCurrentGridID(s);

	cout << Player::Instance()->getPlayerName() << " moved South.\n\n";
	system("pause");
}

void Game::PromptForDirection()
{
	int choice;

	system("cls");
	cout << "Move in which direction?\n\n";
	cout << "(1) North\n(2) South\n(3) East\n(4) West\n(5) Cancel\n\n";
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		system("cls");
		MoveNorth();
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() + 1);
		break;
	case 2:
		system("cls");
		MoveSouth();
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() + 1);
		break;
	case 3:
		system("cls");
		MoveEast();
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() + 1);
		break;
	case 4:
		system("cls");
		MoveWest();
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() + 1);
		break;
	case 5:
		break;
	}
}

void Game::LookAround()
{
	MapManager::Instance()->DescribeRoom(Player::Instance()->getCurrentGridID());
}