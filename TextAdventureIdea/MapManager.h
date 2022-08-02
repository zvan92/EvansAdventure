#pragma once

#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include "Room.h"
#include "Chest.h"
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
	int TransferItemToRoom(Item item, string gridID);
	void TransferItemToPlayer(Food food);
	int TransferItemToRoom(Food food, string gridID);
	void TransferItemToPlayer(Potion potion);
	int TransferItemToRoom(Potion potion, string gridID);
	int TransferItemToRoom(Chest chest, string gridID);
	void RemoveItem(Chest chest);
	//TODO: transferKeyToPlayer
	//TODO: transferKeyToRoom

private:
	static MapManager *instance;

	unordered_map<string, Room> roomMap;
};

