#pragma once

#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include <iostream>
#include <string>
#include <vector>

class Player
{

public:
	Player() :
		sCurrentGridID(""),
		sName(""),
		iEnergy(0),
		iInventoryCount(0),
		iTurnsCompleted(0),
		// Can't instantiate Item objects - will be replaced with Key eventually
		playerItems(), 
		playerFood(), 
		playerPotions() {};
	~Player() {};

	static Player *GetInstance()
	{
		if (!instance)
		{
			instance = new Player;
		}
		return instance;
	}

	void setCurrentLocationGridID(std::string value) { sCurrentGridID = value; }
	std::string getCurrentLocationGridID() { return sCurrentGridID; }
	void setPlayerEnergy(int value) { iEnergy = value; }
	int getPlayerEnergy() { return iEnergy; }
	void setPlayerName(std::string value) { sName = value; }
	std::string getPlayerName() { return sName; }
	void setTurnsCompleted(int value) { iTurnsCompleted = value; }
	int getTurnsCompleted() { return iTurnsCompleted; }
	void setInventoryCount(int value) { iInventoryCount = value; }
	int getInventoryCount() { return iInventoryCount; }
	// Can't instantiate Item objects - will be replaced with Key eventually
	std::vector<Item> getPlayerItems() { return playerItems; }
	std::vector<Food> getPlayerFood() { return playerFood; }
	std::vector<Potion> getPlayerPotions() { return playerPotions; }
	std::vector<std::string> getPlayerItemNames() { return playerItemNames; }
	// Can't instantiate Item objects - will be replaced with Key eventually
	int AddItemToInventory(Item* item);
	int AddItemToInventory(Food* food);
	int AddItemToInventory(Potion* potion);
	void ResetProgress();
	// Can't instantiate Item objects - will be replaced with Key eventually
	void ConsumeItem(Item* item);
	void ConsumeItem(Food* food);
	void ConsumeItem(Potion* potion);
	// Can't instantiate Item objects - will be replaced with Key eventually
	void RemoveItem(Item* item);
	// Can't instantiate Item objects - will be replaced with Key eventually
	void DropItem(Item* item);
	void DropItem(Food* food);
	void DropItem(Potion* potion);
	//TODO: playerKeys
	void LookAround();
	void MoveNorth();
	void MoveSouth();
	void MoveEast();
	void MoveWest();

private:
	static Player *instance;
	std::string sCurrentGridID; //The Grid ID is an X/Y coordinate; the X is represented by a letter and the Y is represented by a number (e.g. A5).
	std::string sName;
	int iEnergy;
	int iTurnsCompleted;
	int iInventoryCount;
	std::vector<std::string> playerItemNames;
	// Can't instantiate Item objects - will be replaced with Key eventually
	std::vector<Item> playerItems;
	std::vector<Food> playerFood;
	std::vector<Potion> playerPotions;
	//TODO: playerKeys
	
};
