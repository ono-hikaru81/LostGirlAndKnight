#include "DxLib.h"
#include "Player.h"
#include"Main.h"

Player::Player()
{
	m_PlayerPosx = 100.0f;
	m_PlayerPosy= WindowHeight - 180.0f;
	m_HP = 1;
	m_Jump = -50;
	m_Jump_exec = false;
	m_Gravity = 0.0f;
}

Player::~Player()
{
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_A))//左移動
	{
		m_PlayerPosx -= 4;
		if (CheckHitKey(KEY_INPUT_W) && m_PlayerPosy >= WindowHeight - 180)//ジャンプ
		{
			m_Gravity = -5.0f;
			m_Jump_exec = true;
		}
	}

	if (CheckHitKey(KEY_INPUT_D))//右移動
	{
		m_PlayerPosx += 4;
		if (CheckHitKey(KEY_INPUT_W) && m_PlayerPosy >= WindowHeight - 180)//ジャンプ
		{
			m_Gravity = -5.0f;
			m_Jump_exec = true;
		}
	}

	if (CheckHitKey(KEY_INPUT_W) && m_PlayerPosy >= WindowHeight - 180)//ジャンプ
	{
		m_Gravity = -5.0f;
		m_Jump_exec = true;
	}
	if (m_Jump_exec == true)
	{
		m_PlayerPosy += m_Gravity;
		m_Gravity += 0.2f;
		if (m_PlayerPosy >= WindowHeight - 180)//重力加速
		{
			m_Jump_exec = false;
			m_Gravity += 0.0f;
		}
	}	
}

void Player::Draw()
{
	LoadGraphScreen(m_PlayerPosx, m_PlayerPosy, "Res/taiki_R.png", TRUE);
}

bool Player::CheckHit()
{
	return false;
}
