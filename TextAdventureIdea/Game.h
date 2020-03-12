#pragma once

#include "MapManager.h"

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

	int CreatePlayer();
	bool CheckForCollision(MapManager::Direction direction);
	void ExecuteTurn();
	void SaveProgress();
	void DisplayMap();
	void Initialize();
	void PromptForDirection();

private:
	static Game *instance;

	static bool gameOverStatus;

//PRIVATE METHODS========================================//

	int PromptForChoice();
};

