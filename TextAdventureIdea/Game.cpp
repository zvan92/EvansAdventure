#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include "FileManager.h"
#include "MapManager.h"
#include "Food.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Game *Game::instance = 0;

bool Game::gameOverStatus = false;

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

int Game::CreatePlayer()
{
	system("cls");

	string name;

	bool nameConfirmed = false;
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
		if (!nameConfirmed)
		{
			getline(cin, name);

			if (name == "esc")
			{
				confirmed = true;
				return 1;
			}
			else
			{
				nameConfirmed = true;
			}
		}
		else
		{
			cout << name << "\n";
		}

		cout << "\nAre you sure? (Y/N): ";

		getline(cin, input);
		stringstream stream(input);
		stream >> choice;

		if (input.length() == 1 && (choice == 'y' || choice == 'Y'))
		{
			confirmed = true;
		}
		else if (input.length() == 1 && (choice == 'n' || choice == 'N'))
		{
			nameConfirmed = false;
		}
		else
		{
			continue;
		}
	}

	Player::GetInstance()->setPlayerName(name);
	Player::GetInstance()->setPlayerEnergy(100);
	Player::GetInstance()->setTurnsCompleted(0);
	Player::GetInstance()->setCurrentLocationGridID("A4");

	return 0;
}

void Game::DisplayMapScreen()
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

void Game::DisplayEndGameScreen()
{
	bool confirmed = false;

	while (!confirmed)
	{
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

		if (input.length() == 1 && (choice == 'y' || choice == 'Y'))
		{
			gameOverStatus = true;
			confirmed = true;
		}
		if (input.length() == 1 && (choice == 'n' || choice == 'N'))
		{
			confirmed = true;
		}
		else
		{
			continue;
		}
	}

}

void Game::DisplayInventoryScreen()
{
	/*TODO:
	#3) for use item:
		-> ask which item # they want to use it on (including room items)
		-> call MapManager::ListRoomItems() for using on room items
	*/

	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");
		cout << "      PLAYER INVENTORY     \n";
		cout << "===========================\n\n";
		ListPlayerItems();
		cout << "(U) Use Item\n";
		cout << "(D) Drop Item\n";
		cout << "(Q) Return\n\n";
		cout << "Enter choice: ";

		string input;
		getline(cin, input);
		stringstream stream(input);
		char choice;
		stream >> choice;

		if (input.length() == 1 && (choice == 'u' || choice == 'U'))
		{
			bool useConfirmed = false;

			while (!useConfirmed)
			{
				system("cls");
				cout << "      PLAYER INVENTORY     \n";
				cout << "===========================\n\n";
				cout << "Use which item?\n\n";
				ListPlayerItems();
				cout << "(Q) Return\n\n";
				cout << "Enter choice: ";

				getline(cin, input);
				stringstream stream(input);
				stream >> choice;

				if (input.length() == 1)
				{
					int playerItemsSize = (int)Player::GetInstance()->getPlayerItems().size();
					int iChoice = (int)choice - 48;

					if (choice == 'q' || choice == 'Q')
					{
						useConfirmed = true;
					}
					else if (iChoice > 0 && iChoice <= playerItemsSize)
					{
						int element = iChoice - 1;
						system("cls");

						//TODO: testing if item is used on player
						Item item(Player::GetInstance()->getPlayerItems().at(element));
						if (item.getIsFood())
						{
							Food& food = (Food&)UnpackItem(item);
							Player::GetInstance()->ConsumeItem(food);
						}
						else
						{
							Player::GetInstance()->ConsumeItem(item);
						}
						//TODO: implement "Use On" action branch

						useConfirmed = true;
						confirmed = true;
					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
		}
		else if (input.length() == 1 && (choice == 'd' || choice == 'D'))
		{
			bool dropConfirmed = false;

			while (!dropConfirmed)
			{
				system("cls");
				cout << "      PLAYER INVENTORY     \n";
				cout << "===========================\n\n";
				cout << "Drop which item?\n\n";
				ListPlayerItems();
				cout << "(Q) Return\n\n";
				cout << "Enter choice: ";

				getline(cin, input);
				stringstream stream(input);
				stream >> choice;

				if (input.length() == 1)
				{
					int playerItemsSize = (int)Player::GetInstance()->getPlayerItems().size();
					int iChoice = (int)choice - 48;

					if (choice == 'q' || choice == 'Q')
					{
						dropConfirmed = true;
					}
					else if (iChoice > 0 && iChoice <= playerItemsSize)
					{
						int element = iChoice - 1;
						string itemName = Player::GetInstance()->getPlayerItems().at(element).getName();
						system("cls");

						Player::GetInstance()->DropItem(Player::GetInstance()->getPlayerItems().at(element));
						cout << Player::GetInstance()->getPlayerName() << " dropped the " << itemName << ".\n\n";
						system("PAUSE");

						dropConfirmed = true;
						confirmed = true;
					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
		}
		else if (input.length() == 1 && (choice == 'q' || choice == 'Q'))
		{
			confirmed = true;
		}
		else
		{
			continue;
		}
	}
}

void Game::Init()
{
	MapManager::GetInstance()->CreateRooms();

	//TODO: testing addition of items to player inventory
	Food f;
	f.setHealFactor(5);
	f.setName("Apple");
	f.setIsFood(true);
	Player::GetInstance()->AddItemToInventory(f);
	

	Item g;
	g.setName("Poison");
	g.setDamageFactor(5);
	Player::GetInstance()->AddItemToInventory(g);

	Food h;
	h.setDamageFactor(5);
	h.setName("Rotten Apple");
	h.setIsFood(true);
	Player::GetInstance()->AddItemToInventory(h);

	Item i;
	i.setHealFactor(5);
	i.setName("Health Potion");
	Player::GetInstance()->AddItemToInventory(i);

	Food j;
	j.setHealFactor(5);
	j.setName("Hamburger");
	j.setIsFood(true);
	Player::GetInstance()->AddItemToInventory(j);

	Item k;
	k.setName("T-Shirt");
	Player::GetInstance()->AddItemToInventory(k);
}

void Game::ListPlayerItems()
{
	if ((int)Player::GetInstance()->getPlayerItems().size() == 0)
	{
		cout << "(EMPTY)\n";
	}
	else
	{
		int counter = 1;
		std::vector<Item>::iterator it;
		std::vector<Item> v = Player::GetInstance()->getPlayerItems();
		for (it = v.begin(); it < v.end(); it++)
		{
			cout << " " << counter << ") " << it->getName() << "\n";
			counter++;
		}
	}
	cout << endl;
}

int Game::PromptForTurnAction()
{
	system("cls");
	cout << "Player health: " << Player::GetInstance()->getPlayerEnergy() << "\n";
	cout << "Turns completed: " << Player::GetInstance()->getTurnsCompleted() << "\n\n";
	cout << "What would you like to do, " << Player::GetInstance()->getPlayerName() << "?\n\n";
	cout << "(1) Move\n(2) Look Around\n(3) View Inventory\n(4) View Map\n(5) Save Progress\n(6) End Game\n\nEnter Choice: ";

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

void Game::PromptForDirection()
{
	bool confirmed = false;

	while (!confirmed)
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

		if (input.length() != 1 && (choice < 1 && choice > 5))
		{
			continue;
		}
		else
		{
			switch (choice)
			{
			case 1:
				system("cls");
				Player::GetInstance()->MoveNorth();
				confirmed = true;
				break;
			case 2:
				system("cls");
				Player::GetInstance()->MoveSouth();
				confirmed = true;
				break;
			case 3:
				system("cls");
				Player::GetInstance()->MoveEast();
				confirmed = true;
				break;
			case 4:
				system("cls");
				Player::GetInstance()->MoveWest();
				confirmed = true;
				break;
			case 5:
				confirmed = true;
				break;
			}
		}
	}
}

void Game::SaveProgress()
{
	FileManager::GetInstance()->PromptForSave();
}

void Game::StartPlayerTurn()
{
	//TODO: make better "game win" event
	if (Player::GetInstance()->getCurrentLocationGridID() == "B13")
	{
		system("cls");
		cout << "You've escaped! Congratulations!\n\n(You can keep wandering around if you want, though.)\n\n";
		system("pause");
	}
	system("cls");

	//TODO: make better "game lose" event
	if (Player::GetInstance()->getPlayerEnergy() <= 0)
	{
		system("cls");
		cout << "You've died. Better luck next time.\n\n";
		system("pause");

		gameOverStatus = true;
	}

	int choice = 0;
	while (choice == 0)
	{
		choice = PromptForTurnAction();
	}

	switch (choice)
	{
	case 1:
		PromptForDirection();
		break;
	case 2:
		Player::GetInstance()->LookAround();
		system("PAUSE");
		break;
	case 3:
		DisplayInventoryScreen();
		break;
	case 4:
		DisplayMapScreen();
		break;
	case 5:
		SaveProgress();
		break;
	case 6:
		DisplayEndGameScreen();
		break;
	}
}

Food Game::UnpackItem(Item& item)
{
	return Food(item);
}