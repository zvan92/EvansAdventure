#pragma once

#include "Item.h"
#include "Food.h"
#include "Potion.h"
#include "Key.h"
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
		playerKeys(), 
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
	std::vector<Key> getPlayerKeys() { return playerKeys; }
	std::vector<Food> getPlayerFood() { return playerFood; }
	std::vector<Potion> getPlayerPotions() { return playerPotions; }
	std::vector<std::string> getPlayerItemNames() { return playerItemNames; }

	int AddItemToInventory(Key* key);
	int AddItemToInventory(Food* food);
	int AddItemToInventory(Potion* potion);
	void ResetProgress();
	void ConsumeItem(Key* key);
	void ConsumeItem(Food* food);
	void ConsumeItem(Potion* potion);
	void RemoveItem(Key* key);
	void DropItem(Key* key);
	void DropItem(Food* food);
	void DropItem(Potion* potion);

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
	std::vector<Key> playerKeys;
	std::vector<Food> playerFood;
	std::vector<Potion> playerPotions;
};
