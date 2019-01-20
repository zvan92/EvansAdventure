#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{
private:
	Player();
	static Player *instance;
//VARIABLES========================================//

	string name;
	int health;
	int turnsCompleted;
	//string vector = inventory

//=================================================//
public:
	~Player();
	static Player *Instance()
	{
		if (!instance)
		{
			instance = new Player;
			return instance;
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

//=================================================//
};
