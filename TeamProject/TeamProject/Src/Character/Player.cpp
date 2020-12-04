#include "DxLib.h"
#include "Player.h"
#include"../Main.h"

Player::Player()
{
	//ステータス
	m_Hp     = 10;
	m_Attack = 0;
	m_Speed  = 4;
	m_Jump   = 0;

	//Player座標
	m_PosX = 143;
	m_PosY = WindowHeight - MapChipHeight - 180;

	// 管理変数
	m_RightMotionMAX = 4;
	m_count = 0;
	m_MotionCooltime = 0;

	// 実行確認
	m_StopExec	  = true;
	m_JumpExec	  = false;
	m_WalkExec	  = false;
	m_AttackExec  = false;
	m_Instraction = false;

	// 画像保存
	m_StopGraph	  = NULL;
	m_WalkGraph   = NULL;
	m_JumpGraph   = NULL;
	m_AttackGraph = NULL;
	m_RightMotion[m_RightMotionMAX];
}

Player::~Player()
{
}

void Player::Move()
{
	// 左移動
	if (CheckHitKey(KEY_INPUT_A) && m_PosX >= -30)
	{
		m_StopExec = false;
		m_WalkExec = true;
		m_PosX -= m_Speed;
		// ジャンプ
		if (CheckHitKey(KEY_INPUT_W) && m_PosY >= WindowHeight - MapChipHeight - 180)
		{
			m_JumpExec = true;
			m_Jump = -20;
		}
	}
	// 右移動
	else if (CheckHitKey(KEY_INPUT_D) && m_PosX <= 1900)
	{
		m_StopExec = false;
		m_WalkExec = true;
		m_PosX += m_Speed;
		// ジャンプ
		if (CheckHitKey(KEY_INPUT_W) && m_PosY >= WindowHeight - MapChipHeight - 180)
		{
			m_JumpExec = true;
			m_Jump = -20;
		}
	}
	// ジャンプ
	else if (CheckHitKey(KEY_INPUT_W) && m_PosY >= WindowHeight - MapChipHeight - 180)
	{
		m_StopExec = false;
		m_JumpExec = true;
		m_Jump = -20;
	}
	else if (CheckHitKey(KEY_INPUT_SPACE) && m_PosY >= WindowHeight - MapChipHeight - 180)
	{
		m_StopExec = false;
		m_AttackExec = true;
	}
	else
	{
		m_StopExec = true;
		m_WalkExec = false;
	}

	if (m_JumpExec == true)
	{
		m_PosY += m_Jump;
		m_Jump += 1;
		m_StopExec = false;
		if (m_PosY >= WindowHeight - MapChipHeight - 180)//重力加速
		{
			m_StopExec = true;
			m_JumpExec = false;
			m_Jump = 0;
		}
	}
}

void Player::Draw()
{
	m_StopGraph		 = LoadGraph( "Res/Character/taiki_R.png");
	m_WalkGraph		 = LoadGraph("Res/Character/taiki_R.png");
	m_AttackGraph	 = LoadGraph("Res/Character/taiki_R.png");
	m_JumpGraph		 = LoadGraph("Res/Character/taiki_R.png");
	m_RightMotion[0] = LoadGraph("Res/Character/Rough/walk_R.png");
	m_RightMotion[1] = LoadGraph("Res/Character/Rough/walk_R2.png");
	m_RightMotion[2] = LoadGraph("Res/Character/Rough/walk_R2r.png");
	m_RightMotion[3] = LoadGraph("Res/Character/Rough/walk_Rl.png");

	if (m_StopExec == true)
	{
		DrawGraph(m_PosX, m_PosY, m_StopGraph, TRUE);
	}
	else if (m_WalkExec == true)
	{
		if (m_count == 2)
		{
			m_count = 0;
		}
		DrawGraph(m_PosX, m_PosY, m_RightMotion[m_count], TRUE);
		m_MotionCooltime++;
		if (m_MotionCooltime == 15)
		{
			m_count++;
			m_MotionCooltime = 0;
			
		}
	}
	else if (m_AttackExec == true)
	{
		DrawGraph(m_PosX, m_PosY, m_AttackGraph, TRUE);
	}
	else if (m_JumpExec == true)
	{
		DrawGraph(m_PosX, m_PosY, m_JumpGraph, TRUE);
	}
}

bool Player::CheckHit(int x, int y, int Width, int Height)
{
	if ((m_PosX > x && m_PosX < Width) ||
		(m_PosY > y && m_PosY < Height)||
		(m_PosX+120 > x && m_PosX +120 < Width)||
		(m_PosY+ 180 > x && m_PosY + 180 <Height))
	{
		return true;
	}
	else
	{
		return false;
	}
}
