#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{

public:
	Player() {};
	~Player() {};
	static Player *Instance()
	{
		if (!instance)
		{
			instance = new Player;
		}
		return instance;
	}
//FUNCTIONS========================================//

	void setPlayerName(string value)
	{
		name = value;
	}
	string getPlayerName()
	{
		return name;
	}
	void setPlayerHealth(int value)
	{
		health = value;
	}
	int getPlayerHealth()
	{
		return health;
	}
	void setTurnsCompleted(int value)
	{
		turnsCompleted = value;
	}
	int getTurnsCompleted()
	{
		return turnsCompleted;
	}
	void setCurrentGridID(string value)
	{
		currentGridID = value;
	}
	string getCurrentGridID()
	{
		return currentGridID;
	}

	void LookAround();
	void MoveEast();


//=================================================//
private:
	static Player *instance;
//VARIABLES========================================//

	string currentGridID;
	string name;
	int health;
	int turnsCompleted;
	//string vector = inventory

//=================================================//
};
