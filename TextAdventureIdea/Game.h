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

	bool CheckForCollision(MapManager::Direction direction);
	int CreatePlayer();
	//TODO: DisplayCollectItemScreen
	void DisplayMapScreen();
	void DisplayInventoryScreen();
	void DisplayEndGameScreen();
	void Init();
	void PromptForDirection();
	void SaveProgress();
	void StartPlayerTurn();

private:
	static Game *instance;

	static bool gameOverStatus;

//PRIVATE METHODS========================================//

	int PromptForTurnAction();
	void ListPlayerItems();
	//TODO: listRoomItems
};

