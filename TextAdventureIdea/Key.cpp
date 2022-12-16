#include "pch.h"
#include "GameManager.h"
#include "Player.h"
#include <iostream>

int Key::CombineWithItem(Chest* chest)
{
	bool match = false;
	if (isBlue && chest->getIsBlue() ||
		isGreen && chest->getIsGreen() ||
		isRed && chest->getIsRed() ||
		isYellow && chest->getIsYellow())
	{
		match = true;
	}

	if (!match)
	{
		system("cls");
		std::cout << Player::GetInstance()->getPlayerName() << " attempted to use the " << getName() << " on the " << chest->getName() << ", but it didn't fit.\n\n";
		system("pause");
		return FAILED;
	}
	return SUCCESS;
}

int Key::CombineWithItem(Food* food)
{
	system("cls");
	std::cout << Player::GetInstance()->getPlayerName() << " attempted to use the " << getName() << " on the " << food->getName() << ", but nothing happened.\n\n";
	system("pause");
	return FAILED;
}

int Key::CombineWithItem(Potion* potion)
{
	system("cls");
	std::cout << Player::GetInstance()->getPlayerName() << " attempted to use the " << getName() << " on the " << potion->getName() << ", but nothing happened.\n\n";
	system("pause");
	return FAILED;
}

int Key::CombineWithItem(Key* key)
{
	system("cls");
	std::cout << Player::GetInstance()->getPlayerName() << " attempted to use the " << getName() << " on the " << key->getName() << ", but nothing happened.\n\n";
	system("pause");
	return FAILED;
}