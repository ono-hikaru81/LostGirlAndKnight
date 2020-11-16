#include "DxLib.h"
#include "Player.h"
#include"Main.h"


Player::Player()
{
	P_Posx = 100;
	P_Posy = 100;
	HP = 1;
	Gravity = 0.98f;
}

Player::~Player()
{
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_A))//左移動
	{
		P_Posx -= 4;
	}

	if (CheckHitKey(KEY_INPUT_D))//右移動
	{
		P_Posx += 4;
	}

	if (CheckHitKey(KEY_INPUT_W))//ジャンプ
	{
		//ジャンプの物理演算 
	}
	if (P_Posy < WindowHeight - 180)//重力加速
	{
		P_Posy /= Gravity;
	}
}

void Player::Draw()
{
	LoadGraphScreen(P_Posx, P_Posy, "Res/taiki_R.png", TRUE);
}

bool Player::CheckHit()
{
	return false;
}
