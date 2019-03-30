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
	cin >> filepath;

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
	system("cls");
	cout << "==========================================\n";
	cout << "==           EVAN'S ADVENTURE           ==\n";
	cout << "==========================================\n";
	cout << "             [ Save Progress ]\n\n";
	cout << "Save your progress, " << Player::Instance()->getPlayerName() << "? (Y/N) ";

	char choice;
	string input;
	getline(cin, input);
	stringstream stream(input);
	stream >> choice;

	if (input.length() == 0 || input.length() > 1 ||
		input.length() == 1 && choice != 'n' && choice != 'N' &&
		choice != 'y' && choice != 'Y')
	{
		system("cls");
		cout << "Invalid selection.\n\n";
		system("pause");
	}
	if (input.length() == 1 && choice == 'y' || input.length() == 1 && choice == 'Y')
	{
		system("cls");
		cout << "==========================================\n";
		cout << "==           EVAN'S ADVENTURE           ==\n";
		cout << "==========================================\n";
		cout << "             [ Save Progress ]\n\n";
		cout << "Enter character file save destination\n[ i.e. C:/Users/Evan/Documents/evan.txt ]\nor type 'esc' to cancel:\n\n";

		string filepath;
		getline(cin, filepath);

		if (filepath == "esc")
		{
			return;
		}

		const char *cPath = filepath.c_str();
		WriteToFile(cPath);

		system("cls");
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

	Player::Instance()->setPlayerName(name);
	Player::Instance()->setPlayerHealth(health);
	Player::Instance()->setTurnsCompleted(turnsCompleted);
	Player::Instance()->setCurrentGridID(gridID);

	fclose(fileptr);
	fileptr = NULL;
	delete fileptr;
	delete[] name;

	cout << "Character file: " << Player::Instance()->getPlayerName() << "\nloaded successfully.\n\n";
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

	int nameLength = Player::Instance()->getPlayerName().length() + 1;
	int currentGridIDLength = Player::Instance()->getCurrentGridID().length() + 1;
	int health = Player::Instance()->getPlayerHealth();
	int turnsCompleted = Player::Instance()->getTurnsCompleted();
	
	char* name_array = new char[Player::Instance()->getPlayerName().length() + 1];
	strcpy_s(name_array, Player::Instance()->getPlayerName().length() + 1, Player::Instance()->getPlayerName().c_str());

	char* gridID_array = new char[Player::Instance()->getCurrentGridID().length() + 1];
	strcpy_s(gridID_array, Player::Instance()->getCurrentGridID().length() + 1, Player::Instance()->getCurrentGridID().c_str());

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

	cout << "Character file: " << Player::Instance()->getPlayerName() << "\nSaved to location: " << pathToFile << "\n\n";
	system("pause");
}