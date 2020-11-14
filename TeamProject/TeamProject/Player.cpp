#include "DxLib.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_A) == true)
	{
		P_Speed *= -1;
	}
}

void Player::Draw()
{
}

bool Player::CheckHit()
{
	return false;
}
