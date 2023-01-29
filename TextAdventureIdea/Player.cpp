#include "pch.h"
#include "GameManager.h"
#include "MapManager.h"
#include "Player.h"

Player *Player::instance = 0;

int Player::AddItemToInventory(Key* key)
{
	if (iInventoryCount < MAX_INVENTORY_ITEMS)
	{
		std::vector<Key>::iterator it;
		it = playerKeys.begin();
		playerKeys.insert(it, *key);
		std::vector<std::string>::iterator it2;
		it2 = playerItemNames.begin();
		playerItemNames.insert(it2, key->getName());
		iInventoryCount++;

		if (!GameManager::GetInstance()->getGameIsInitializing())
		{
			cout << sName << " collected the " << key->getName() << ".\n\n";
			system("pause");
		}
	}
	else
	{
		system("cls");
		cout << "Inventory full. Could not collect " << key->getName() << ".\n\n";
		system("pause");
		return FAILED;
	}
	return SUCCESS;
}

int Player::AddItemToInventory(Food* food)
{
	if (iInventoryCount < MAX_INVENTORY_ITEMS)
	{
		std::vector<Food>::iterator it;
		it = playerFood.begin();
		playerFood.insert(it, *food);
		std::vector<std::string>::iterator it2;
		it2 = playerItemNames.begin();
		playerItemNames.insert(it2, food->getName());
		iInventoryCount++;

		if (!GameManager::GetInstance()->getGameIsInitializing())
		{
			cout << sName << " collected the " << food->getName() << ".\n\n";
			system("pause");
		}
	}
	else
	{
		system("cls");
		cout << "Inventory full. Could not collect " << food->getName() << ".\n\n";
		system("pause");
		return FAILED;
	}
	return SUCCESS;
}

int Player::AddItemToInventory(Potion* potion)
{
	if (iInventoryCount < MAX_INVENTORY_ITEMS)
	{
		std::vector<Potion>::iterator it;
		it = playerPotions.begin();
		playerPotions.insert(it, *potion);
		std::vector<std::string>::iterator it2;
		it2 = playerItemNames.begin();
		playerItemNames.insert(it2, potion->getName());
		iInventoryCount++;

		if (!GameManager::GetInstance()->getGameIsInitializing())
		{
			cout << sName << " collected the " << potion->getName() << ".\n\n";
			system("pause");
		}
	}
	else
	{
		system("cls");
		cout << "Inventory full. Could not collect " << potion->getName() << ".\n\n";
		system("pause");
		return FAILED;
	}
	return SUCCESS;
}

void Player::DropItem(Key* key)
{
	if (MapManager::GetInstance()->TransferItemToRoom(key, sCurrentGridID) == FAILED)
	{
		system("cls");
		cout << "There is no room to drop the " << key->getName() << ".\n\n";
		system("pause");
	}
	else
	{
		cout << sName << " dropped the " << key->getName() << ".\n\n";
		system("pause");

		std::vector<Key>::iterator it;
		for (it = playerKeys.begin(); it < playerKeys.end(); it++)
		{
			if (it->getName().compare(key->getName()) == 0)
			{
				std::vector<std::string>::iterator it2;
				for (it2 = playerItemNames.begin(); it2 < playerItemNames.end(); it2++)
				{
					if (it2->compare(it->getName()) == 0)
					{
						playerItemNames.erase(it2);
						break;
					}
				}

				playerKeys.erase(it);
				break;
			}
		}
		iInventoryCount--;
	}
}

void Player::DropItem(Food* food)
{
	if (MapManager::GetInstance()->TransferItemToRoom(food, sCurrentGridID) == FAILED)
	{
		system("cls");
		cout << "There is no room to drop the " << food->getName() << ".\n\n";
		system("pause");
	}
	else
	{
		cout << sName << " dropped the " << food->getName() << ".\n\n";
		system("pause");

		std::vector<Food>::iterator it;
		for (it = playerFood.begin(); it < playerFood.end(); it++)
		{
			if (it->getName().compare(food->getName()) == 0)
			{
				std::vector<std::string>::iterator it2;
				for (it2 = playerItemNames.begin(); it2 < playerItemNames.end(); it2++)
				{
					if (it2->compare(it->getName()) == 0)
					{
						playerItemNames.erase(it2);
						break;
					}
				}

				playerFood.erase(it);
				break;
			}
		}
		iInventoryCount--;
	}
}

void Player::DropItem(Potion* potion)
{
	if (MapManager::GetInstance()->TransferItemToRoom(potion, sCurrentGridID) == FAILED)
	{
		system("cls");
		cout << "There is no room to drop the " << potion->getName() << ".\n\n";
		system("pause");
	}
	else
	{
		cout << sName << " dropped the " << potion->getName() << ".\n\n";
		system("pause");

		std::vector<Potion>::iterator it;
		for (it = playerPotions.begin(); it < playerPotions.end(); it++)
		{
			if (it->getName().compare(potion->getName()) == 0)
			{
				std::vector<std::string>::iterator it2;
				for (it2 = playerItemNames.begin(); it2 < playerItemNames.end(); it2++)
				{
					if (it2->compare(it->getName()) == 0)
					{
						playerItemNames.erase(it2);
						break;
					}
				}

				playerPotions.erase(it);
				break;
			}
		}
		iInventoryCount--;
	}
}

void Player::ConsumeItem(Key* key)
{
	system("cls");
	cout << sName << " can't consume the " << key->getName() << ".\n\n";
	system("pause");
	return;
}

void Player::ConsumeItem(Food* food)
{
	cout << sName << " ate the " << food->getName() << ".\n";

	if (food->getIsRotten())
	{
		cout << "Unfortunately, it was rotten.\n";
	}

	if (food->getHealFactor() > 0)
	{
		iEnergy += food->getHealFactor();

		cout << "The " << food->getName() << " increased " << sName << "'s energy by " << food->getHealFactor() << ".\n\n";
		system("pause");
	}
	else if (food->getDamageFactor() > 0)
	{
		iEnergy -= food->getDamageFactor();

		cout << "The " << food->getName() << " decreased " << sName << "'s energy by " << food->getDamageFactor() << ".\n\n";
		system("pause");
	}

	std::vector<Food>::iterator it;
	for (it = playerFood.begin(); it < playerFood.end(); it++)
	{
		if (it->getName().compare(food->getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = playerItemNames.begin(); it2 < playerItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					playerItemNames.erase(it2);
					break;
				}
			}

			playerFood.erase(it);
			break;
		}
	}
	iInventoryCount--;
}

void Player::ConsumeItem(Potion* potion)
{
	cout << sName << " consumed the " << potion->getName() << ".\n";

	if (potion->getIsPoison() == true)
	{
		cout << "Unfortunately, it was poison.\n";
	}

	if (potion->getHealFactor() > 0)
	{
		iEnergy += potion->getHealFactor();

		cout << "The " << potion->getName() << " increased " << sName << "'s energy by " << potion->getHealFactor() << ".\n\n";
		system("pause");
	}
	else if (potion->getDamageFactor() > 0)
	{
		iEnergy -= potion->getDamageFactor();

		cout << "The " << potion->getName() << " decreased " << sName << "'s energy by " << potion->getDamageFactor() << ".\n\n";
		system("pause");
	}

	std::vector<Potion>::iterator it;
	for (it = playerPotions.begin(); it < playerPotions.end(); it++)
	{
		if (it->getName().compare(potion->getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = playerItemNames.begin(); it2 < playerItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					playerItemNames.erase(it2);
					break;
				}
			}

			playerPotions.erase(it);
			break;
		}
	}
	iInventoryCount--;
}

void Player::MoveNorth()
{
	if (GameManager::GetInstance()->CheckForCollision(MapManager::Direction::NORTH))
	{
		cout << Player::GetInstance()->getPlayerName() << " cannot move North.\n\n";
	}
	else
	{
		string sCurrentGridID = Player::GetInstance()->getCurrentLocationGridID();
		char xValue = sCurrentGridID[0];

		xValue++;
		sCurrentGridID[0] = xValue;

		cout << Player::GetInstance()->getPlayerName() << " moved North.\n\n";
		cout << Player::GetInstance()->getPlayerName() << " used 5 energy.\n\n";
		Player::GetInstance()->setPlayerEnergy(Player::GetInstance()->getPlayerEnergy() - 5);

		Player::GetInstance()->setCurrentLocationGridID(sCurrentGridID);
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
	}

	system("pause");
}

void Player::MoveSouth()
{
	if (GameManager::GetInstance()->CheckForCollision(MapManager::Direction::SOUTH))
	{
		cout << Player::GetInstance()->getPlayerName() << " cannot move South.\n\n";
	}
	else
	{
		string sCurrentGridID = Player::GetInstance()->getCurrentLocationGridID();
		char xValue = sCurrentGridID[0];

		xValue--;
		sCurrentGridID[0] = xValue;

		cout << Player::GetInstance()->getPlayerName() << " moved South.\n\n";
		cout << Player::GetInstance()->getPlayerName() << " used 5 energy.\n\n";
		Player::GetInstance()->setPlayerEnergy(Player::GetInstance()->getPlayerEnergy() - 5);

		Player::GetInstance()->setCurrentLocationGridID(sCurrentGridID);
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
	}

	system("pause");
}

void Player::MoveEast()
{
	if (GameManager::GetInstance()->CheckForCollision(MapManager::Direction::EAST))
	{
		cout << Player::GetInstance()->getPlayerName() << " cannot move East.\n\n";
	}
	else
	{
		//Grid ID: [0] will be the X, [1] will be the first digit of the Y
		string sCurrentGridID = Player::GetInstance()->getCurrentLocationGridID();
		int yValue1 = NULL;
		int yValue2 = NULL;

		//ensure that the Y value can change to 2-digits
		if (sCurrentGridID[1] == '9')
		{
			sCurrentGridID[1] = '1';
			sCurrentGridID.append("0");
		}
		else
		{
			//if the Y value is 2 digits, make sure the first digit = 1
			if (sCurrentGridID[2] != NULL)
			{
				yValue1 = 1;
				yValue2 = (int)sCurrentGridID[2];
			}
			else
			{
				yValue1 = (int)sCurrentGridID[1];
			}

			//move east on the grid
			if (sCurrentGridID[2] != NULL)
			{
				yValue2++;
			}
			else
			{
				yValue1++;
			}

			if (sCurrentGridID[2] != NULL)
			{
				sCurrentGridID[2] = yValue2;
			}
			else
			{
				sCurrentGridID[1] = yValue1;
			}
		}

		cout << Player::GetInstance()->getPlayerName() << " moved East.\n\n";

		Player::GetInstance()->setCurrentLocationGridID(sCurrentGridID);
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
		cout << Player::GetInstance()->getPlayerName() << " used 5 energy.\n\n";
		Player::GetInstance()->setPlayerEnergy(Player::GetInstance()->getPlayerEnergy() - 5);
	}

	system("pause");
}

void Player::MoveWest()
{
	if (GameManager::GetInstance()->CheckForCollision(MapManager::Direction::WEST))
	{
		cout << Player::GetInstance()->getPlayerName() << " cannot move West.\n\n";
	}
	else
	{
		string sCurrentGridID = Player::GetInstance()->getCurrentLocationGridID();
		int yValue1 = NULL;
		int yValue2 = NULL;

		if (sCurrentGridID[1] == '1' && sCurrentGridID[2] == '0')
		{
			sCurrentGridID[1] = '9';
			sCurrentGridID.erase(sCurrentGridID.begin() + 2);
		}
		else
		{
			if (sCurrentGridID[2] != NULL)
			{
				yValue1 = 1;
				yValue2 = (int)sCurrentGridID[2];
			}
			else
			{
				yValue1 = (int)sCurrentGridID[1];
			}

			if (sCurrentGridID[2] != NULL)
			{
				yValue2--;
			}
			else
			{
				yValue1--;
			}

			if (sCurrentGridID[2] != NULL)
			{
				sCurrentGridID[2] = yValue2;
			}
			else
			{
				sCurrentGridID[1] = yValue1;
			}
		}

		cout << Player::GetInstance()->getPlayerName() << " moved West.\n\n";

		Player::GetInstance()->setCurrentLocationGridID(sCurrentGridID);
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
		cout << Player::GetInstance()->getPlayerName() << " used 5 energy.\n\n";
		Player::GetInstance()->setPlayerEnergy(Player::GetInstance()->getPlayerEnergy() - 5);
	}

	system("pause");
}

void Player::ResetProgress()
{
	playerItemNames.clear();
	playerKeys.clear();
	playerPotions.clear();
	playerFood.clear();
	sName = "";
	sCurrentGridID = "";
	iTurnsCompleted = 0;
	iInventoryCount = 0;
	iEnergy = 0;
}

void Player::RemoveItem(Key* key)
{
	system("cls");
	cout << getPlayerName() << " used the " << key->getName() << " and it vanished in a puff of smoke.\nLooks like " << sName << " won't be needing it anymore!\n\n";
	system("pause");

	std::vector<Key>::iterator it;
	for (it = playerKeys.begin(); it < playerKeys.end(); it++)
	{
		if (it->getName().compare(key->getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = playerItemNames.begin(); it2 < playerItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					playerItemNames.erase(it2);
					break;
				}
			}

			playerKeys.erase(it);
			break;
		}
	}
	iInventoryCount--;
}
