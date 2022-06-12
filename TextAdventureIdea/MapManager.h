#pragma once

#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include "Room.h"
#include <unordered_map>

using namespace std;

class MapManager
{
public:
	MapManager() {};
	~MapManager() {};

	static MapManager* GetInstance()
	{
		if (!instance)
		{
			instance = new MapManager;
		}
		return instance;
	}

	enum Direction
	{
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

//PUBLIC METHODS=========================================//

	unordered_map<string, Room> GetRoomMap() { return roomMap; }

	void CreateRooms();
	void DescribeRoom(string gridID);
	void TransferItemToPlayer(Item item);
	void TransferItemToRoom(Item item);
	void TransferFoodToPlayer(Food food);
	void TransferFoodToRoom(Food food);
	void TransferPotionToPlayer(Potion potion);
	void TransferPotionToRoom(Potion potion);
	//TODO: transferKeyToPlayer
	//TODO: transferKeyToRoom

private:
	static MapManager *instance;

	unordered_map<string, Room> roomMap;
};

