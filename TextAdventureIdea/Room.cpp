#include "pch.h"
#include "Room.h"
#include <iostream>
#include <vector>
// Can't instantiate Item objects - will be replaced with Key eventually
void Room::AddRoomItem(Item* item)
{
	std::vector<Item>::iterator it;
	it = roomItems.begin();
	roomItems.insert(it, *item);
	std::vector<std::string>::iterator it2;
	it2 = roomItemNames.begin();
	roomItemNames.insert(it2, item->getName());
	iRoomItemCount++;
}
// Can't instantiate Item objects - will be replaced with Key eventually
void Room::RemoveRoomItem(Item* item)
{
	std::vector<Item>::iterator it;
	for (it = roomItems.begin(); it < roomItems.end(); it++)
	{
		if (it->getName().compare(item->getName()) == 0)
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
	iRoomItemCount--;
}

void Room::AddRoomItem(Food* food)
{
	std::vector<Food>::iterator it;
	it = roomFood.begin();
	roomFood.insert(it, *food);
	std::vector<std::string>::iterator it2;
	it2 = roomItemNames.begin();
	roomItemNames.insert(it2, food->getName());
	iRoomItemCount++;
}

void Room::RemoveRoomItem(Food* food)
{
	std::vector<Food>::iterator it;
	for (it = roomFood.begin(); it < roomFood.end(); it++)
	{
		if (it->getName().compare(food->getName()) == 0)
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
	iRoomItemCount--;
}

void Room::AddRoomItem(Potion* potion)
{
	std::vector<Potion>::iterator it;
	it = roomPotions.begin();
	roomPotions.insert(it, *potion);
	std::vector<std::string>::iterator it2;
	it2 = roomItemNames.begin();
	roomItemNames.insert(it2, potion->getName());
	iRoomItemCount++;
}

void Room::RemoveRoomItem(Potion* potion)
{
	std::vector<Potion>::iterator it;
	for (it = roomPotions.begin(); it < roomPotions.end(); it++)
	{
		if (it->getName().compare(potion->getName()) == 0)
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
	iRoomItemCount--;
}

void Room::AddRoomItem(Chest* chest)
{
	std::vector<Chest>::iterator it;
	it = roomChests.begin();
	roomChests.insert(it, *chest);
	std::vector<std::string>::iterator it2;
	it2 = roomItemNames.begin();
	roomItemNames.insert(it2, chest->getName());
	iRoomItemCount++;
}

void Room::RemoveRoomItem(Chest* chest)
{
	std::vector<Chest>::iterator it;
	for (it = roomChests.begin(); it < roomChests.end(); it++)
	{
		if (it->getName().compare(chest->getName()) == 0)
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

			roomChests.erase(it);
			break;
		}
	}
	iRoomItemCount--;
}