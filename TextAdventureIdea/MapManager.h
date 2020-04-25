#pragma once

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
	void TransferItemToPlayer(string roomItem);
	void TransferItemToRoom(string item, string gridID);


private:
	static MapManager *instance;

	unordered_map<string, Room> roomMap;
	//TODO: roomItemMap <string, std::vector<Item>>
};

