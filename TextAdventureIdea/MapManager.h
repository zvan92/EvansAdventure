#pragma once
#include <list>
using namespace std;
class MapManager
{
private:
	MapManager();
	static MapManager *instance;

	struct Room
	{
		Room(const char* gridID, bool hasNorthwall, bool hasSouthWall, bool hasWestWall, bool hasEastWall) {};
		~Room();

		const char* gridID;
		bool hasNorthWall;
		bool hasSouthWall;
		bool hasWestWall;
		bool hasEastWall;
		list <const char*> roomItems;
	};

	void CreateRooms();

	list <Room> rooms;
public:
	~MapManager();
	static MapManager *Instance()
	{
		if (!instance)
		{
			instance = new MapManager;
		}
		return instance;
	}

	void TransferToIventory(const char* roomItem); //attempts to add to player inventory, runs a check through GameManager to see if possible
	void AddItemToRoom(const char* item, const char* gridID);
	void DescribeCurrentRoom(const char* gridID);
};

