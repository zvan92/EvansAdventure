#include "pch.h"
#include "Room.h"
#include <iostream>
#include <vector>

void Room::AddRoomItem(Item item)
{
	std::vector<Item>::iterator it;
	it = roomItems.begin();
	roomItems.insert(it, item);
	std::vector<std::string>::iterator it2;
	it2 = roomItemNames.begin();
	roomItemNames.insert(it2, item.getName());
}

void Room::RemoveRoomItem(Item item)
{
	std::vector<Item>::iterator it;
	for (it = roomItems.begin(); it < roomItems.end(); it++)
	{
		if (it->getName().compare(item.getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = roomItemNames.begin(); it2 < roomItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					roomItemNames.erase(it2);
					break;
				}
			}

			roomItems.erase(it);
			break;
		}
	}
}

void Room::AddRoomFood(Food food)
{
	std::vector<Food>::iterator it;
	it = roomFood.begin();
	roomFood.insert(it, food);
	std::vector<std::string>::iterator it2;
	it2 = roomItemNames.begin();
	roomItemNames.insert(it2, food.getName());
}

void Room::RemoveRoomFood(Food food)
{
	std::vector<Food>::iterator it;
	for (it = roomFood.begin(); it < roomFood.end(); it++)
	{
		if (it->getName().compare(food.getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = roomItemNames.begin(); it2 < roomItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					roomItemNames.erase(it2);
					break;
				}
			}

			roomFood.erase(it);
			break;
		}
	}
}

void Room::AddRoomPotion(Potion potion)
{
	std::vector<Potion>::iterator it;
	it = roomPotions.begin();
	roomPotions.insert(it, potion);
	std::vector<std::string>::iterator it2;
	it2 = roomItemNames.begin();
	roomItemNames.insert(it2, potion.getName());
}

void Room::RemoveRoomPotion(Potion potion)
{
	std::vector<Potion>::iterator it;
	for (it = roomPotions.begin(); it < roomPotions.end(); it++)
	{
		if (it->getName().compare(potion.getName()) == 0)
		{
			std::vector<std::string>::iterator it2;
			for (it2 = roomItemNames.begin(); it2 < roomItemNames.end(); it2++)
			{
				if (it2->compare(it->getName()) == 0)
				{
					roomItemNames.erase(it2);
					break;
				}
			}

			roomPotions.erase(it);
			break;
		}
	}
}