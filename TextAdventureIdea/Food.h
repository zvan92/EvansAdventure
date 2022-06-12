#pragma once

#include "Item.h"

class Food : public Item
{
public:
	Food() : 
		isRotten(false),
		rotsAfterTurn(NULL)
	{ 
		isFood = true;
	};
	~Food() {};

	Food(const Item& item) :
		Item(item),
		isRotten(false),
		rotsAfterTurn(NULL)
	{
		isFood = true;
	};

	bool getIsRotten() { return isRotten; }
	void setIsRotten(bool value) { isRotten = value; }

	int getRotsAfterTurn() { return rotsAfterTurn; }
	void setRotsAfterTurn(int turnNumber) { rotsAfterTurn = turnNumber; }

private:
	void CombineWithItem(Item& item);
	bool isRotten;
	int rotsAfterTurn;
};
