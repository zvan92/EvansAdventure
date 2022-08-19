#pragma once

#include <string>

class Item
{
public:
	Item() : 
		name(""),
		damageFactor(0), 
		healFactor(0),
		isFood(false),
		isPotion(false),
		isKey(false),
		isChest(false) {};
	~Item() {};

	Item(const Item& item) :
		name(item.name),
		damageFactor(item.damageFactor),
		healFactor(item.healFactor),
		isFood(item.isFood),
		isPotion(item.isPotion),
		isKey(item.isKey),
		isChest(item.isChest) {};

	void setDamageFactor(int value) { damageFactor = value; }
	int getDamageFactor() { return damageFactor; }
	void setHealFactor(int value) { healFactor = value; }
	int getHealFactor() { return healFactor; }
	void setName(std::string value) { name = value; }
	std::string getName() { return name; }
	void setIsFood(int value) { isFood = value; }
	int getIsFood() { return isFood; }
	void setIsPotion(int value) { isPotion = value; }
	int getIsPotion() { return isPotion; }
	void setIsKey(int value) { isKey = value; }
	int getIsKey() { return isKey; }
	void setIsChest(int value) { isChest = value; }
	int getIsChest() { return isChest; }

protected:
	std::string name;
	bool isFood;
	bool isPotion;
	bool isKey;
	bool isChest;
	int damageFactor;
	int healFactor;
};
