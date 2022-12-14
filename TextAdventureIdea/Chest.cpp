#include "pch.h"
#include "GameManager.h"
#include "Player.h"
#include <iostream>

// will need to become Key eventually
int Chest::CombineWithItem(Item* item)
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
	if (item->getIsKey())
	{
		system("cls");
		std::cout << Player::GetInstance()->getPlayerName() << " unlocked a chest!\nThey open it, gather its contents, and it pops out of existence.\n\n";
		system("pause");
	}
	else
	{
		system("cls");
		std::cout << "Nothing happened.\n\n";
		system("pause");
		return FAILED;
	}
	return SUCCESS;
}