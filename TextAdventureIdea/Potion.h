#pragma once

#include "Item.h"

class Potion : public Item
{
public:
	Potion() :
		isPoison(false)
	{
		isPotion = true;
	};
	~Potion() {};

	bool getIsPoison() { return isPoison; }
	void setIsPoison(bool value) { isPoison = value; }

private:
	bool isPoison;
};