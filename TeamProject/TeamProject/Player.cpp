#include "DxLib.h"
#include "Player.h"
#include"InputKey.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Move()
{
	if (IsKeyHold(KEY_INPUT_A))
	{
		P_Posx *= -1;
	}
}

void Player::Draw()
{
}

bool Player::CheckHit()
{
	return false;
}
