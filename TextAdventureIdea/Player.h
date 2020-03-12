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

	void setPlayerName(string value) { sName = value; }
	string getPlayerName() { return sName; }

	void setPlayerHealth(int value) { iHealth = value; }
	int getPlayerHealth() { return iHealth; }

	void setTurnsCompleted(int value) { iTurnsCompleted = value; }
	int getTurnsCompleted() { return iTurnsCompleted; }

	void setCurrentLocationGridID(string value) { sCurrentGridID = value; }
	string getCurrentLocationGridID() { return sCurrentGridID; }

	void MoveEast();
	void MoveWest();
	void MoveNorth();
	void MoveSouth();
	void LookAround();

private:
	static Player *instance;

	string sCurrentGridID;
	string sName;
	int iHealth;
	int iTurnsCompleted;

	//TODO: add string vector for inventory items
};
