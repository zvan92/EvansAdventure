#pragma once
#include <list>
#include <unordered_map>
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
		//progression puzzle string?
	};

	// don't want this to be public, i'm sure
	unordered_map<string, Room> roomMap; //to store the rooms: string is key (i.e. "A1", Room is the object)

	void TransferToIventory(string roomItem); //attempts to add to player inventory, runs a check through GameManager to see if possible
	void AddItemToRoom(string item, string gridID);
	void DescribeRoom(string gridID);
	void CreateRooms();

private:
	static MapManager *instance;
};

