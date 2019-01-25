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
	rooms.push_front(Room("A1", true, true, true, true));
}

void MapManager::AddItemToRoom(const char* item, const char* gridID)
{

}

void MapManager::DescribeCurrentRoom(const char* gridID)
{
	// USE DICTIONARIES FOR THIS!!! LOOK IT UP

	// iterate through list and target room with matching 'gridID'
	// -> cout message saying if a wall is present
	// -> cout contents of room's item list
}