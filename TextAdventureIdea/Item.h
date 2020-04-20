#pragma once

#include <string>

class Item
{
public:
	Item() : 
		name(""),
		damageFactor(0), 
		healFactor(0),
		isRedKey(false),
		isBlueKey(false),
		isGreenKey(false) {};
	~Item() {};

//PUBLIC METHODS=========================================//

	void setDamageFactor(int value) { damageFactor = value; }
	void setHealFactor(int value) { healFactor = value; }
	void setName(std::string value) { name = value; }
	std::string getName() { return name; }

protected:
	int damageFactor;
	int healFactor;
	std::string name;
	bool isRedKey;
	bool isBlueKey;
	bool isGreenKey;

	void HealPlayer();
	void DamagePlayer();
	//each item will produce different interactions
	virtual void CombineWithItem(Item* item) {};
};
