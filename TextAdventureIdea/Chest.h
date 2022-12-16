#pragma once

#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

class Key;

class Chest : public Item
{
public:
	Chest() :
		isBlue(false),
		isGreen(false),
		isRed(false),
		isYellow(false),
		iItemCount(0)
	{
		isChest = true;
	};
	~Chest() {};

	Chest(const Item& item) :
		Item(item),
		isBlue(false),
		isGreen(false),
		isRed(false),
		isYellow(false),
		iItemCount(0)
	{
		isChest = true;
	};

	bool getIsBlue() { return isBlue; }
	void setIsBlue(bool value) { isBlue = value; }
	bool getIsGreen() { return isGreen; }
	void setIsGreen(bool value) { isGreen = value; }
	bool getIsRed() { return isRed; }
	void setIsRed(bool value) { isRed = value; }
	bool getIsYellow() { return isYellow; }
	void setIsYellow(bool value) { isYellow = value; }
	int getItemCount() { return iItemCount; }
	void setItemCount(int value) { iItemCount = value; }
	std::vector<Key> getChestKeys() { return chestKeys; }
	std::vector<Food> getChestFood() { return chestFood; }
	std::vector<Potion> getChestPotions() { return chestPotions; }
	std::vector<std::string> getChestItemNames() { return chestItemNames; }

	int AddItemToChest(Food* food);
	int AddItemToChest(Potion* potion);
	int AddItemToChest(Key* key);
	void RemoveItemFromChest(Food* food);
	void RemoveItemFromChest(Potion* potion);
	void RemoveItemFromChest(Key* key);

private:
	bool isBlue;
	bool isGreen;
	bool isRed;
	bool isYellow;
	int iItemCount;
	std::vector<std::string> chestItemNames;
	std::vector<Key> chestKeys;
	std::vector<Food> chestFood;
	std::vector<Potion> chestPotions;
	
};