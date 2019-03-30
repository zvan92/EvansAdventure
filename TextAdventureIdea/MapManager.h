#pragma once

#include <list>
#include <unordered_map>
#include <string>

using namespace std;

class MapManager
{
public:
	MapManager() {};
	~MapManager() {};

	static MapManager *Instance()
	{
		if (!instance)
		{
			instance = new MapManager;
		}
		return instance;
	}

	struct Room
	{
		Room() {};
		~Room() {};

		Room(bool setNorthWall, bool setSouthWall, bool setWestWall, bool setEastWall) 
		{
			hasNorthWall = setNorthWall;
			hasSouthWall = setSouthWall;
			hasWestWall = setWestWall;
			hasEastWall = setEastWall;
		};

		bool hasNorthWall;
		bool hasSouthWall;
		bool hasWestWall;
		bool hasEastWall;
		list <string> roomItems;
		//TODO: puzzle progression item
	};

	// TODO: make this map NOT public
	unordered_map<string, Room> roomMap;

//FUNCTIONS========================================//

	void TransferToPlayerIventory(string roomItem);
	void TransferItemToRoom(string item, string gridID);
	void DescribeRoom(string gridID);
	void CreateRooms();

//=================================================//
private:
	static MapManager *instance;
};

