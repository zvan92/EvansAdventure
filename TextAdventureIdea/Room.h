#pragma once

#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include <list>
#include <string>

class Room
{
public:
	Room() :
		hasNorthWall(false),
		hasSouthWall(false),
		hasWestWall(false),
		hasEastWall(false) {};
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
	//TODO: getItemNamesList
	//TODO: getItemList
	//TODO: getFoodList
	//TODO: getPotionList
	//TODO: getKeyList
	//TODO: getDoorList
	//TODO: getChestList

private:
	bool hasNorthWall;
	bool hasSouthWall;
	bool hasWestWall;
	bool hasEastWall;
	//TODO: itemNamesList
	//TODO: itemList
	//TODO: foodList
	//TODO: potionList
	//TODO: keyList
	//TODO: doorList
	//TODO: chestList
};