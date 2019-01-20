#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include "FileManager.h"
#include <iostream>
#include <string>
using namespace std;

Game *Game::instance = 0;
bool Game::gameOverStatus = false;

Game::Game()
{
}
Game::~Game()
{
}

void Game::ExecuteTurn() 
{
	system("cls");

	int choice = 0;

	while (choice == 0)
	{
		choice = PromptUserChoice();
	}

	switch (choice)
	{
	case 1:
		system("cls");
		cout << "(" << Player::Instance()->getPlayerName() << " moves)\n\n";
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() +1);
		system("PAUSE");
		break;
	case 2:
		system("cls");
		cout << "(" << Player::Instance()->getPlayerName() << " looks around)\n\n";
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() + 1);
		system("PAUSE");
		break;
	case 3:
		system("cls");
		cout << "(" << Player::Instance()->getPlayerName() << " uses an item)\n\n";
		Player::Instance()->setTurnsCompleted(Player::Instance()->getTurnsCompleted() + 1);
		system("PAUSE");
		break;
	case 4:
		SaveProgress();
		break;
	case 5:
		system("cls");
		cout << "Game over after " << Player::Instance()->getTurnsCompleted() << " turns!\n\nReturning to menu...\n\n";
		system("pause");

		Player::Instance()->setPlayerName("");
		Player::Instance()->setPlayerHealth(0);

		gameOverStatus = true;
	}
}

int Game::PromptUserChoice()
{
	system("cls");

	int choice;

	cout << "Turns completed: " << Player::Instance()->getTurnsCompleted() << "\n\n";
	cout << Player::Instance()->getPlayerName() << ", what would you like to do?\n\n(1) Move\n(2) Look Around\n(3) Use Item\n(4) Save Progress\n(5) End Game\n\nEnter Choice: ";
	cin >> choice;

	if (choice == 1 ||
		choice == 2 ||
		choice == 3 ||
		choice == 4 ||
		choice == 5)
	{
		return choice;
	}
	else
	{
		return 0;
	}
}

int Game::CreatePlayer()
{
	system("cls");

	string name;
	char choice;
	bool confirmed = false;

	while (!confirmed)
	{
		cout << "========================================\n";
		cout << "==          EVAN'S ADVENTURE          ==\n";
		cout << "========================================\n\n";
		cout << "[Player Creation]\n\n";
		cout << "Enter player name (or type 'esc' to cancel): ";
		cin >> name;
		if (name == "esc")
		{
			return 1;
		}

		cout << "\nAre you sure? (Y/N): ";
		cin >> choice;
		if (choice == 'y')
		{
			confirmed = true;
		}
	}
	
	Player::Instance()->setPlayerName(name);
	Player::Instance()->setPlayerHealth(100);
	Player::Instance()->setTurnsCompleted(0);

	return 0;
}

void Game::SaveProgress()
{
	FileManager::Instance()->PromptForSave();
}