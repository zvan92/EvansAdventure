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
		hasForwardWall(false),
		hasBackwardWall(false),
		hasRightWall(false),
		hasLeftWall(false),
		hasForwardDoor(false),
		hasBackwardDoor(false),
		hasRightDoor(false),
		hasLeftDoor(false),
		roomKeys(),
		roomFood(),
		roomPotions(),
		roomChests(),
		iRoomItemCount(0) {};
	~Room() {};

	Room(bool setForwardWall,
		bool setBackwardWall,
		bool setRightWall,
		bool setLeftWall,
		bool setForwardDoor,
		bool setBackwardDoor,
		bool setRightDoor,
		bool setLeftDoor) :
		hasForwardWall(setForwardWall),
		hasBackwardWall(setBackwardWall),
		hasRightWall(setRightWall),
		hasLeftWall(setLeftWall),
		hasForwardDoor(setForwardDoor),
		hasBackwardDoor(setBackwardDoor),
		hasRightDoor(setRightDoor),
		hasLeftDoor(setLeftDoor),
		iRoomItemCount(0) {};

	bool GetHasForwardWall() { return hasForwardWall; }
	void SetHasForwardWall(bool value) { hasForwardWall = value; }
	bool GetHasBackwardWall() { return hasBackwardWall; }
	void SetHasBackwardWall(bool value) { hasBackwardWall = value; }
	bool GetHasRightWall() { return hasRightWall; }
	void SetHasRightWall(bool value) { hasRightWall = value; }
	bool GetHasLeftWall() { return hasLeftWall; }
	void SetHasLeftWall(bool value) { hasLeftWall = value; }
	bool GetHasForwardDoor() { return hasForwardDoor; }
	void SetHasForwardDoor(bool value) { hasForwardDoor = value; }
	bool GetHasBackwardDoor() { return hasBackwardDoor; }
	void SetHasBackwardDoor(bool value) { hasBackwardDoor = value; }
	bool GetHasRightDoor() { return hasRightDoor; }
	void SetHasRightDoor(bool value) { hasRightDoor = value; }
	bool GetHasLeftDoor() { return hasLeftDoor; }
	void SetHasLeftDoor(bool value) { hasLeftDoor = value; }

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
	bool hasForwardWall;
	bool hasBackwardWall;
	bool hasRightWall;
	bool hasLeftWall;
	bool hasForwardDoor;
	bool hasBackwardDoor;
	bool hasRightDoor;
	bool hasLeftDoor;
	std::vector<std::string> roomItemNames;
	std::vector<Key> roomKeys;
	std::vector<Food> roomFood;
	std::vector<Potion> roomPotions;
	std::vector<Chest> roomChests;
	int iRoomItemCount;

};