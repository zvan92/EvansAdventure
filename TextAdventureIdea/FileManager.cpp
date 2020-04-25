#include "pch.h"
#include "FileManager.h"
#include "Player.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <sstream>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

FileManager *FileManager::instance = 0;

int FileManager::PromptForLoad()
{
	system("cls");
	cout << "==========================================\n";
	cout << "==           EVAN'S ADVENTURE           ==\n";
	cout << "==========================================\n";
	cout << "              [ Load Game ]\n\n";
	cout << "Enter character file location\n[ i.e. C:/Users/Evan/Documents/evan.txt ]\nor type 'esc' to cancel:\n\n";

	string filepath;
	getline(cin, filepath);

	if (filepath == "esc")
	{
		return 1;
	}

	const char *cPath = filepath.c_str();

	if (ReadFromFile(cPath) == 1)
	{
		return 1;
	}

	system("cls");

	return 0;
}

void FileManager::PromptForSave()
{
	bool confirmed = false;

	while (!confirmed)
	{
		system("cls");
		cout << "==========================================\n";
		cout << "==           EVAN'S ADVENTURE           ==\n";
		cout << "==========================================\n";
		cout << "             [ Save Progress ]\n\n";
		cout << "Save your progress, " << Player::GetInstance()->getPlayerName() << "? (Y/N) ";

		char choice;
		string input;
		getline(cin, input);
		stringstream stream(input);
		stream >> choice;

		if (input.length() == 1 && (choice == 'y' || choice == 'Y'))
		{
			system("cls");
			cout << "==========================================\n";
			cout << "==           EVAN'S ADVENTURE           ==\n";
			cout << "==========================================\n";
			cout << "             [ Save Progress ]\n\n";
			cout << "Enter character file save destination\n[ i.e. C:/Users/Evan/Documents/evan.txt ]\nor type 'esc' to cancel:\n\n";

			string filepath;
			getline(cin, filepath);

			if (filepath != "esc")
			{
				const char* cPath = filepath.c_str();
				WriteToFile(cPath);

				system("cls");

				confirmed = true;
			}
		}
		else if (input.length() == 1 && (choice == 'n' || choice == 'N'))
		{
			confirmed = true;
		}
		else
		{
			continue;
		}
	}
}

int FileManager::ReadFromFile(const char *pathToFile)
{
	system("cls");

	FILE *fileptr;
	fopen_s(&fileptr, pathToFile, "rb");

	if (fileptr == NULL)
	{
		cout << "ERROR: File not found.\n\n";
		system("pause");
		return 1;
	}

	int nameLength = 0;
	int currentGridIDLength = 0;
	int health = 0;
	int turnsCompleted = 0;

	fread(&nameLength, sizeof(int), 1, fileptr);
	char* name = new char[nameLength];
	fread(name, sizeof(char), nameLength, fileptr);

	fread(&currentGridIDLength, sizeof(int), 1, fileptr);
	char* gridID = new char[currentGridIDLength];
	fread(gridID, sizeof(char), currentGridIDLength, fileptr);
	
	fread(&health, sizeof(int), 1, fileptr);
	fread(&turnsCompleted, sizeof(int), 1, fileptr);

	Player::GetInstance()->setPlayerName(name);
	Player::GetInstance()->setPlayerEnergy(health);
	Player::GetInstance()->setTurnsCompleted(turnsCompleted);
	Player::GetInstance()->setCurrentLocationGridID(gridID);

	fclose(fileptr);
	fileptr = NULL;
	delete fileptr;
	delete[] name;

	cout << "Character file: " << Player::GetInstance()->getPlayerName() << "\nloaded successfully.\n\n";
	system("pause");

	return 0;
}

void FileManager::WriteToFile(const char *pathToFile)
{
	system("cls");

	FILE *fileptr;
	fopen_s(&fileptr, pathToFile, "wb");

	if (fileptr == NULL)
	{
		cout << "ERROR: Invalid path.\n\n";
		system("pause");
		return;
	}

	int nameLength = static_cast<int>(Player::GetInstance()->getPlayerName().length() + 1);
	int currentGridIDLength = static_cast<int>(Player::GetInstance()->getCurrentLocationGridID().length() + 1);
	int health = Player::GetInstance()->getPlayerEnergy();
	int turnsCompleted = Player::GetInstance()->getTurnsCompleted();
	
	char* name_array = new char[Player::GetInstance()->getPlayerName().length() + 1];
	strcpy_s(name_array, Player::GetInstance()->getPlayerName().length() + 1, Player::GetInstance()->getPlayerName().c_str());

	char* gridID_array = new char[Player::GetInstance()->getCurrentLocationGridID().length() + 1];
	strcpy_s(gridID_array, Player::GetInstance()->getCurrentLocationGridID().length() + 1, Player::GetInstance()->getCurrentLocationGridID().c_str());

	fwrite(&nameLength, sizeof(int), 1, fileptr);
	fwrite(name_array, sizeof(char), nameLength, fileptr);
	fwrite(&currentGridIDLength, sizeof(int), 1, fileptr);
	fwrite(gridID_array, sizeof(char), currentGridIDLength, fileptr);
	fwrite(&health, sizeof(int), 1, fileptr);
	fwrite(&turnsCompleted, sizeof(int), 1, fileptr);

	fclose(fileptr);
	fileptr = NULL;
	delete fileptr;
	delete[] name_array;
	delete[] gridID_array;

	cout << "Character file: " << Player::GetInstance()->getPlayerName() << "\nSaved to location: " << pathToFile << "\n\n";
	system("pause");
}