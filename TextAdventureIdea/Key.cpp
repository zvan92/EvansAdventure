#include "pch.h"
#include "GameManager.h"
#include "Player.h"
#include <iostream>

int Key::CombineWithItem(Chest* chest)
{
	// something like...
	/*
		if (isBlue && key->getIsBlue() ||
		isGreen && key->getIsGreen() ||
		isRed && key->getIsRed() ||
		isYellow && key->getIsYellow())
	{
		//success! the chest opens and...
		//collect contents or get hurt
	}
	*/

	// placeholder
	if (isBlue && chest->getIsBlue())
	{
		system("cls");
		std::cout << Player::GetInstance()->getPlayerName() << " unlocked a chest!\nThey open it, gather its contents, and it pops out of existence.\n\n";
		system("pause");
	}
	else
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