#include "pch.h"
#include "Game.h"
#include "MapManager.h"
#include "Player.h"
#include "Item.h"

Player *Player::instance = 0;

void Player::AddItemToInventory(Item& item)
{
	if ((int)playerItems.size() < MAX_INVENTORY_ITEMS)
	{
		std::vector<Item>::iterator it;
		it = playerItems.begin();
		playerItems.insert(it, item);
		//TODO: remove from current room
	}
	else
	{
		system("cls");
		cout << "Inventory full. Could not collect " << item.getName() << ".\n\n";
		system("pause");
	}
}

void Player::LookAround()
{
	MapManager::GetInstance()->DescribeRoom(Player::GetInstance()->getCurrentLocationGridID());
}

void Player::DropItem(Item& item)
{
	std::vector<Item>::iterator it;
	for (it = playerItems.begin(); it < playerItems.end(); it++)
	{
		if (it->getName().compare(item.getName()) == 0)
		{
			playerItems.erase(it);
			break;
		}
	}
	
	//TODO: add to current room
}

void Player::UseItem(Item& item, Item& target)
{
	//TODO
}

void Player::ConsumeItem(Item& item)
{
	if (item.getHealFactor() > 0)
	{
		iEnergy += item.getHealFactor();
		
		cout << "The " << item.getName() << " increased " << sName << "'s energy by " << item.getHealFactor() << ".\n\n";
		system("pause");

		std::vector<Item>::iterator it;
		for (it = playerItems.begin(); it < playerItems.end(); it++)
		{
			if (it->getName().compare(item.getName()) == 0)
			{
				playerItems.erase(it);
				break;
			}
		}
	}
	else if (item.getDamageFactor() > 0)
	{
		iEnergy -= item.getDamageFactor();

		cout << "The " << item.getName() << " decreased " << sName << "'s energy by " << item.getDamageFactor() << ".\n\n";
		system("pause");

		std::vector<Item>::iterator it;
		for (it = playerItems.begin(); it < playerItems.end(); it++)
		{
			if (it->getName().compare(item.getName()) == 0)
			{
				playerItems.erase(it);
				break;
			}
		}
	}
	else
	{
		cout << sName << " can't consume the " << item.getName() << ".\n\n";
		system("pause");
	}
}

void Player::ConsumeItem(Food& food)
{
	cout << sName << " ate the " << food.getName() << ".\n";

	if (food.getIsRotten())
	{
		cout << "Unfortunately, it was rotten.\n";
	}

	ConsumeItem((Item&)food);
}

void Player::MoveNorth()
{
	if (Game::GetInstance()->CheckForCollision(MapManager::Direction::NORTH))
	{
		cout << "You cannot move North.\n\n";
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
	if (Game::GetInstance()->CheckForCollision(MapManager::Direction::SOUTH))
	{
		cout << "You cannot move South.\n\n";
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
	if (Game::GetInstance()->CheckForCollision(MapManager::Direction::EAST))
	{
		cout << "You cannot move East.\n\n";
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
	if (Game::GetInstance()->CheckForCollision(MapManager::Direction::WEST))
	{
		cout << "You cannot move West.\n\n";
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
