#pragma once
class Menu
{
private:
	Menu();
	static Menu *instance;

	bool quitting;
public:
	~Menu();
	static Menu *Instance()
	{
		if (!instance)
		{
			instance = new Menu;
			return instance;
		}
	}
//FUNCTIONS========================================//

	int Run();
	bool getQuitting()
	{
		return quitting;
	}
	void setQuitting(bool value)
	{
		quitting = value;
	}

//=================================================//
};

