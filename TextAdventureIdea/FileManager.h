#pragma once

class FileManager
{
public:
	~FileManager() {};
	FileManager() {};

	static FileManager *Instance()
	{
		if (!instance)
		{
			instance = new FileManager;
		}
		return instance;
	}
//FUNCTIONS========================================//

	void PromptForSave();
	int PromptForLoad();

//=================================================//
private:
	static FileManager *instance;

	int ReadFromFile(const char *pathToFile);
	void WriteToFile(const char *pathToFile);
};

