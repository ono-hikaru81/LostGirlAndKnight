#include "DxLib.h"
#include "Player.h"
#include"InputKey.h"



Player::Player()
{
	P_Posx = 100;
	P_Posy = 100;
	HP = 1;
}

Player::~Player()
{
}

void Player::Move()
{
	if (IsKeyHold(KEY_INPUT_A))//左移動
	{
		P_Posx += -1;
	}

	if (IsKeyHold(KEY_INPUT_D))//右移動
	{
		P_Posx += 1;
	}

	if (IsKeyHold(KEY_INPUT_W))//ジャンプ
	{
		//ジャンプの物理演算 
	}
}

void Player::Draw()
{
	LoadGraphScreen(P_Posx, 100, "Res/taiki_R.png", TRUE);
}

bool Player::CheckHit()
{
	return false;
}
