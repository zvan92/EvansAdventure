#pragma once

#include "Item.h"

class Chest : public Item
{
public:
	Chest() :
		isBlue(false),
		isGreen(false),
		isRed(false),
		isYellow(false)
		//contents
	{
		isChest = true;
	};
	~Chest() {};

	Chest(const Item& item) :
		Item(item),
		isBlue(false),
		isGreen(false),
		isRed(false),
		isYellow(false)
		//contents
	{
		isChest = true;
	};

	bool getIsBlue() { return isBlue; }
	void setIsBlue(bool value) { isBlue = value; }
	bool getIsGreen() { return isGreen; }
	void setIsGreen(bool value) { isGreen = value; }
	bool getIsRed() { return isRed; }
	void setIsRed(bool value) { isRed = value; }
	bool getIsYellow () { return isYellow; }
	void setIsYellow(bool value) { isYellow = value; }
	//contents
	// Can't instantiate Item objects - will be replaced with Key eventually
	int CombineWithItem(Item* item);

private:
	bool isBlue;
	bool isGreen;
	bool isRed;
	bool isYellow;
	//contents
};