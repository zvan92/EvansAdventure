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

	Potion(const Item& item) :
		Item(item),
		isPoison(false)
	{
		isPotion = true;
	};

	bool getIsPoison() { return isPoison; }
	void setIsPoison(bool value) { isPoison = value; }

private:
	void CombineWithItem(Item& item);
	bool isPoison;
};