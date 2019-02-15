#pragma once
class Game
{
public:
	Game() {};
	~Game() {};

	static Game *Instance() //returns static Game ptr
	{
		if (!instance)
		{
			instance = new Game; //initialize the ptr with the location of Game instance
		}
		return instance; //Game instance destroys after return
	}
//FUNCTIONS========================================//

	bool getGameOverStatus()
	{
		return gameOverStatus;
	}
	void setGameOverStatus(bool value)
	{
		gameOverStatus = value;
	}
	void ExecuteTurn();
	int CreatePlayer();
	void SaveProgress();
	void DisplayMap();
	void Init();

//=================================================//
private:
	static Game *instance;

	static bool gameOverStatus;
	int PromptUserChoice();
};

