#include "pch.h"
#include "Room.h"
#include <iostream>
#include <vector>

void Room::AddRoomFood(Food food)
{
	std::vector<Food>::iterator it;
	it = roomFood.begin();
	roomFood.insert(it, food);
}

void Room::RemoveRoomFood(Food food)
{
	std::vector<Food>::iterator it;
	for (it = roomFood.begin(); it < roomFood.end(); it++)
	{
		if (it->getName().compare(food.getName()) == 0)
		{
			roomFood.erase(it);
		}
		break;
	}
}