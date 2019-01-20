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

FileManager::FileManager()
{
}
FileManager::~FileManager()
{
}

int FileManager::PromptForLoad()
{
	system("cls");

	string filepath;
	cout << "Specify a file location (i.e. C:/Users/Evan/Documents/evan.txt)\nor type 'esc' to cancel: ";
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

	char choice;
	system("cls");
	cout << "Do you wish to save your progress, " << Player::Instance()->getPlayerName() << "? (Y/N) ";
	cin >> choice;
	system("cls");

	if (choice == 'y')
	{
		string filepath;
		cout << "Specify a save destination (i.e. C:/Users/Evan/Documents/evan.txt): ";
		cin >> filepath;
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

	cout << Player::Instance()->getPlayerName() << " loaded successfully.\n";
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

	cout << "Progress saved successfully.\n\n";
	system("pause");
}