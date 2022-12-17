#pragma once

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
		hasNorthDoor(false),
		hasSouthDoor(false),
		hasWestDoor(false),
		hasEastDoor(false),
		roomKeys(),
		roomFood(),
		roomPotions(),
		roomChests(),
		iRoomItemCount(0) {};
	~Room() {};

	Room(bool setNorthWall,
		bool setSouthWall,
		bool setWestWall,
		bool setEastWall,
		bool setNorthDoor,
		bool setSouthDoor,
		bool setWestDoor,
		bool setEastDoor) :
		hasNorthWall(setNorthWall),
		hasSouthWall(setSouthWall),
		hasWestWall(setWestWall),
		hasEastWall(setEastWall),
		hasNorthDoor(setNorthDoor),
		hasSouthDoor(setSouthDoor),
		hasWestDoor(setWestDoor),
		hasEastDoor(setEastDoor),
		iRoomItemCount(0) {};

	bool GetHasNorthWall() { return hasNorthWall; }
	void SetHasNorthWall(bool value) { hasNorthWall = value; }
	bool GetHasSouthWall() { return hasSouthWall; }
	void SetHasSouthWall(bool value) { hasSouthWall = value; }
	bool GetHasEastWall() { return hasEastWall; }
	void SetHasEastWall(bool value) { hasEastWall = value; }
	bool GetHasWestWall() { return hasWestWall; }
	void SetHasWestWall(bool value) { hasWestWall = value; }
	bool GetHasNorthDoor() { return hasNorthDoor; }
	void SetHasNorthDoor(bool value) { hasNorthDoor = value; }
	bool GetHasSouthDoor() { return hasSouthDoor; }
	void SetHasSouthDoor(bool value) { hasSouthDoor = value; }
	bool GetHasEastDoor() { return hasEastDoor; }
	void SetHasEastDoor(bool value) { hasEastDoor = value; }
	bool GetHasWestDoor() { return hasWestDoor; }
	void SetHasWestDoor(bool value) { hasWestDoor = value; }

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

private:
	bool hasNorthWall;
	bool hasSouthWall;
	bool hasWestWall;
	bool hasEastWall;
	bool hasNorthDoor;
	bool hasSouthDoor;
	bool hasWestDoor;
	bool hasEastDoor;
	std::vector<std::string> roomItemNames;
	std::vector<Key> roomKeys;
	std::vector<Food> roomFood;
	std::vector<Potion> roomPotions;
	std::vector<Chest> roomChests;
	int iRoomItemCount;

};