#pragma once

//#include "MapManager.h"
#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include "Chest.h"
#include <list>
#include <string>
#include <vector>

using namespace std;

class Room
{
public:
	Room() :
		hasNorthWall(false),
		hasSouthWall(false),
		hasWestWall(false),
		hasEastWall(false),
		// Can't instantiate Item objects - will be replaced with Key eventually
		roomItems(),
		roomFood(),
		roomPotions(),
		roomChests(),
		iRoomItemCount(0) {};
	~Room() {};

	Room(bool setNorthWall,
		bool setSouthWall,
		bool setWestWall,
		bool setEastWall) :
		hasNorthWall(setNorthWall),
		hasSouthWall(setSouthWall),
		hasWestWall(setWestWall),
		hasEastWall(setEastWall),
		iRoomItemCount(0) {};

	bool GetHasNorthWall() { return hasNorthWall; }
	bool GetHasSouthWall() { return hasSouthWall; }
	bool GetHasEastWall() { return hasEastWall; }
	bool GetHasWestWall() { return hasWestWall; }
	std::vector<std::string> GetRoomItemNames() { return roomItemNames; }
	// Can't instantiate Item objects - will be replaced with Key eventually
	std::vector<Item> GetRoomItems() { return roomItems; }
	std::vector<Food> GetRoomFood() { return roomFood; }
	std::vector<Potion> GetRoomPotions() { return roomPotions; }
	std::vector<Chest> GetRoomChests() { return roomChests; }
	int GetRoomItemCount() { return iRoomItemCount; }
	// Can't instantiate Item objects - will be replaced with Key eventually
	void AddRoomItem(Item* item);
	void AddRoomItem(Food* food);
	void AddRoomItem(Potion* potion);
	void AddRoomItem(Chest* chest);
	// Can't instantiate Item objects - will be replaced with Key eventually
	void RemoveRoomItem(Item* item);
	void RemoveRoomItem(Food* food);
	void RemoveRoomItem(Potion* potion);
	void RemoveRoomItem(Chest* chest);
	//TODO: roomKeys
	//TODO: roomDoors

private:
	bool hasNorthWall;
	bool hasSouthWall;
	bool hasWestWall;
	bool hasEastWall;
	std::vector<std::string> roomItemNames;
	// Can't instantiate Item objects - will be replaced with Key eventually
	std::vector<Item> roomItems;
	std::vector<Food> roomFood;
	std::vector<Potion> roomPotions;
	std::vector<Chest> roomChests;
	int iRoomItemCount;
	//TODO: roomKeys
	//TODO: roomDoors

};