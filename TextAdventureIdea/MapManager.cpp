#include "pch.h"
#include "MapManager.h"
#include <iostream>

using namespace std;

MapManager *MapManager::instance = 0;

void MapManager::TransferToIventory(const char* item)
{
	//attempt to transfer to player inventory
}

void MapManager::CreateRooms()
{
	//NOTE: STARTING ROOM IS "A4"

	// H ROW
	roomMap["H1"] = Room(1, 0, 1, 1);
	roomMap["H5"] = Room(1, 0, 1, 0);
	roomMap["H6"] = Room(1, 0, 0, 1);
	// G ROW
	roomMap["G1"] = Room(0, 0, 1, 1);
	roomMap["G3"] = Room(1, 0, 1, 0);
	roomMap["G4"] = Room(1, 1, 0, 0);
	roomMap["G5"] = Room(0, 0, 0, 1);
	roomMap["G6"] = Room(0, 0, 1, 1);
	roomMap["G9"] = Room(1, 0, 1, 1);
	roomMap["G11"] = Room(1, 0, 1, 1);
	// F ROW
	roomMap["F1"] = Room(0, 0, 1, 1);
	roomMap["F3"] = Room(0, 1, 1, 1);
	roomMap["F4"] = Room(1, 1, 1, 0);
	roomMap["F5"] = Room(0, 1, 0, 1);
	roomMap["F6"] = Room(0, 1, 1, 0);
	roomMap["F7"] = Room(0, 1, 0, 0);
	roomMap["F8"] = Room(0, 1, 0, 0);
	roomMap["F9"] = Room(0, 0, 0, 0);
	roomMap["F10"] = Room(1, 1, 0, 0);
	roomMap["F11"] = Room(0, 1, 0, 0);
	roomMap["F12"] = Room(1, 1, 0, 1);

}

void MapManager::AddItemToRoom(const char* item, const char* gridID)
{

}

void MapManager::DescribeRoom(const char* gridID)
{
	system("cls");

	if (roomMap[gridID].hasNorthWall == true)
	{
		cout << "There is a wall to the North.\n";
	}
	if (roomMap[gridID].hasSouthWall == true)
	{
		cout << "There is a wall to the South.\n";
	}
	if (roomMap[gridID].hasEastWall == true)
	{
		cout << "There is a wall to the East.\n";
	}
	if (roomMap[gridID].hasWestWall == true)
	{
		cout << "There is a wall to the West.\n";
	}
	cout << endl;
}