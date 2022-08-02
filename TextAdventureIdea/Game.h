#pragma once

#include "MapManager.h"

#define SUCCESS 0
#define FAILED 1
#define MAX_INVENTORY_ITEMS 10
#define MAX_ROOM_ITEMS 10

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
	bool getGameIsInitializing() { return gameIsInitializing; }
	void setGameIsInitializing(bool value) { gameIsInitializing = value; }

	bool CheckForCollision(MapManager::Direction direction);
	int CreatePlayer();
	void DisplayCollectItemScreen();
	void DisplayMapScreen();
	void DisplayInventoryScreen();
	void DisplayEndGameScreen();
	void DisplayUseItemScreen(Item item);
	void Init();
	void PromptForDirection();
	void StartPlayerTurn();

private:
	static Game *instance;

	static bool gameOverStatus;
	static bool gameIsInitializing;

//PRIVATE METHODS========================================//

	int PromptForTurnAction();
	void ListPlayerItems();
	void ListRoomItems();
};

