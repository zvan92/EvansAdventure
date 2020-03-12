#pragma once

class Menu
{
public:
	Menu() :
		bIsQuitting(false) {};
	~Menu() {};

	static Menu *GetInstance()
	{
		if (!instance)
		{
			instance = new Menu;
		}
		return instance;
	}

//PUBLIC METHODS=========================================//

	bool getIsQuitting() { return bIsQuitting; }
	void setIsQuitting(bool value) { bIsQuitting = value; }

	int Run();

private:
	static Menu *instance;

	bool bIsQuitting;
};

