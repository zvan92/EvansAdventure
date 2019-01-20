#pragma once
class FileManager
{
public:
	~FileManager();
	static FileManager *Instance()
	{
		if (!instance)
		{
			instance = new FileManager;
			return instance;
		}
	}
//FUNCTIONS========================================//

	void PromptForSave();
	int PromptForLoad();

//=================================================//
private:
	FileManager();
	static FileManager *instance;

	int ReadFromFile(const char *pathToFile);
	void WriteToFile(const char *pathToFile);
};

