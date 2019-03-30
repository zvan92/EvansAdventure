#pragma once

class Game
{
public:
	Game() {};
	~Game() {};

	static Game *Instance()
	{
		if (!instance)
		{
			instance = new Game;
		}
		return instance;
	}
//FUNCTIONS========================================//

	bool getGameOverStatus() { return gameOverStatus; }
	void setGameOverStatus(bool value) { gameOverStatus = value; }

	int CreatePlayer();
	bool CollisionCheck(const char* direction);
	void ExecuteTurn();
	void SaveProgress();
	void DisplayMap();
	void Init();
	void MoveEast();
	void MoveWest();
	void MoveNorth();
	void MoveSouth();
	void PromptForDirection();
	void LookAround();

//=================================================//
private:
	static Game *instance;

	static bool gameOverStatus;
	int PromptUserChoice();
};

