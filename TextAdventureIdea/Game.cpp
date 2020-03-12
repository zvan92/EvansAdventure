#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include "FileManager.h"
#include "MapManager.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Game *Game::instance = 0;

bool Game::gameOverStatus = false;

void Game::Initialize()
{
	MapManager::GetInstance()->CreateRooms();
}

void Game::ExecuteTurn() 
{
	//TODO: make better "game win" event
	if (Player::GetInstance()->getCurrentLocationGridID() == "B13")
	{
		system("cls");
		cout << "You've escaped! Congratulations!\n\n";
		system("pause");
	}
	system("cls");

	int choice = 0;
	while (choice == 0)
	{
		choice = PromptForChoice();
	}

	switch (choice)
	{
	case 1:
		system("cls");
		PromptForDirection();
		break;
	case 2:
		system("cls");
		Player::GetInstance()->LookAround();
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
		system("PAUSE");
		break;
	case 3:
		system("cls");
		cout << "(" << Player::GetInstance()->getPlayerName() << " uses an item)\n\n";
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
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
		cout << "All unsaved progress will be lost.\n\nAre you sure, " << Player::GetInstance()->getPlayerName() << "? (Y/N): ";

		string input;
		char choice;
		getline(cin, input);
		stringstream stream(input);
		stream >> choice;

		if (input.length() == 0 || input.length() > 1 ||
			input.length() == 1 && choice != 'n' && choice != 'N' &&
			choice != 'y' && choice != 'Y')
		{
			system("cls");
			cout << "Invalid selection.\n\n";
			system("pause");
			break;
		}
		if (input.length() == 1 && choice == 'n' || input.length() == 1 && choice == 'N')
		{
			break;
		}

		Player::GetInstance()->setPlayerName("");
		Player::GetInstance()->setPlayerHealth(0);

		gameOverStatus = true;
	}
}

int Game::PromptForChoice()
{
	system("cls");
	cout << "Turns completed: " << Player::GetInstance()->getTurnsCompleted() << "\n\n";
	cout << "What would you like to do, " << Player::GetInstance()->getPlayerName() << "?\n\n";
	cout << "(1) Move\n(2) Look Around\n(3) Use Item\n(4) View Map\n(5) Save Progress\n(6) End Game\n\nEnter Choice: ";

	string input;
	int choice;
	getline(cin, input);
	stringstream stream(input);
	stream >> choice;

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

	bool confirmed = false;
	while (!confirmed)
	{
		system("cls");
		cout << "==========================================\n";
		cout << "==           EVAN'S ADVENTURE           ==\n";
		cout << "==========================================\n";
		cout << "               [ New Game ]\n\n";
		cout << "Enter character name or type 'esc' to cancel:\n\n";

		string input;
		char choice;
		getline(cin, name);

		if (name == "esc")
		{
			return 1;
		}

		cout << "\nAre you sure? (Y/N): ";

		getline(cin, input);
		stringstream stream(input);
		stream >> choice;

		if (input.length() == 1 && choice == 'y' || input.length() == 1 && choice == 'Y')
		{
			confirmed = true;
		}
		if (input.length() == 0 || input.length() > 1 || 
			input.length() == 1 && choice != 'n' && choice != 'N' &&
			choice != 'y' && choice != 'Y')
		{
			system("cls");
			cout << "Invalid selection.\n\n";
			system("pause");
		}
	}
	
	Player::GetInstance()->setPlayerName(name);
	Player::GetInstance()->setPlayerHealth(100);
	Player::GetInstance()->setTurnsCompleted(0);
	Player::GetInstance()->setCurrentLocationGridID("A4");

	return 0;
}

void Game::SaveProgress()
{
	FileManager::GetInstance()->PromptForSave();
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

//void Game::MoveEast()
//{
//	if (CheckForCollision("east"))
//	{
//		cout << "You cannot move East.\n\n";
//	}
//	else
//	{
//		string s = Player::GetInstance()->getCurrentLocationGridID();
//		int yValue1 = NULL;
//		int yValue2 = NULL;
//
//		//if our first digit is 9, automatically make number = 10
//		if (s[1] == '9')
//		{
//			s[1] = '1';
//			s.append("0");
//		}
//		else
//		{
//			//if y-coordinate is 2 digit number, make sure first digit is 1
//			if (s[2] != NULL)
//			{
//				yValue1 = 1;
//				yValue2 = (int)s[2];
//			}
//			//and for one digit numbers do this
//			else
//			{
//				yValue1 = (int)s[1];
//			}
//
//			//move east on the grid
//			if (s[2] != NULL)
//			{
//				yValue2++;
//			}
//			else
//			{
//				yValue1++;
//			}
//
//			if (s[2] != NULL)
//			{
//				s[2] = yValue2;
//			}
//			else
//			{
//				s[1] = yValue1;
//			}
//		}
//
//		cout << Player::GetInstance()->getPlayerName() << " moved East.\n\n";
//
//		Player::GetInstance()->setCurrentLocationGridID(s);
//		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
//	}
//	
//	system("pause");
//}
//
//void Game::MoveWest()
//{
//	if (CheckForCollision("west"))
//	{
//		cout << "You cannot move West.\n\n";
//	}
//	else
//	{
//		string s = Player::GetInstance()->getCurrentLocationGridID();
//		int yValue1 = NULL;
//		int yValue2 = NULL;
//
//		if (s[1] == '1' && s[2] == '0')
//		{
//			s[1] = '9';
//			s.erase(s.begin() + 2);
//		}
//		else
//		{
//			if (s[2] != NULL)
//			{
//				yValue1 = 1;
//				yValue2 = (int)s[2];
//			}
//			else
//			{
//				yValue1 = (int)s[1];
//			}
//
//			if (s[2] != NULL)
//			{
//				yValue2--;
//			}
//			else
//			{
//				yValue1--;
//			}
//
//			if (s[2] != NULL)
//			{
//				s[2] = yValue2;
//			}
//			else
//			{
//				s[1] = yValue1;
//			}
//		}
//
//		cout << Player::GetInstance()->getPlayerName() << " moved West.\n\n";
//
//		Player::GetInstance()->setCurrentLocationGridID(s);
//		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
//	}
//
//	system("pause");
//}
//
//void Game::MoveNorth()
//{
//	if (CheckForCollision("north"))
//	{
//		cout << "You cannot move North.\n\n";
//	}
//	else
//	{
//		string s = Player::GetInstance()->getCurrentLocationGridID();
//		char xValue = s[0];
//
//		xValue++;
//		s[0] = xValue;
//
//		cout << Player::GetInstance()->getPlayerName() << " moved North.\n\n";
//
//		Player::GetInstance()->setCurrentLocationGridID(s);
//		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
//	}
//
//	system("pause");
//}
//
//void Game::MoveSouth()
//{
//	if (CheckForCollision("south"))
//	{
//		cout << "You cannot move South.\n\n";
//	}
//	else
//	{
//		string s = Player::GetInstance()->getCurrentLocationGridID();
//		char xValue = s[0];
//
//		xValue--;
//		s[0] = xValue;
//
//		cout << Player::GetInstance()->getPlayerName() << " moved South.\n\n";
//
//		Player::GetInstance()->setCurrentLocationGridID(s);
//		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
//	}
//	
//	system("pause");
//}

void Game::PromptForDirection()
{
	system("cls");
	cout << "Move in which direction?\n\n";
	cout << "(1) North\n(2) South\n(3) East\n(4) West\n(5) Cancel\n\n";
	cout << "Enter choice: ";

	int choice;
	string input;
	getline(cin, input);
	stringstream stream(input);
	stream >> choice;

	if (input.length() == 0 || input.length() > 1 ||
		input.length() == 1 && choice != 1 && 
		choice != 2 && choice != 3 && 
		choice != 4 && choice != 5)
	{
		system("cls");
		cout << "Invalid selection.\n\n";
		system("pause");
		PromptForDirection(); //call recursively if input is invalid
	}
	else
	{
		switch (choice)
		{
		case 1:
			system("cls");
			Player::GetInstance()->MoveNorth();
			break;
		case 2:
			system("cls");
			Player::GetInstance()->MoveSouth();
			break;
		case 3:
			system("cls");
			Player::GetInstance()->MoveEast();
			break;
		case 4:
			system("cls");
			Player::GetInstance()->MoveWest();
			break;
		case 5:
			break;
		}
	}
}

bool Game::CheckForCollision(MapManager::Direction direction)
{
	switch (direction)
	{
	case MapManager::Direction::WEST:
	{
		if (MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasWestWall() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case MapManager::Direction::NORTH:
	{
		if (MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasNorthWall() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case MapManager::Direction::EAST:
	{
		if (MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasEastWall() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case MapManager::Direction::SOUTH:
	{
		if (MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasSouthWall() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	}

	return false;
}