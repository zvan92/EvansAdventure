#pragma once

#include "MapManager.h"
#include "Food.h"

class Game
{
public:
	Game() {};
	~Game() {};

	static Game *GetInstance()
	{
		if (!instance)
		{
			instance = new Game;
		}
		return instance;
	}

//PUBLIC METHODS=========================================//

	bool getGameOverStatus() { return gameOverStatus; }
	void setGameOverStatus(bool value) { gameOverStatus = value; }

	bool CheckForCollision(MapManager::Direction direction);
	int CreatePlayer();
	void DisplayMapScreen();
	void DisplayInventoryScreen();
	void DisplayEndGameScreen();
	void Init();
	void PromptForDirection();
	void SaveProgress();
	void StartPlayerTurn();
	
	Food UnpackItem(Item& item);

private:
	static Game *instance;

	static bool gameOverStatus;

//PRIVATE METHODS========================================//

	int PromptForTurnAction();
	void ListPlayerItems();
};

