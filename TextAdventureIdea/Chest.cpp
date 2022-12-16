#include "pch.h"
#include "GameManager.h"
#include "Chest.h"

int Chest::AddItemToChest(Food* food)
{
	if (iItemCount < MAX_CHEST_ITEMS)
	{
		std::vector<Food>::iterator it;
		it = chestFood.begin();
		chestFood.insert(it, *food);
		std::vector<std::string>::iterator it2;
		it2 = chestItemNames.begin();
		chestItemNames.insert(it2, food->getName());
		iItemCount++;
	}
	else
	{
		return FAILED;
	}
	return SUCCESS;
}

int Chest::AddItemToChest(Potion* potion)
{
	if (iItemCount < MAX_CHEST_ITEMS)
	{
		std::vector<Potion>::iterator it;
		it = chestPotions.begin();
		chestPotions.insert(it, *potion);
		std::vector<std::string>::iterator it2;
		it2 = chestItemNames.begin();
		chestItemNames.insert(it2, potion->getName());
		iItemCount++;
	}
	else
	{
		return FAILED;
	}
	return SUCCESS;
}

int Chest::AddItemToChest(Key* key)
{
	if (iItemCount < MAX_CHEST_ITEMS)
	{
		std::vector<Key>::iterator it;
		it = chestKeys.begin();
		chestKeys.insert(it, *key);
		std::vector<std::string>::iterator it2;
		it2 = chestItemNames.begin();
		chestItemNames.insert(it2, key->getName());
		iItemCount++;
	}
	else
	{
		return FAILED;
	}
	return SUCCESS;
}

void Chest::RemoveItemFromChest(Food* food)
{
	std::vector<Food>::iterator it;
	for (it = chestFood.begin(); it < chestFood.end(); it++)
	{
		if (it->getName().compare(food->getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = chestItemNames.begin(); it2 < chestItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					chestItemNames.erase(it2);
					break;
				}
			}

			chestFood.erase(it);
			break;
		}
	}
	iItemCount--;
}

void Chest::RemoveItemFromChest(Potion* potion)
{
	std::vector<Potion>::iterator it;
	for (it = chestPotions.begin(); it < chestPotions.end(); it++)
	{
		if (it->getName().compare(potion->getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = chestItemNames.begin(); it2 < chestItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					chestItemNames.erase(it2);
					break;
				}
			}

			chestPotions.erase(it);
			break;
		}
	}
	iItemCount--;
}

void Chest::RemoveItemFromChest(Key* key)
{
	std::vector<Key>::iterator it;
	for (it = chestKeys.begin(); it < chestKeys.end(); it++)
	{
		if (it->getName().compare(key->getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = chestItemNames.begin(); it2 < chestItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					chestItemNames.erase(it2);
					break;
				}
			}

			chestKeys.erase(it);
			break;
		}
	}
	iItemCount--;
}