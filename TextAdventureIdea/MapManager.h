#pragma once

#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include "Room.h"
#include "Chest.h"
#include "Key.h"
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

	enum class Direction
	{
		NORTH	= 0,
		SOUTH	= 1,
		EAST	= 2,
		WEST	= 3
	};

	unordered_map<string, Room> GetRoomMap() { return roomMap; }
	unordered_map<string, Room>* GetRoomMapPtr() { return &roomMap; }
	void CreateRooms();
	void DescribeRoom(string gridID);
	void TransferItemToPlayer(Key* key);
	int TransferItemToRoom(Key* key, string gridID);
	void TransferItemToPlayer(Food* food);
	int TransferItemToRoom(Food* food, string gridID);
	void TransferItemToPlayer(Potion* potion);
	int TransferItemToRoom(Potion* potion, string gridID);
	int TransferItemToRoom(Chest* chest, string gridID);
	void RemoveItem(Chest* chest);

private:
	static MapManager* instance;
	unordered_map<string, Room> roomMap;
};

