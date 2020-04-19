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

	int PromptForLoad();
	void PromptForSave();

private:
	static FileManager *instance;

//PRIVATE METHODS========================================//

	int ReadFromFile(const char *pathToFile);
	void WriteToFile(const char *pathToFile);

};

