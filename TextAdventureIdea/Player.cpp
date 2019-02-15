#include "pch.h"
#include "Player.h"
#include "MapManager.h"

Player *Player::instance = 0;

void Player::LookAround()
{
	MapManager::Instance()->DescribeRoom(getCurrentRoomId());
}


