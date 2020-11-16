#include "DxLib.h"
#include "Player.h"
#include"Main.h"

Player::Player()
{
	P_Posx = 100.0f;
	P_Posy = 100.0f;
	HP = 1;
	Jump = -50;
	Jump_exec = false;
	Clone_Jump = Jump;
}

Player::~Player()
{
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_A))//���ړ�
	{
		P_Posx -= 4;
	}

	if (CheckHitKey(KEY_INPUT_D))//�E�ړ�
	{
		P_Posx += 4;
	}

	if (CheckHitKey(KEY_INPUT_W))//�W�����v
	{
		Jump_exec = true;
	}
	if (Jump_exec == true)
	{
		P_Posy += Clone_Jump;
		Jump += Gravity;
		Jump_exec = false;
	}

	
	if (P_Posy < WindowHeight - 180)//�d�͉���
	{
		P_Posy += Gravity;
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
