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
		isKey(false) {};
	~Item() {};

	Item(const Item& item) :
		name(item.name),
		damageFactor(item.damageFactor),
		healFactor(item.healFactor),
		isFood(item.isFood),
		isPotion(item.isPotion),
		isKey(item.isKey) {};

//PUBLIC METHODS=========================================//

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

	void setIskey(int value) { isKey = value; }
	int getIsKey() { return isKey; }

protected:
	bool isFood;
	bool isPotion;
	bool isKey;
	int damageFactor;
	int healFactor;
	std::string name;

	//each item combination will produce different interactions
	virtual void CombineWithItem(Item* item) {};
};
