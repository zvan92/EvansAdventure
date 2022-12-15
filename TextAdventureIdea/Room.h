#pragma once

//#include "MapManager.h"
#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include "Chest.h"
#include "Key.h"
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
		roomKeys(),
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
	std::vector<Key> GetRoomKeys() { return roomKeys; }
	std::vector<Food> GetRoomFood() { return roomFood; }
	std::vector<Potion> GetRoomPotions() { return roomPotions; }
	std::vector<Chest> GetRoomChests() { return roomChests; }
	int GetRoomItemCount() { return iRoomItemCount; }
	
	void AddRoomItem(Key* key);
	void AddRoomItem(Food* food);
	void AddRoomItem(Potion* potion);
	void AddRoomItem(Chest* chest);

	void RemoveRoomItem(Key* key);
	void RemoveRoomItem(Food* food);
	void RemoveRoomItem(Potion* potion);
	void RemoveRoomItem(Chest* chest);
	//TODO: roomDoors

private:
	bool hasNorthWall;
	bool hasSouthWall;
	bool hasWestWall;
	bool hasEastWall;
	std::vector<std::string> roomItemNames;
	std::vector<Key> roomKeys;
	std::vector<Food> roomFood;
	std::vector<Potion> roomPotions;
	std::vector<Chest> roomChests;
	int iRoomItemCount;
	//TODO: roomDoors

};