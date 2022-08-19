#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include "MapManager.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
Game *Game::instance = 0;
bool Game::gameOverStatus = false;
bool Game::gameIsInitializing = false;

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
			Player::GetInstance()->setPlayerName(name);
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

	return 0;
}

void Game::DisplayCollectItemScreen()
{
	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");
		cout << "       COLLECT ITEM        \n";
		cout << "===========================\n\n";
		ListRoomItems();
		cout << "(C) Collect Item\n";
		cout << "(Q) Return\n\n";
		cout << "Enter choice: ";

		string input;
		getline(cin, input);
		stringstream stream(input);
		char choice;
		stream >> choice;

		if (input.length() == 1 && (choice == 'c' || choice == 'C'))
		{
			bool collectConfirmed = false;

			while (!collectConfirmed)
			{
				system("cls");
				cout << "       COLLECT ITEM        \n";
				cout << "===========================\n\n";
				cout << "Collect which item?\n\n";
				ListRoomItems();
				cout << "(Q) Return\n\n";
				cout << "Enter choice: ";

				getline(cin, input);
				stringstream stream(input);
				stream >> choice;

				if (input.length() == 1)
				{
					unordered_map<std::string, Room>roomMap = MapManager::GetInstance()->GetRoomMap();
					Room* currentRoom = &roomMap[Player::GetInstance()->getCurrentLocationGridID()];
					int roomItemsCount = (int)currentRoom->GetRoomItemNames().size();
					int iChoice = (int)choice - 48;

					if (choice == 'q' || choice == 'Q')
					{
						collectConfirmed = true;
					}
					else if (iChoice > 0 && iChoice <= roomItemsCount)
					{
						int index = iChoice - 1;
						system("cls");

						std::vector<std::string> itemNames = currentRoom->GetRoomItemNames();
						std::vector<std::string>::iterator it;

						// ---- COLLECT ITEM
						std::vector<Item> roomItems = currentRoom->GetRoomItems();
						std::vector<Item>::iterator it2;
						for (it2 = roomItems.begin(); it2 < roomItems.end(); ++it2)
						{
							if (itemNames[index].compare(it2->getName()) == 0)
							{
								Item& item = (*it2);
								MapManager::GetInstance()->TransferItemToPlayer(item);
							}
						}

						// ---- COLLECT FOOD
						std::vector<Food> roomFood = currentRoom->GetRoomFood();
						std::vector<Food>::iterator it3;
						for (it3 = roomFood.begin(); it3 < roomFood.end(); ++it3)
						{
							if (itemNames[index].compare(it3->getName()) == 0)
							{
								Food& food = (*it3);
								MapManager::GetInstance()->TransferItemToPlayer(food);
							}
						}

						// ---- COLLECT POTION
						std::vector<Potion> roomPotions = currentRoom->GetRoomPotions();
						std::vector<Potion>::iterator it4;
						for (it4 = roomPotions.begin(); it4 < roomPotions.end(); ++it4)
						{
							if (itemNames[index].compare(it4->getName()) == 0)
							{
								Potion& potion = (*it4);
								MapManager::GetInstance()->TransferItemToPlayer(potion);
							}
						}

						// ---- COLLECT CHEST
						std::vector<Chest> roomChests = currentRoom->GetRoomChests();
						std::vector<Chest>::iterator it5;
						for (it5 = roomChests.begin(); it5 < roomChests.end(); ++it5)
						{
							if (itemNames[index].compare(it5->getName()) == 0)
							{
								Chest& chest = (*it5);
								system("cls");
								cout << Player::GetInstance()->getPlayerName() << " can't collect the " << chest.getName() << ".\n\n";
								system("pause");
							}
						}

						collectConfirmed = true;
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

// will need to become Key eventually
void Game::DisplayUseItemScreen(Item item)
{
	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");
		cout << "      USE ITEM     \n";
		cout << "====================\n\n";
		cout << "Use item on what?\n\n";
		ListRoomItems();
		cout << "(P) Player\n";
		cout << "(Q) Return\n\n";
		cout << "Enter choice: ";

		string input;
		getline(cin, input);
		stringstream stream(input);
		char choice;
		stream >> choice;

		if (input.length() == 1 && (choice == 'p' || choice == 'P'))
		{
			Player::GetInstance()->ConsumeItem(item);
			confirmed = true;
		}
		else if (input.length() == 1 && (choice == 'q' || choice == 'Q'))
		{
			confirmed = true;
		}
		else if (input.length() == 1) 
		{
			unordered_map<std::string, Room>roomMap = MapManager::GetInstance()->GetRoomMap();
			Room* currentRoom = &roomMap[Player::GetInstance()->getCurrentLocationGridID()];
			int roomItemsCount = (int)currentRoom->GetRoomItemNames().size();
			int iChoice = (int)choice - 48;

			if (iChoice > 0 && iChoice <= roomItemsCount)
			{
				int index = iChoice - 1;
				system("cls");

				// ---- USE KEY ON CHEST
				std::vector<std::string> itemNames = currentRoom->GetRoomItemNames();
				std::vector<std::string>::iterator it;

				std::vector<Chest> roomChests = currentRoom->GetRoomChests();
				std::vector<Chest>::iterator it2;
				for (it2 = roomChests.begin(); it2 < roomChests.end(); ++it2)
				{
					if (itemNames[index].compare(it2->getName()) == 0)
					{
						Chest& chest = (*it2);
						if (chest.CombineWithItem(item) == SUCCESS)
						{
							MapManager::GetInstance()->RemoveItem(chest);
							Player::GetInstance()->RemoveItem(item);
						}
					}
				}

				// repeat for other items

				confirmed = true;
			}
			else
			{
				continue;
			}
		}
	}
}

void Game::DisplayMapScreen()
{
	system("cls");
	cout << "    EVAN'S ADVENTURE: MAP    \n";
	cout << "=============================\n";
	cout << "     _       _ _             \n";
	cout << "[H] | |  _ _|   |    _   _   \n";
	cout << "|   | | |  _  | |_ _| |_| |_ \n";
	cout << "|   | |_| |_ _|_ _ _   _ _ _|\n";
	cout << "|   |_ _ _ _    |  _| |_ _  |\n";
	cout << "|   |_ _   _ _| |_   _|_   _|\n";
	cout << "|   |_    |  _ _|  _ _ _|   |\n";
	cout << "|     | |_| |  _ _   _ _| |_ END\n";
	cout << "[A]   |_ _  |_ _ _|_ _ _ _ _|\n";
	cout << "         START               \n";
	cout << "    [1]------------------[12]\n";
	cout << "							  \n";
	cout << "=============================\n\n";
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

			MapManager::GetInstance()->GetRoomMap().clear();
			Player::GetInstance()->ResetProgress();
			Game::GetInstance()->Init();

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
					int playerItemsCount = Player::GetInstance()->getInventoryCount();
					int iChoice = (int)choice - 48;

					if (choice == 'q' || choice == 'Q')
					{
						useConfirmed = true;
					}
					else if (iChoice > 0 && iChoice <= playerItemsCount)
					{
						int index = iChoice - 1;
						system("cls");

						// ---- USE ITEM (will become Key)
						std::vector<std::string> itemNames = Player::GetInstance()->getPlayerItemNames();
						std::vector<std::string>::iterator it;

						std::vector<Item> playerItems = Player::GetInstance()->getPlayerItems();
						std::vector<Item>::iterator it2;
						for (it2 = playerItems.begin(); it2 < playerItems.end(); ++it2)
						{
							if (itemNames[index].compare(it2->getName()) == 0)
							{
								Item& item = (*it2);
								DisplayUseItemScreen(item);
							}
						}

						// ---- USE FOOD
						std::vector<Food> playerFood = Player::GetInstance()->getPlayerFood();
						std::vector<Food>::iterator it3;
						for (it3 = playerFood.begin(); it3 < playerFood.end(); ++it3)
						{
							if (itemNames[index].compare(it3->getName()) == 0)
							{
								Food& food = (*it3);
								Player::GetInstance()->ConsumeItem(food);
							}
						}

						// ---- USE POTION
						std::vector<Potion> playerPotions = Player::GetInstance()->getPlayerPotions();
						std::vector<Potion>::iterator it4;
						for (it4 = playerPotions.begin(); it4 < playerPotions.end(); ++it4)
						{
							if (itemNames[index].compare(it4->getName()) == 0)
							{
								Potion& potion = (*it4);
								Player::GetInstance()->ConsumeItem(potion);
							}
						}

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
					int playerItemsCount = Player::GetInstance()->getInventoryCount();
					int iChoice = (int)choice - 48;

					if (choice == 'q' || choice == 'Q')
					{
						dropConfirmed = true;
					}
					else if (iChoice > 0 && iChoice <= playerItemsCount)
					{
						int index = iChoice - 1;
						system("cls");

						std::vector<std::string> itemNames = Player::GetInstance()->getPlayerItemNames();
						std::vector<std::string>::iterator it;

						// ---- DROP ITEMS
						std::vector<Item> playerItems = Player::GetInstance()->getPlayerItems();
						std::vector<Item>::iterator it2;
						for (it2 = playerItems.begin(); it2 < playerItems.end(); ++it2)
						{
							if (itemNames[index].compare(it2->getName()) == 0)
							{
								Item& item = (*it2);
								Player::GetInstance()->DropItem(item);
							}
						}

						// ---- DROP FOOD
						std::vector<Food> playerFood = Player::GetInstance()->getPlayerFood();
						std::vector<Food>::iterator it3;
						for (it3 = playerFood.begin(); it3 < playerFood.end(); ++it3)
						{
							if (itemNames[index].compare(it3->getName()) == 0)
							{
								Food& food = (*it3);
								Player::GetInstance()->DropItem(food);
							}
						}

						// ---- DROP POTIONS
						std::vector<Potion> playerPotions = Player::GetInstance()->getPlayerPotions();
						std::vector<Potion>::iterator it4;
						for (it4 = playerPotions.begin(); it4 < playerPotions.end(); ++it4)
						{
							if (itemNames[index].compare(it4->getName()) == 0)
							{
								Potion& potion = (*it4);
								Player::GetInstance()->DropItem(potion);
							}
						}

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
	gameIsInitializing = true;

	MapManager::GetInstance()->CreateRooms();
	Player::GetInstance()->setPlayerEnergy(100);
	Player::GetInstance()->setTurnsCompleted(0);
	Player::GetInstance()->setCurrentLocationGridID("A4");
	Player::GetInstance()->setInventoryCount(0);

	Food f;
	f.setName("Apple");
	f.setHealFactor(5);
	MapManager::GetInstance()->TransferItemToRoom(f, "A4");
	
	Potion g;
	g.setName("Poison");
	g.setDamageFactor(5);
	g.setIsPoison(true);
	MapManager::GetInstance()->TransferItemToRoom(g, "A4");

	Food h;
	h.setName("Rotten Apple");
	h.setDamageFactor(5);
	h.setIsRotten(true);
	MapManager::GetInstance()->TransferItemToRoom(h, "A4");

	Potion i;
	i.setName("Health Potion");
	i.setHealFactor(5);
	MapManager::GetInstance()->TransferItemToRoom(i, "A4");

	Chest blueChest;
	blueChest.setName("Blue Chest");
	blueChest.setIsChest(true);
	//TODO: contents
	MapManager::GetInstance()->TransferItemToRoom(blueChest, "A4");

	// will become a Key eventually
	Item blueKey;
	blueKey.setName("Blue Key");
	blueKey.setIsKey(true);
	MapManager::GetInstance()->TransferItemToRoom(blueKey, "A4");

	gameIsInitializing = false;
}

void Game::ListRoomItems()
{
	unordered_map<string, Room> roomMap = MapManager::GetInstance()->GetRoomMap();
	Room* currentRoom = &roomMap[Player::GetInstance()->getCurrentLocationGridID()];

	if (currentRoom->GetRoomItemNames().empty())
	{
		cout << "<< ROOM EMPTY >>\n";
	}
	else
	{
		int counter = 1;
		std::vector<std::string>::iterator it;
		std::vector<std::string> v1 = currentRoom->GetRoomItemNames();
		for (it = v1.begin(); it < v1.end(); it++)
		{
			cout << counter << ") " << it->c_str() << "\n";
			counter++;
		}
	}
	cout << endl;
}

void Game::ListPlayerItems()
{
	if (Player::GetInstance()->getInventoryCount() == 0)
	{
		cout << "<< EMPTY >>\n";
	}
	else
	{
		int counter = 1;
		std::vector<std::string>::iterator it;
		std::vector<std::string> v1 = Player::GetInstance()->getPlayerItemNames();
		for (it = v1.begin(); it < v1.end(); it++)
		{
			cout << counter << ") " << it->c_str() << "\n";
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
	cout << "(1) Move\n(2) Look Around\n(3) Collect Item\n(4) View Inventory\n(5) View Map\n(6) End Game\n\nEnter Choice: ";

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
		DisplayCollectItemScreen();
		break;
	case 4:
		DisplayInventoryScreen();
		break;
	case 5:
		DisplayMapScreen();
		break;
	case 6:
		DisplayEndGameScreen();
		break;
	}
}