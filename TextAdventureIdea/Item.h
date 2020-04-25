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
		isRedKey(false),
		isBlueKey(false),
		isGreenKey(false) {};
	~Item() {};

	Item(const Item& item) :
		name(item.name),
		damageFactor(item.damageFactor),
		healFactor(item.healFactor),
		isFood(item.isFood),
		isRedKey(item.isRedKey),
		isBlueKey(item.isBlueKey),
		isGreenKey(item.isGreenKey) {};

//PUBLIC METHODS=========================================//

	void setDamageFactor(int value) { damageFactor = value; }
	int getDamageFactor() { return damageFactor; }

	void setHealFactor(int value) { healFactor = value; }
	int getHealFactor() { return healFactor; }

	void setName(std::string value) { name = value; }
	std::string getName() { return name; }

	void setIsFood(int value) { isFood = value; }
	int getIsFood() { return isFood; }

	void setIsRedkey(int value) { isRedKey = value; }
	int getIsRedKey() { return isRedKey; }

	void setIsBlueKey(int value) { isBlueKey = value; }
	int getIsBlueKey() { return isBlueKey; }

	void setIsGreenKey(int value) { isGreenKey = value; }
	int getIsGreenKey() { return isGreenKey; }

protected:
	int damageFactor;
	int healFactor;
	std::string name;
	bool isFood;
	bool isRedKey;
	bool isBlueKey;
	bool isGreenKey;

	//each item will produce different interactions
	virtual void CombineWithItem(Item* item) {};
};
