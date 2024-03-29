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

	bool getIsRotten() { return isRotten; }
	void setIsRotten(bool value) { isRotten = value; }
	int getRotsAfterTurn() { return rotsAfterTurn; }
	void setRotsAfterTurn(int turnNumber) { rotsAfterTurn = turnNumber; }

private:
	bool isRotten;
	int rotsAfterTurn;
};
