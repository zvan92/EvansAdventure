#pragma once

#include "MapManager.h"

#define SUCCESS 0
#define FAILED 1
#define MAX_INVENTORY_ITEMS 10
#define MAX_ROOM_ITEMS 10
#define MAX_CHEST_ITEMS 1

class GameManager
{
public:
	GameManager() {};
	~GameManager() {};

	static GameManager *GetInstance()
	{
		if (!instance)
		{
			instance = new GameManager;
		}
		return instance;
	}

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
	void DisplayUseItemScreen(Key* key);
	void DisplayChestScreen(Chest* chest);
	void Init();
	void PromptForDirection();
	void StartPlayerTurn();

private:
	static GameManager *instance;
	static bool gameOverStatus;
	static bool gameIsInitializing;

	int PromptForTurnAction();
	void ListPlayerItems();
	void ListRoomItems();
	void ListChestItems(Chest* chest);
};

