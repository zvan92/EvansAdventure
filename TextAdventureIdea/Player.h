#pragma once

#include <string>

using namespace std;

class Player
{

public:
	Player() :
		sCurrentGridID(""),
		sName(""),
		iHealth(0),
		iTurnsCompleted(0) {};
	~Player() {};

	static Player *GetInstance()
	{
		if (!instance)
		{
			instance = new Player;
		}
		return instance;
	}

//PUBLIC METHODS=========================================//

	void setCurrentLocationGridID(string value) { sCurrentGridID = value; }
	string getCurrentLocationGridID() { return sCurrentGridID; }

	void setPlayerHealth(int value) { iHealth = value; }
	int getPlayerHealth() { return iHealth; }

	void setPlayerName(string value) { sName = value; }
	string getPlayerName() { return sName; }

	void setTurnsCompleted(int value) { iTurnsCompleted = value; }
	int getTurnsCompleted() { return iTurnsCompleted; }

	void LookAround();
	void MoveNorth();
	void MoveSouth();
	void MoveEast();
	void MoveWest();

private:
	static Player *instance;

	//The Grid ID is an X/Y coordinate; the X is represented by a letter and the Y is represented by a number (e.g. A5).
	string sCurrentGridID;
	string sName;
	int iHealth;
	int iTurnsCompleted;

	//TODO: add string vector for inventory items
};
