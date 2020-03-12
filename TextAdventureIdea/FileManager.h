#pragma once

class FileManager
{
public:
	~FileManager() {};
	FileManager() {};

	static FileManager *GetInstance()
	{
		if (!instance)
		{
			instance = new FileManager;
		}
		return instance;
	}

//PUBLIC METHODS=========================================//

	void PromptForSave();
	int PromptForLoad();

private:
	static FileManager *instance;

//PRIVATE METHODS========================================//

	int ReadFromFile(const char *pathToFile);
	void WriteToFile(const char *pathToFile);

};

