#include "DxLib.h"
#include "Player.h"
#include "../Main.h"
#include "../Function/Input.h"

Player::Player()
{
	//ステータス
	m_Hp = 10;
	m_Attack = 0;
	m_Speed = 4;
	m_Jump = 0;

	//Player座標
	m_PosX = 143;
	m_PosY = WindowHeight - MapChipHeight - 180;

	// 管理変数
	m_Player = 0;
	m_count = 0;
	m_ActSpeed = 20;
	m_ActIndex = 0;
	m_AttIndex = 0;
	m_MotionCooltime = 0;
	m_WaitIndex = 0;
	m_DeiIndex = 0;
	m_ActStop = m_ActSpeed;

	// 実行確認
	m_JumpExec = false;
	m_WalkExec = false;
	m_WaitExec = false;
	m_IsRight = false;

	InitTexture();
}

Player::~Player()
{
	ReleaseTexture();
}

void Player::Move()
{
	// 左移動
	if (GetKeyStatus(KEY_INPUT_A) == InputState::Hold && m_PosX >= -30)
	{
		m_IsRight = false;
		m_WaitExec = false;
		m_WalkExec = true;
		if (--m_ActStop <= 0)
		{
			m_Player = m_WlkMotionL[m_ActIndex];
			m_ActIndex++;
			m_ActStop = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
		m_PosX -= m_Speed;
			

		// ジャンプ
		if (GetKeyStatus(KEY_INPUT_W) == InputState::Pushed && m_PosY >= WindowHeight - MapChipHeight - 180)
		{
			m_JumpExec = true;
			m_Jump = -20;
		}
	}
	// 右移動
	else if (GetKeyStatus(KEY_INPUT_D) == InputState::Hold)
	{
		m_IsRight = true;
		m_WaitExec = false;
		m_WalkExec = true;
		if (--m_ActStop <= 0)
		{
			m_Player = m_WlkMotionR[m_ActIndex];
			m_ActIndex++;
			m_ActStop = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
		m_PosX += m_Speed;
		
		// ジャンプ
		if (GetKeyStatus(KEY_INPUT_W) == InputState::Pushed && m_PosY >= WindowHeight - MapChipHeight - 180)
		{
			m_JumpExec = true;
			m_Jump = -20;
		}
	}
	// ジャンプ
	else if (GetKeyStatus(KEY_INPUT_W) == InputState::Pushed && m_PosY >= WindowHeight - MapChipHeight - 180)
	{
		m_WaitExec = false;
		m_JumpExec = true;
		m_Jump = -20;
	}
	//攻撃
	else if (GetKeyStatus(KEY_INPUT_SPACE) == InputState::Hold && m_PosY >= WindowHeight - MapChipHeight - 180)
	{
		if (--m_ActStop <= 0)
		{
			if (m_IsRight == true)
			{
				m_Player = m_AttMotionR[m_AttIndex];
			}
			else
			{
				m_Player = m_AttMotionL[m_AttIndex];
			}
			m_AttIndex++;
			m_ActStop = m_ActSpeed;
			m_AttIndex %= m_AttMotionMax;
		}
	}
	else if (GetKeyStatus(KEY_INPUT_V) == InputState::Hold)
	{
		if (--m_ActStop <= 0)
		{
			if (m_IsRight == true)
			{
				m_Player = m_DeiMotionR[m_DeiIndex];
			}
			else
			{
				m_Player = m_DeiMotionL[m_DeiIndex];
			}
			m_DeiIndex++;
			m_ActStop = m_ActSpeed;
			m_DeiIndex %= m_DeiMotionMax;
		}
	}
	else
	{
		if (--m_ActStop <= 0)
		{
			m_WaitExec = true;
			if (m_IsRight == true)
			{
				m_Player = m_WaiMotionR[m_WaitIndex];
			}
			else
			{
				m_Player = m_WaiMotionL[m_WaitIndex];
			}
			m_WaitIndex++;
			m_ActStop = m_ActSpeed;
			m_WaitIndex %= m_MotionMax;
		}
	}

	if (m_JumpExec == true)
	{
		m_PosY += m_Jump;
		m_Jump += 1;
		if (m_PosY >= WindowHeight - MapChipHeight - 180)//重力加速
		{
			m_JumpExec = false;
			m_Jump = 0;
		}
	}
}

void Player::InitTexture()
{
	LoadDivGraph("Res/Character/Players.png", m_PlayerMax, 4, 8, 180, 180, m_Players);
}

void Player::Draw(Camera camera)
{
	int DrawPosX = camera.ConvertPosXWorldToScreen(m_PosX);
	int DrawPosY = camera.ConvertPosYWorldToScreen(m_PosY);

	DrawGraph(DrawPosX, DrawPosY, m_Players[m_Player], TRUE);
}

void Player::ReleaseTexture()
{
}

bool Player::CheckHit(int x, int y, int Width, int Height)
{
	if ((m_PosX > x && m_PosX < Width) ||
		(m_PosY > y && m_PosY < Height) ||
		(m_PosX + 120 > x && m_PosX + 120 < Width) ||
		(m_PosY + 180 > x && m_PosY + 180 < Height))
	{
		return true;
	}
	else
	{
		return false;
	}
}
