#include "DxLib.h"
#include "Player.h"
#include"Main.h"

Player::Player()
{
	m_PlayerPosx = 100.0f;
	m_PlayerPosy= WindowHeight - 180.0f;
	m_HP = 1;
	m_Gravity = 0.0f;
	m_Jump_exec = false;
	m_stop_exec = true;
	m_walk_exec = false;
	m_attacl_exec = false;
}

Player::~Player()
{
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_A))//左移動
	{
		m_stop_exec = false;
		m_walk_exec = true;
		m_PlayerPosx -= 4;
		if (CheckHitKey(KEY_INPUT_W) && m_PlayerPosy >= WindowHeight - 180)//ジャンプ
		{
			m_Gravity = -5.0f;
			m_Jump_exec = true;
		}
	}
	else
	{
		m_stop_exec = true;
		m_walk_exec = false;
	}

	if (CheckHitKey(KEY_INPUT_D))//右移動
	{
		m_stop_exec = false;
		m_walk_exec = true;
		m_PlayerPosx += 4;
		if (CheckHitKey(KEY_INPUT_W) && m_PlayerPosy >= WindowHeight - 180)//ジャンプ
		{
			m_Gravity = -5.0f;
			m_Jump_exec = true;
		}
	}

	else if (CheckHitKey(KEY_INPUT_W) && m_PlayerPosy >= WindowHeight - 180)//ジャンプ
	{
		m_stop_exec = false;
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
	else if (CheckHitKey(KEY_INPUT_SPACE) && m_PlayerPosy >= WindowHeight - 180)
	{
		m_stop_exec = false;
		m_attacl_exec = true;
	}
}

void Player::Draw()
{
	m_stop = LoadGraph( "Res/taiki_R.png");
	m_walk = LoadGraph("Res/walk_R2r.png");
	m_attack = LoadGraph("Res/attack_R2.png");
	m_Jump = LoadGraph("Res/junp_R.png");

	if (m_stop_exec == true)
	{
		DrawGraph(m_PlayerPosx, m_PlayerPosy, m_stop, TRUE);
	}
	else if (m_walk_exec == true)
	{
		DrawGraph(m_PlayerPosx, m_PlayerPosy, m_walk, TRUE);
	}
	else if (m_attacl_exec == true)
	{
		DrawGraph(m_PlayerPosx, m_PlayerPosy, m_attack, TRUE);
	}
	else if (m_Jump_exec == true)
	{
		DrawGraph(m_PlayerPosx, m_PlayerPosy, m_Jump, TRUE);
	}
}

bool Player::CheckHit()
{
	return false;
}
