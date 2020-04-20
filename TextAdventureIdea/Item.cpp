#include "pch.h"
#include "Item.h"
#include "Player.h"

void Item::HealPlayer()
{
	Player::GetInstance()->setPlayerHealth(Player::GetInstance()->getPlayerHealth() + healFactor);
}

void Item::DamagePlayer()
{
	Player::GetInstance()->setPlayerHealth(Player::GetInstance()->getPlayerHealth() - damageFactor);
}