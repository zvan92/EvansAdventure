#include "pch.h"
#include "Game.h"
#include "MapManager.h"
#include "Player.h"
#include <iostream>

Player *Player::instance = 0;

void Player::MoveEast()
{
	if (Game::GetInstance()->CheckForCollision(MapManager::Direction::EAST))
	{
		cout << "You cannot move East.\n\n";
	}
	else
	{
		string s = Player::GetInstance()->getCurrentLocationGridID();
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

		cout << Player::GetInstance()->getPlayerName() << " moved East.\n\n";

		Player::GetInstance()->setCurrentLocationGridID(s);
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
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
		string s = Player::GetInstance()->getCurrentLocationGridID();
		int yValue1 = NULL;
		int yValue2 = NULL;

		if (s[1] == '1' && s[2] == '0')
		{
			s[1] = '9';
			s.erase(s.begin() + 2);
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

		cout << Player::GetInstance()->getPlayerName() << " moved West.\n\n";

		Player::GetInstance()->setCurrentLocationGridID(s);
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
	}

	system("pause");
}

void Player::MoveNorth()
{
	if (Game::GetInstance()->CheckForCollision(MapManager::Direction::NORTH))
	{
		cout << "You cannot move North.\n\n";
	}
	else
	{
		string s = Player::GetInstance()->getCurrentLocationGridID();
		char xValue = s[0];

		xValue++;
		s[0] = xValue;

		cout << Player::GetInstance()->getPlayerName() << " moved North.\n\n";

		Player::GetInstance()->setCurrentLocationGridID(s);
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
		string s = Player::GetInstance()->getCurrentLocationGridID();
		char xValue = s[0];

		xValue--;
		s[0] = xValue;

		cout << Player::GetInstance()->getPlayerName() << " moved South.\n\n";

		Player::GetInstance()->setCurrentLocationGridID(s);
		Player::GetInstance()->setTurnsCompleted(Player::GetInstance()->getTurnsCompleted() + 1);
	}

	system("pause");
}

void Player::LookAround()
{
	MapManager::GetInstance()->DescribeRoom(Player::GetInstance()->getCurrentLocationGridID());
}
