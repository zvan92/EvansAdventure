#include "pch.h"
#include "GameManager.h"
#include "Player.h"
#include "Menu.h"
#include "MapManager.h"
#include "Key.h"
#include "Chest.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
GameManager *GameManager::instance = 0;
bool GameManager::gameOverStatus = false;
bool GameManager::gameIsInitializing = false;

bool GameManager::CheckForCollision(MapManager::Direction direction)
{
	switch (direction)
	{
	case MapManager::Direction::LEFT:
	{
		if (MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasLeftWall() == true ||
			MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasLeftDoor() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case MapManager::Direction::FORWARD:
	{
		if (MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasForwardWall() == true ||
			MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasForwardDoor() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case MapManager::Direction::RIGHT:
	{
		if (MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasRightWall() == true ||
			MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasRightDoor() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case MapManager::Direction::BACKWARD:
	{
		if (MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasBackwardWall() == true ||
			MapManager::GetInstance()->GetRoomMap()[Player::GetInstance()->getCurrentLocationGridID()].GetHasBackwardDoor() == true)
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

int GameManager::CreatePlayer()
{
	system("cls");

	string name;

	bool nameConfirmed = false;
	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");
		cout << "NEW GAME\n";
		cout << "--------\n\n";
		cout << "Enter character name or type '/q' to cancel:\n\n";

		string input;
		char choice;
		if (!nameConfirmed)
		{
			getline(cin, name);

			if (name == "/q" || name == "/Q")
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

void GameManager::DisplayCollectItemScreen()
{
	bool confirmed = false;
	bool isSelectable = false;

	while (!confirmed)
	{
		system("cls");
		cout << "COLLECT ITEM\n";
		cout << "------------\n\n";
		cout << "Items:\n\n";
		ListRoomItems(isSelectable);
		cout << "(C) Collect\n";
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
			isSelectable = true;

			while (!collectConfirmed)
			{
				system("cls");
				cout << "COLLECT ITEM\n";
				cout << "------------\n\n";
				cout << "Collect which item?\n\n";
				ListRoomItems(isSelectable);
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
						isSelectable = false;
					}
					else if (iChoice > 0 && iChoice <= roomItemsCount)
					{
						int index = iChoice - 1;
						system("cls");

						std::vector<std::string> itemNames = currentRoom->GetRoomItemNames();
						std::vector<std::string>::iterator it;

						// ---- COLLECT KEY
						std::vector<Key> roomKeys = currentRoom->GetRoomKeys();
						std::vector<Key>::iterator it2;
						for (it2 = roomKeys.begin(); it2 < roomKeys.end(); ++it2)
						{
							if (itemNames[index].compare(it2->getName()) == 0)
							{
								Key& key = (*it2);
								MapManager::GetInstance()->TransferItemToPlayer(&key);
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
								MapManager::GetInstance()->TransferItemToPlayer(&food);
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
								MapManager::GetInstance()->TransferItemToPlayer(&potion);
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

void GameManager::DisplayChestScreen(Chest* chest)
{
	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");
		cout << "CHEST\n";
		cout << "-----\n\n";
		cout << Player::GetInstance()->getPlayerName() << " unlocked the chest and found:\n\n";
		ListChestItems(chest);
		if (chest->getItemCount() == 0)
		{
			cout << "(Q) Return\n\n";
		}
		else
		{
			cout << "(C) Collect\n";
			cout << "(Q) Return\n\n";
		}
		cout << "Enter choice: ";

		string input;
		getline(cin, input);
		stringstream stream(input);
		char choice;
		stream >> choice;

		if (input.length() == 1 && (choice == 'c' || choice == 'C') && (chest->getItemCount() > 0))
		{
			system("cls");

			std::vector<std::string> chestItemNames = chest->getChestItemNames();
			std::vector<std::string>::iterator it;

			// ---- COLLECT CHEST FOOD
			std::vector<Food> chestFood = chest->getChestFood();
			std::vector<Food>::iterator it1;
			for (it1 = chestFood.begin(); it1 < chestFood.end(); ++it1)
			{
				if (chestItemNames[0].compare(it1->getName()) == 0)
				{
					Food& food = (*it1);
					if (Player::GetInstance()->AddItemToInventory(&food) == SUCCESS)
					{
						system("cls");
						cout << "The chest vanished in a puff of smoke.\n\n";
						system("pause");
						chest->RemoveItemFromChest(&food);
					}
				}
			}

			// ---- COLLECT CHEST POTION
			std::vector<Potion> chestPotions = chest->getChestPotions();
			std::vector<Potion>::iterator it2;
			for (it2 = chestPotions.begin(); it2 < chestPotions.end(); ++it2)
			{
				if (chestItemNames[0].compare(it2->getName()) == 0)
				{
					Potion& potion = (*it2);
					if (Player::GetInstance()->AddItemToInventory(&potion) == SUCCESS)
					{
						system("cls");
						cout << "The chest vanished in a puff of smoke.\n\n";
						system("pause");
						chest->RemoveItemFromChest(&potion);
					}
				}
			}

			// ---- COLLECT CHEST KEY
			std::vector<Key> chestKeys = chest->getChestKeys();
			std::vector<Key>::iterator it3;
			for (it3 = chestKeys.begin(); it3 < chestKeys.end(); ++it3)
			{
				if (chestItemNames[0].compare(it3->getName()) == 0)
				{
					Key& key = (*it3);
					if (Player::GetInstance()->AddItemToInventory(&key) == SUCCESS)
					{
						system("cls");
						cout << "The chest vanished in a puff of smoke.\n\n";
						system("pause");
						chest->RemoveItemFromChest(&key);
					}
				}
			}

			confirmed = true;
			break;
		}
		else if (input.length() == 1 && (choice == 'q' || choice == 'Q'))
		{
			system("cls");
			cout << "The chest vanishes in a puff of smoke.\n\n";
			system("pause");
			confirmed = true;
			break;
		}
	}
}

void GameManager::DisplayUseItemScreen(Key* key)
{
	bool confirmed = false;
	bool isSelectable = true;

	while (!confirmed)
	{
		system("cls");
		cout << "USE ITEM\n";
		cout << "--------\n\n";
		cout << "Use " << key->getName() << " on what? \n\n";
		cout << "Items:\n\n";
		ListRoomItems(isSelectable);
		bool hasDoor = false;
		unordered_map<std::string, Room> roomMap = MapManager::GetInstance()->GetRoomMap();
		Room* currentRoom = &roomMap[Player::GetInstance()->getCurrentLocationGridID()];
		if (currentRoom->GetHasForwardDoor() ||
			currentRoom->GetHasBackwardDoor() ||
			currentRoom->GetHasRightDoor() ||
			currentRoom->GetHasLeftDoor())
		{
			hasDoor = true;
			cout << "(D) Door (locked)\n";
		}

		cout << "(P) Player\n";
		cout << "(Q) Return\n\n";
		cout << "Enter choice: ";

		string input;
		getline(cin, input);
		stringstream stream(input);
		char choice;
		stream >> choice;

		if (input.length() == 1 && (choice == 'd' || choice == 'D') && hasDoor)
		{
			unordered_map<std::string, Room>* roomMapPtr = MapManager::GetInstance()->GetRoomMapPtr();
			currentRoom = &roomMapPtr->at(Player::GetInstance()->getCurrentLocationGridID());

			if (key->CombineWithItem(currentRoom) == SUCCESS)
			{
				string currentGridID = Player::GetInstance()->getCurrentLocationGridID();
				int letter;
				int number;
				string newGridID = "";
				Room* nextRoom = new Room();

				// find and store current gridID's letter
				if (currentGridID.find("A") != string::npos)
				{
					letter = 65;
				}
				else if (currentGridID.find("B") != string::npos)
				{
					letter = 66;
				}
				else if (currentGridID.find("C") != string::npos)
				{
					letter = 67;
				}
				else if (currentGridID.find("D") != string::npos)
				{
					letter = 68;
				}
				else if (currentGridID.find("E") != string::npos)
				{
					letter = 69;
				}
				else if (currentGridID.find("F") != string::npos)
				{
					letter = 70;
				}
				else if (currentGridID.find("G") != string::npos)
				{
					letter = 71;
				}

				// find and store current gridID's number
				if (currentGridID.find("1") != string::npos)
				{
					number = 1;
				}
				else if (currentGridID.find("2") != string::npos)
				{
					number = 2;
				}
				else if (currentGridID.find("3") != string::npos)
				{
					number = 3;
				}
				else if (currentGridID.find("4") != string::npos)
				{
					number = 4;
				}
				else if (currentGridID.find("5") != string::npos)
				{
					number = 5;
				}
				else if (currentGridID.find("6") != string::npos)
				{
					number = 6;
				}
				else if (currentGridID.find("7") != string::npos)
				{
					number = 7;
				}
				else if (currentGridID.find("8") != string::npos)
				{
					number = 8;
				}
				else if (currentGridID.find("9") != string::npos)
				{
					number = 9;
				}
				else if (currentGridID.find("10") != string::npos)
				{
					number = 10;
				}
				else if (currentGridID.find("11") != string::npos)
				{
					number = 11;
				}
				else if (currentGridID.find("12") != string::npos)
				{
					number = 12;
				}

				if (currentRoom->GetHasForwardDoor())
				{
					currentRoom->SetHasForwardDoor(false);
					letter++;
					newGridID = char(letter);
					newGridID.append(to_string(number));
					nextRoom = &roomMapPtr->at(newGridID);
					nextRoom->SetHasBackwardDoor(false);
				}
				else if (currentRoom->GetHasBackwardDoor())
				{
					currentRoom->SetHasBackwardDoor(false);
					letter--;
					newGridID = char(letter);
					newGridID.append(to_string(number));
					nextRoom = &roomMapPtr->at(newGridID);
					nextRoom->SetHasForwardDoor(false);
				}
				else if (currentRoom->GetHasRightDoor())
				{
					currentRoom->SetHasRightDoor(false);
					number++;
					newGridID = char(letter);
					newGridID.append(to_string(number));
					nextRoom = &roomMapPtr->at(newGridID);
					nextRoom->SetHasLeftDoor(false);
				}
				else if (currentRoom->GetHasLeftDoor())
				{
					currentRoom->SetHasLeftDoor(false);
					number--;
					newGridID = char(letter);
					newGridID.append(to_string(number));
					nextRoom = &roomMapPtr->at(newGridID);
					nextRoom->SetHasRightDoor(false);
				}
				nextRoom = nullptr;
				delete(nextRoom);

				system("cls");
				cout << Player::GetInstance()->getPlayerName() << " unlocked the door using the " << key->getName() << ".\n\n";
				system("pause");
			}

			confirmed = true;
			break;
		}
		if (input.length() == 1 && (choice == 'p' || choice == 'P'))
		{
			Player::GetInstance()->ConsumeItem(key);
			confirmed = true;
			break;
		}
		else if (input.length() == 1 && (choice == 'q' || choice == 'Q'))
		{
			confirmed = true;
			break;
		}
		else if (input.length() == 1) 
		{
			int roomItemsCount = (int)currentRoom->GetRoomItemNames().size();
			int iChoice = (int)choice - 48;

			if (iChoice > 0 && iChoice <= roomItemsCount)
			{
				int index = iChoice - 1;
				system("cls");

				std::vector<std::string> itemNames = currentRoom->GetRoomItemNames();
				std::vector<std::string>::iterator it;

				// ---- USE KEY ON CHEST
				std::vector<Chest> roomChests = currentRoom->GetRoomChests();
				std::vector<Chest>::iterator it2;
				for (it2 = roomChests.begin(); it2 < roomChests.end(); ++it2)
				{
					if (itemNames[index].compare(it2->getName()) == 0)
					{
						Chest& chest = (*it2);
						if (key->CombineWithItem(&chest) == SUCCESS)
						{
							Player::GetInstance()->RemoveItem(key);
							DisplayChestScreen(&chest);
							MapManager::GetInstance()->RemoveItem(&chest);
						}
					}
				}

				// ---- USE KEY ON FOOD
				std::vector<Food> roomFood = currentRoom->GetRoomFood();
				std::vector<Food>::iterator it3;
				for (it3 = roomFood.begin(); it3 < roomFood.end(); ++it3)
				{
					if (itemNames[index].compare(it3->getName()) == 0)
					{
						Food& food = (*it3);
						key->CombineWithItem(&food);
					}
				}

				// ---- USE KEY ON POTION
				std::vector<Potion> roomPotions = currentRoom->GetRoomPotions();
				std::vector<Potion>::iterator it4;
				for (it4 = roomPotions.begin(); it4 < roomPotions.end(); ++it4)
				{
					if (itemNames[index].compare(it4->getName()) == 0)
					{
						Potion& potion = (*it4);
						key->CombineWithItem(&potion);
					}
				}

				// ---- USE KEY ON KEY
				std::vector<Key> roomKeys = currentRoom->GetRoomKeys();
				std::vector<Key>::iterator it5;
				for (it5 = roomKeys.begin(); it5 < roomKeys.end(); ++it5)
				{
					if (itemNames[index].compare(it5->getName()) == 0)
					{
						Key& otherKey = (*it5);
						key->CombineWithItem(&otherKey);
					}
				}

				confirmed = true;
				break;
			}
			else
			{
				continue;
			}
		}
	}
}

void GameManager::DisplayMapScreen()
{
	system("cls");
	cout << "MAP\n";
	cout << "---\n";
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
	cout << "							  \n\n";
	system("pause");
}

void GameManager::DisplayEndGameScreen()
{
	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");
		cout << "QUIT GAME\n";
		cout << "---------\n\n";
		cout << "All progress for " << Player::GetInstance()->getPlayerName() << " will be lost.\n\nAre you sure? (Y/N): ";

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
			GameManager::GetInstance()->Init();

			confirmed = true;
			break;
		}
		if (input.length() == 1 && (choice == 'n' || choice == 'N'))
		{
			confirmed = true;
			break;
		}
		else
		{
			continue;
		}
	}

}

void GameManager::DisplayInventoryScreen()
{
	bool confirmed = false;
	bool isSelectable = false;

	while (!confirmed)
	{
		system("cls");
		cout << "INVENTORY\n";
		cout << "---------\n\n";
		ListPlayerItems(isSelectable);
		cout << "(U) Use\n";
		cout << "(D) Drop\n";
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
			isSelectable = true;

			while (!useConfirmed)
			{
				system("cls");
				cout << "PLAYER INVENTORY\n";
				cout << "----------------\n\n";
				cout << "Use which item?\n\n";
				ListPlayerItems(isSelectable);
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
						isSelectable = false;
					}
					else if (iChoice > 0 && iChoice <= playerItemsCount)
					{
						int index = iChoice - 1;
						system("cls");

						// ---- USE KEY
						std::vector<std::string> itemNames = Player::GetInstance()->getPlayerItemNames();
						std::vector<std::string>::iterator it;

						std::vector<Key> playerKeys = Player::GetInstance()->getPlayerKeys();
						std::vector<Key>::iterator it2;
						for (it2 = playerKeys.begin(); it2 < playerKeys.end(); ++it2)
						{
							if (itemNames[index].compare(it2->getName()) == 0)
							{
								Key& key = (*it2);
								DisplayUseItemScreen(&key);
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
								Player::GetInstance()->ConsumeItem(&food);
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
								Player::GetInstance()->ConsumeItem(&potion);
							}
						}

						useConfirmed = true;
						confirmed = true;
						break;
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
			isSelectable = true;

			while (!dropConfirmed)
			{
				system("cls");
				cout << "PLAYER INVENTORY\n";
				cout << "----------------\n\n";
				cout << "Drop which item?\n\n";
				ListPlayerItems(isSelectable);
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
						isSelectable = false;
					}
					else if (iChoice > 0 && iChoice <= playerItemsCount)
					{
						int index = iChoice - 1;
						system("cls");

						std::vector<std::string> itemNames = Player::GetInstance()->getPlayerItemNames();
						std::vector<std::string>::iterator it;

						// ---- DROP KEYS
						std::vector<Key> playerKeys = Player::GetInstance()->getPlayerKeys();
						std::vector<Key>::iterator it2;
						for (it2 = playerKeys.begin(); it2 < playerKeys.end(); ++it2)
						{
							if (itemNames[index].compare(it2->getName()) == 0)
							{
								Key& key = (*it2);
								Player::GetInstance()->DropItem(&key);
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
								Player::GetInstance()->DropItem(&food);
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
								Player::GetInstance()->DropItem(&potion);
							}
						}

						dropConfirmed = true;
						confirmed = true;
						break;
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

void GameManager::Init()
{
	gameIsInitializing = true;

	MapManager::GetInstance()->CreateRooms();
	Player::GetInstance()->setPlayerEnergy(100);
	Player::GetInstance()->setTurnsCompleted(0);
	Player::GetInstance()->setCurrentLocationGridID("A4");
	Player::GetInstance()->setInventoryCount(0);

	// KEYS (START)

	Key* a4_brassKey = new Key();
	a4_brassKey->setName("Brass Key");
	a4_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(a4_brassKey, "A4");
	delete(a4_brassKey);

	Key* d5_brassKey = new Key();
	d5_brassKey->setName("Brass Key");
	d5_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(d5_brassKey, "D5");
	delete(d5_brassKey);

	Key* g1_brassKey = new Key();
	g1_brassKey->setName("Brass Key");
	g1_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(g1_brassKey, "G1");
	delete(g1_brassKey);

	Key* f6_brassKey = new Key();
	f6_brassKey->setName("Brass Key");
	f6_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(f6_brassKey, "F6");
	delete(f6_brassKey);

	Key* g9_brassKey = new Key();
	g9_brassKey->setName("Brass Key");
	g9_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(g9_brassKey, "G9");
	delete(g9_brassKey);

	Key* f10_brassKey = new Key();
	f10_brassKey->setName("Brass Key");
	f10_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(f10_brassKey, "F10");
	delete(f10_brassKey);

	Key* e9_brassKey = new Key();
	e9_brassKey->setName("Brass Key");
	e9_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(e9_brassKey, "E9");
	delete(e9_brassKey);

	Key* c9_brassKey = new Key();
	c9_brassKey->setName("Brass Key");
	c9_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(c9_brassKey, "C9");
	delete(c9_brassKey);

	Key* a7_brassKey = new Key();
	a7_brassKey->setName("Brass Key");
	a7_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(a7_brassKey, "A7");
	delete(a7_brassKey);

	Key* b11_brassKey = new Key();
	b11_brassKey->setName("Brass Key");
	b11_brassKey->setIsBrass(true);
	MapManager::GetInstance()->TransferItemToRoom(b11_brassKey, "B11");
	delete(b11_brassKey);

	// KEYS (END)

	// CONSUMABLES (START)

	/*
	Food* f = new Food();
	f->setName("Apple");
	f->setHealFactor(5);
	MapManager::GetInstance()->TransferItemToRoom(f, "A4");
	delete(f);
	*/

	// CONSUMABLES (END)
	
	// CHESTS (START)

	/*
	Chest* blueChest = new Chest();
	blueChest->setName("Blue Chest");
	blueChest->setIsBlue(true);
	blueChest->AddItemToChest(i);
	MapManager::GetInstance()->TransferItemToRoom(blueChest, "A4");
	delete(blueChest);
	delete(i);
	*/

	// CHESTS (END)

	gameIsInitializing = false;
}

void GameManager::ListRoomItems(bool isSelectable)
{
	unordered_map<string, Room> roomMap = MapManager::GetInstance()->GetRoomMap();
	Room* currentRoom = &roomMap[Player::GetInstance()->getCurrentLocationGridID()];

	if (currentRoom->GetRoomItemNames().empty())
	{
		cout << "-> None\n";
	}
	else
	{
		int counter = 1;
		std::vector<std::string>::iterator it;
		std::vector<std::string> v1 = currentRoom->GetRoomItemNames();
		for (it = v1.begin(); it < v1.end(); it++)
		{
			if (isSelectable)
			{
				cout << "(" << counter << ") ";
			}
			else
			{
				cout << "-> ";
			}
			cout << it->c_str() << "\n";
			counter++;
		}
	}
	cout << endl;
}

void GameManager::ListPlayerItems(bool isSelectable)
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
			if (isSelectable)
			{
				cout << "(" << counter << ") ";
			}
			else
			{
				cout << "-> ";
			}
			cout << it->c_str() << "\n";
			counter++;
		}
	}
	cout << endl;
}

void GameManager::ListChestItems(Chest* chest)
{
	if (chest->getItemCount() == 0)
	{
		cout << "<< EMPTY >>\n";
	}
	else
	{
		std::vector<std::string>::iterator it;
		std::vector<std::string> v1 = chest->getChestItemNames();
		for (it = v1.begin(); it < v1.end(); it++)
		{
			cout << it->c_str() << "\n";
		}
	}
	cout << endl;
}

char GameManager::PromptForTurnAction()
{
	system("cls");
	cout << "Energy: " << Player::GetInstance()->getPlayerEnergy() << "\n";
	cout << "Turns: " << Player::GetInstance()->getTurnsCompleted() << "\n\n";
	cout << Player::GetInstance()->getPlayerName() << " looks around the room and sees:\n\n";
	MapManager::GetInstance()->DescribeRoom(Player::GetInstance()->getCurrentLocationGridID());
	cout << "\n";
	cout << "What should " << Player::GetInstance()->getPlayerName() << " do?\n\n";
	cout << "(M) Move\n(C) Collect Item\n(I) View Inventory\n(X) View Map\n\n(Q) Quit Game\n\nEnter Choice: ";

	string input;
	char choice;
	getline(cin, input);
	stringstream stream(input);
	stream >> choice;

	if (choice == 'm' ||
		choice == 'M' ||
		choice == 'c' ||
		choice == 'C' ||
		choice == 'i' ||
		choice == 'I' ||
		choice == 'x' ||
		choice == 'X' ||
		choice == 'q' ||
		choice == 'Q')
	{
		return choice;
	}
	else
	{
		return 0;
	}
}

void GameManager::PromptForDirection()
{
	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");
		cout << "MOVE\n";
		cout << "----\n\n";
		cout << "Move in which direction?\n\n";
		cout << "(W) Forward\n(S) Backward\n(D) Right\n(A) Left\n\n(Q) Cancel\n\n";
		cout << "Enter choice: ";

		char choice;
		string input;
		getline(cin, input);
		stringstream stream(input);
		stream >> choice;

		if (input.length() != 1)
		{
			continue;
		}
		else
		{
			switch (choice)
			{
			case 'W':
				system("cls");
				Player::GetInstance()->MoveForward();
				confirmed = true;
				break;
			case 'w':
				system("cls");
				Player::GetInstance()->MoveForward();
				confirmed = true;
				break;
			case 'S':
				system("cls");
				Player::GetInstance()->MoveBackward();
				confirmed = true;
				break;
			case 's':
				system("cls");
				Player::GetInstance()->MoveBackward();
				confirmed = true;
				break;
			case 'D':
				system("cls");
				Player::GetInstance()->MoveRight();
				confirmed = true;
				break;
			case 'd':
				system("cls");
				Player::GetInstance()->MoveRight();
				confirmed = true;
				break;
			case 'A':
				system("cls");
				Player::GetInstance()->MoveLeft();
				confirmed = true;
				break;
			case 'a':
				system("cls");
				Player::GetInstance()->MoveLeft();
				confirmed = true;
				break;
			case 'q':
				confirmed = true;
				break;
			case 'Q':
				confirmed = true;
				break;
			}
		}
	}
}

void GameManager::StartPlayerTurn()
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

		MapManager::GetInstance()->GetRoomMap().clear();
		Player::GetInstance()->ResetProgress();
		GameManager::GetInstance()->Init();

		return;
	}

	char choice = PromptForTurnAction();
	switch (choice)
	{
	case 'm':
		PromptForDirection();
		break;
	case 'M':
		PromptForDirection();
		break;
	case 'c':
		DisplayCollectItemScreen();
		break;
	case 'C':
		DisplayCollectItemScreen();
		break;
	case 'i':
		DisplayInventoryScreen();
		break;
	case 'I':
		DisplayInventoryScreen();
		break;
	case 'x':
		DisplayMapScreen();
		break;
	case 'X':
		DisplayMapScreen();
		break;
	case 'q':
		DisplayEndGameScreen();
		break;
	case 'Q':
		DisplayEndGameScreen();
		break;
	default:
		choice = PromptForTurnAction();
		break;
	}
}