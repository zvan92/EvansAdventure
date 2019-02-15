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
			hasEastWall = setEastWall;
			hasWestWall = setWestWall;
		};

		bool hasNorthWall;
		bool hasSouthWall;
		bool hasEastWall;
		bool hasWestWall;
		list <const char*> roomItems;
		//progression puzzle string?
	};

	unordered_map<const char*, Room> roomMap; //to store the rooms: char* is key (i.e. "A1", Room is the object)

	void TransferToIventory(const char* roomItem); //attempts to add to player inventory, runs a check through GameManager to see if possible
	void AddItemToRoom(const char* item, const char* gridID);
	void DescribeRoom(const char* gridID);
	void CreateRooms();

private:
	static MapManager *instance;
};

