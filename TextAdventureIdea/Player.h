#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Food.h"

#define MAX_INVENTORY_ITEMS 6

class Player
{

public:
	Player() :
		sCurrentGridID(""),
		sName(""),
		iHealth(0),
		iTurnsCompleted(0),
		playerItems() {};
	~Player() {};

	static Player *GetInstance()
	{
		if (!instance)
		{
			instance = new Player;
		}
		return instance;
	}

//PUBLIC METHODS=========================================//

	void setCurrentLocationGridID(std::string value) { sCurrentGridID = value; }
	std::string getCurrentLocationGridID() { return sCurrentGridID; }

	void setPlayerHealth(int value) { iHealth = value; }
	int getPlayerHealth() { return iHealth; }

	void setPlayerName(std::string value) { sName = value; }
	std::string getPlayerName() { return sName; }

	void setTurnsCompleted(int value) { iTurnsCompleted = value; }
	int getTurnsCompleted() { return iTurnsCompleted; }

	std::vector<Item> getPlayerItems() { return playerItems; }

	void AddItemToInventory(Item& item);
	void LookAround();
	void MoveNorth();
	void MoveSouth();
	void MoveEast();
	void MoveWest();

private:
	static Player *instance;

	//The Grid ID is an X/Y coordinate; the X is represented by a letter and the Y is represented by a number (e.g. A5).
	std::string sCurrentGridID;
	std::string sName;
	int iHealth;
	int iTurnsCompleted;
	std::vector<Item> playerItems;
};
