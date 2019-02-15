#pragma once
class Menu
{
public:
	Menu() {};
	~Menu() {};

	static Menu *Instance()
	{
		if (!instance)
		{
			instance = new Menu;
		}
		return instance;
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
private:
	static Menu *instance;

	bool quitting;


};

