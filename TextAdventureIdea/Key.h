#pragma once

#include "Item.h"

class Room;

class Key : public Item
{
public:
	Key() :
		isBlue(false),
		isGreen(false),
		isRed(false),
		isYellow(false),
		isBrass(false)
	{
		isKey = true;
	};
	~Key() {};

	bool getIsBlue() { return isBlue; }
	void setIsBlue(bool value) { isBlue = value; }
	bool getIsGreen() { return isGreen; }
	void setIsGreen(bool value) { isGreen = value; }
	bool getIsRed() { return isRed; }
	void setIsRed(bool value) { isRed = value; }
	bool getIsYellow() { return isYellow; }
	void setIsYellow(bool value) { isYellow = value; }
	bool getIsBrass() { return isBrass; }
	void setIsBrass(bool value) { isBrass = value; }

	int CombineWithItem(Chest* chest);
	int CombineWithItem(Food* food);
	int CombineWithItem(Potion* potion);
	int CombineWithItem(Key* key);
	int CombineWithItem(Room* room);

private:
	bool isBlue;
	bool isGreen;
	bool isRed;
	bool isYellow;
	bool isBrass;
};