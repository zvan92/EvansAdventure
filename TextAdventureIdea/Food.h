#pragma once

#include "Item.h"

class Food : public Item
{
public:
	Food() : bIsRotten(false) {};
	~Food() {};

	Food(const Item& item) :
		Item(item),
		bIsRotten(false)
	{
		// if the food has a damage factor, it's rotten
		(damageFactor > 0) ? (bIsRotten = true) : (bIsRotten = false);
	};

	bool getIsRotten() { return bIsRotten; }
	void setIsRotten(bool value) { bIsRotten = value; }

private:
	void CombineWithItem(Item& item);
	bool bIsRotten;
};
