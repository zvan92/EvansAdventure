#pragma once

//#include "MapManager.h"
#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include <list>
#include <string>
#include <vector>

class Room
{
public:
	Room() :
		hasNorthWall(false),
		hasSouthWall(false),
		hasWestWall(false),
		hasEastWall(false),
		roomItemNames(),
		roomItems(),
		roomFood(),
		roomPotions() {};
	~Room() {};

	Room(bool setNorthWall,
		bool setSouthWall,
		bool setWestWall,
		bool setEastWall) :
		hasNorthWall(setNorthWall),
		hasSouthWall(setSouthWall),
		hasWestWall(setWestWall),
		hasEastWall(setEastWall) {};

//PUBLIC METHODS=========================================//

	bool GetHasNorthWall() { return hasNorthWall; }
	bool GetHasSouthWall() { return hasSouthWall; }
	bool GetHasEastWall() { return hasEastWall; }
	bool GetHasWestWall() { return hasWestWall; }
	std::vector<std::string> GetRoomItemNames() { return roomItemNames; }
	std::vector<Item> GetRoomItems() { return roomItems; }
	std::vector<Food> GetRoomFood() { return roomFood; }
	std::vector<Potion> GetRoomPotions() { return roomPotions; }
	void AddRoomItem(Item item);
	void AddRoomFood(Food food);
	void AddRoomPotion(Potion potion);
	void RemoveRoomItem(Item item);
	void RemoveRoomFood(Food food);
	void RemoveRoomPotion(Potion potion);
	//TODO: roomKeys
	//TODO: roomDoors
	//TODO: roomChests

private:
	bool hasNorthWall;
	bool hasSouthWall;
	bool hasWestWall;
	bool hasEastWall;
	std::vector<std::string> roomItemNames;
	std::vector<Item> roomItems;
	std::vector<Food> roomFood;
	std::vector<Potion> roomPotions;
	//TODO: roomKeys
	//TODO: roomDoors
	//TODO: roomChests
};