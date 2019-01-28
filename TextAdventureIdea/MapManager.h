#pragma once
#include <list>
#include <unordered_map>
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
		//progression puzzle string?
	};

	void CreateRooms();
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

	unordered_map<const char*, Room> rMap; //to store the rooms

	void TransferToIventory(const char* roomItem); //attempts to add to player inventory, runs a check through GameManager to see if possible
	void AddItemToRoom(const char* item, const char* gridID);
	void DescribeRoom(const char* gridID);
};

