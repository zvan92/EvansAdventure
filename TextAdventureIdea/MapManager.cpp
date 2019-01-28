#include "pch.h"
#include "MapManager.h"

MapManager *MapManager::instance = 0;

MapManager::MapManager()
{
}
MapManager::~MapManager()
{
}

void MapManager::TransferToIventory(const char* item)
{
	//attempt to transfer to player inventory
}

void MapManager::CreateRooms()
{
	//each room object will be initialized into an unordered map
	rMap["A1"] = Room("A1", true, true, true, true);
}

void MapManager::AddItemToRoom(const char* item, const char* gridID)
{

}

void MapManager::DescribeRoom(const char* gridID)
{
	// USE UNORDERED MAP FOR THIS

	// -> match passed in gridID to map key and return the room
	// -> cout message saying what walls are present
	// -> cout contents of room's item list
}