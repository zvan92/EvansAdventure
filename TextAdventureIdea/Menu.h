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

	bool getQuitting() { return quitting; }
	void setQuitting(bool value) { quitting = value; }

	int Run();

//=================================================//
private:
	static Menu *instance;

	bool quitting;


};

