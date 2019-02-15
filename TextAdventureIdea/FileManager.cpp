#include "pch.h"
#include "FileManager.h"
#include "Player.h"
#include "Game.h"
#include <string>
#include <iostream>
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
	string filepath;
	cout << "Enter file location (without spaces)\n[ i.e. C:/Users/Evan/Documents/evan.txt ]\nor type 'esc' to cancel:\n\n";
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
	char choice;
	cout << "Save your progress, " << Player::Instance()->getPlayerName() << "? (Y/N) ";
	cin >> choice;
	cout << "\n";

	if (choice == 'y')
	{
		string filepath;
		cout << "Enter save destination (without spaces)\n[ i.e. C:/Users/Evan/Documents/evan.txt ]\nor type 'esc' to cancel:\n\n";
		cin >> filepath;
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
	int health = 0;
	int turnsCompleted = 0;

	fread(&nameLength, sizeof(int), 1, fileptr);
	char* name = new char[nameLength];
	fread(name, sizeof(char), nameLength, fileptr);
	fread(&health, sizeof(int), 1, fileptr);
	fread(&turnsCompleted, sizeof(int), 1, fileptr);

	Player::Instance()->setPlayerName(name);
	Player::Instance()->setPlayerHealth(health);
	Player::Instance()->setTurnsCompleted(turnsCompleted);

	fclose(fileptr);
	fileptr = NULL;
	delete fileptr;
	delete[] name;

	cout << "File: " << Player::Instance()->getPlayerName() << "\nloaded successfully.\n\n";
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
	int health = Player::Instance()->getPlayerHealth();
	int turnsCompleted = Player::Instance()->getTurnsCompleted();
	char* char_array = new char[Player::Instance()->getPlayerName().length() + 1];
	strcpy_s(char_array, Player::Instance()->getPlayerName().length() + 1, Player::Instance()->getPlayerName().c_str());

	fwrite(&nameLength, sizeof(int), 1, fileptr);
	fwrite(char_array, sizeof(char), nameLength, fileptr);
	fwrite(&health, sizeof(int), 1, fileptr);
	fwrite(&turnsCompleted, sizeof(int), 1, fileptr);

	fclose(fileptr);
	fileptr = NULL;
	delete fileptr;
	delete[] char_array;

	cout << "File: " << Player::Instance()->getPlayerName() << "\nsaved successfully.\n\n";
	system("pause");
}