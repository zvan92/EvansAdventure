#include "pch.h"
#include "Player.h"
#include "MapManager.h"

Player *Player::instance = 0;

void Player::LookAround()
{
	MapManager::Instance()->DescribeRoom(currentGridID);
}

void Player::MoveEast()
{
	string s = currentGridID;;
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

	setCurrentGridID(s);

	cout << getPlayerName() << " moved East.\n";
}
