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
	if (IsKeyHold(KEY_INPUT_A))//���ړ�
	{
		P_Posx += -1;
	}

	if (IsKeyHold(KEY_INPUT_D))//�E�ړ�
	{
		P_Posx += 1;
	}

	if (IsKeyHold(KEY_INPUT_W))//�W�����v
	{
		//�W�����v�̕������Z 
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
