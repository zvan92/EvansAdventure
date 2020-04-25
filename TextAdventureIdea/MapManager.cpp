#include "pch.h"
#include "MapManager.h"
#include "Room.h"
#include "Player.h"
#include <iostream>

using namespace std;

MapManager *MapManager::instance = 0;

void MapManager::CreateRooms()
{
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
	roomMap["F3"] = Room(0, 0, 1, 1);
	roomMap["F4"] = Room(1, 1, 1, 0);
	roomMap["F5"] = Room(0, 1, 0, 1);
	roomMap["F6"] = Room(0, 1, 1, 0);
	roomMap["F7"] = Room(1, 1, 0, 0);
	roomMap["F8"] = Room(1, 1, 0, 0);
	roomMap["F9"] = Room(0, 0, 0, 0);
	roomMap["F10"] = Room(1, 1, 0, 0);
	roomMap["F11"] = Room(0, 1, 0, 0);
	roomMap["F12"] = Room(1, 1, 0, 1);
	// E ROW
	roomMap["E1"] = Room(0, 1, 1, 0);
	roomMap["E2"] = Room(1, 1, 0, 0);
	roomMap["E3"] = Room(0, 1, 0, 0);
	roomMap["E4"] = Room(1, 1, 0, 0);
	roomMap["E5"] = Room(1, 0, 0, 0);
	roomMap["E6"] = Room(1, 0, 0, 1);
	roomMap["E7"] = Room(1, 0, 1, 0);
	roomMap["E8"] = Room(1, 1, 0, 1);
	roomMap["E9"] = Room(0, 0, 1, 1);
	roomMap["E10"] = Room(1, 1, 1, 0);
	roomMap["E11"] = Room(1, 1, 0, 0);
	roomMap["E12"] = Room(1, 0, 0, 1);
	// D ROW
	roomMap["D1"] = Room(1, 1, 1, 0);
	roomMap["D2"] = Room(1, 1, 0, 0);
	roomMap["D3"] = Room(1, 0, 0, 0);
	roomMap["D4"] = Room(1, 1, 0, 0);
	roomMap["D5"] = Room(0, 1, 0, 1);
	roomMap["D6"] = Room(0, 0, 1, 1);
	roomMap["D7"] = Room(0, 1, 1, 0);
	roomMap["D8"] = Room(1, 0, 0, 0);
	roomMap["D9"] = Room(0, 1, 0, 1);
	roomMap["D10"] = Room(1, 1, 1, 0);
	roomMap["D11"] = Room(1, 0, 0, 0);
	roomMap["D12"] = Room(0, 1, 0, 1);
	// C ROW
	roomMap["C1"] = Room(1, 1, 1, 0);
	roomMap["C2"] = Room(1, 0, 0, 0);
	roomMap["C3"] = Room(0, 0, 0, 1);
	roomMap["C4"] = Room(1, 0, 1, 0);
	roomMap["C5"] = Room(1, 1, 0, 0);
	roomMap["C6"] = Room(0, 1, 0, 1);
	roomMap["C7"] = Room(1, 0, 1, 0);
	roomMap["C8"] = Room(0, 1, 0, 0);
	roomMap["C9"] = Room(1, 1, 0, 0);
	roomMap["C10"] = Room(1, 1, 0, 1);
	roomMap["C11"] = Room(0, 0, 1, 0);
	roomMap["C12"] = Room(1, 0, 0, 1);
	// B ROW
	roomMap["B2"] = Room(0, 0, 1, 1);
	roomMap["B3"] = Room(0, 1, 1, 1);
	roomMap["B4"] = Room(0, 0, 1, 1);
	roomMap["B5"] = Room(1, 0, 1, 0);
	roomMap["B6"] = Room(1, 1, 0, 0);
	roomMap["B7"] = Room(0, 1, 0, 0);
	roomMap["B8"] = Room(1, 0, 0, 0);
	roomMap["B9"] = Room(1, 1, 0, 0);
	roomMap["B10"] = Room(1, 1, 0, 1);
	roomMap["B11"] = Room(0, 0, 1, 1);
	roomMap["B12"] = Room(0, 1, 1, 0);
	roomMap["B13"] = Room(0, 0, 0, 0); // THE EXIT ROOM!
	// A ROW
	roomMap["A2"] = Room(0, 1, 1, 0);
	roomMap["A3"] = Room(1, 1, 0, 0);
	roomMap["A4"] = Room(0, 1, 0, 1); // THE START!
	roomMap["A5"] = Room(0, 1, 1, 0);
	roomMap["A6"] = Room(1, 1, 0, 0);
	roomMap["A7"] = Room(1, 1, 0, 1);
	roomMap["A8"] = Room(0, 1, 1, 0);
	roomMap["A9"] = Room(1, 1, 0, 0);
	roomMap["A10"] = Room(1, 1, 0, 0);
	roomMap["A11"] = Room(0, 1, 0, 0);
	roomMap["A12"] = Room(1, 1, 0, 1);
}

void MapManager::DescribeRoom(string gridID)
{
	system("cls");

	if (roomMap[gridID].GetHasNorthWall() == true)
	{
		cout << "There is a wall to the North.\n";
	}
	if (roomMap[gridID].GetHasSouthWall() == true)
	{
		cout << "There is a wall to the South.\n";
	}
	if (roomMap[gridID].GetHasEastWall() == true)
	{
		cout << "There is a wall to the East.\n";
	}
	if (roomMap[gridID].GetHasWestWall() == true)
	{
		cout << "There is a wall to the West.\n";
	}
	if (roomMap[gridID].GetHasNorthWall() == false &&
		roomMap[gridID].GetHasSouthWall() == false &&
		roomMap[gridID].GetHasEastWall() == false &&
		roomMap[gridID].GetHasWestWall() == false)
	{
		cout << "There are no walls nearby.\n";
	}

	cout << endl;
}

void MapManager::TransferItemToPlayer(string item)
{
	/*TODO
	#1) Player::GetInstance()->AddItemToInventory(item)
	#2) remove item from roomItemMap
	*/
}

void MapManager::TransferItemToRoom(string item, string gridID)
{
	/*TODO
	#1) Player::DropItem(item)
	#2) add item to roomItemMap
	*/
}