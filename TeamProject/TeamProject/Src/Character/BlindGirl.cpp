#include "DxLib.h"
#include "BlindGirl.h"
#include "../Main.h"
#include "../Character/Player.h"
#include"../Function/Input.h"

static Player player;

Girl::Girl()
{
	// ステータス
	m_Hp = 2;
	m_Speed = 20;
	m_Jump = 0;

	//位置座標 
	m_PosX = 120;
	m_PosY = 1060;

	// 管理変数
	m_Girl = 0;
	m_ActSpeed = 20;
	m_WaitIndex = 0;
	m_WlkIndex = 0;
	m_DedIndex = 0;
	m_ActStop = m_ActSpeed;

	// 実行確認
	m_StopExec = true;
	m_WalkExec = false;
	m_JumpExec = false;

	m_CurrentAction = ActionType::Wait;
}

Girl::~Girl()
{
}

void Girl::InitTexture()
{
	LoadDivGraph("Res/Character/Girls.png", m_GirlMax,5,5,180,180,m_Girls);
}

void Girl::Move(Player player)
{
	if (GetKeyStatus(KEY_INPUT_S) == InputState::Pushed)
	{
		if (m_CurrentAction == ActionType::Move)
		{
			m_CurrentAction = ActionType::Wait;
		}
		else if (m_CurrentAction == ActionType::Wait)
		{
			m_CurrentAction = ActionType::Move;
		}
	}

	if (player.m_IsFloatingAir == true)
	{
		m_Jump = -20;
		m_PosY += m_Jump;
		m_Jump += 1;
		if (player.m_IsRight == true)
		{
			m_Girl = 7;	
		}
		else
		{
			m_Girl = 18;
		}
		if (m_PosY >= WindowHeight - MapChipHeight - 180)//重力加速
		{
			m_Jump = 0;
		}	
	}

	if (m_CurrentAction == ActionType::Wait)
	{
		if (--m_ActStop <= 0)
		{
			if (player.m_IsRight == true)
			{
				m_Girl = m_WatMotionR[m_WaitIndex];
			}
			else
			{
				m_Girl = m_WatMotionL[m_WaitIndex];
			}
			m_WaitIndex++;
			m_ActStop = m_ActSpeed;
			m_WaitIndex %= m_MotionMax;
		}
	}
	else if (m_CurrentAction == ActionType::Move)
	{
		if (--m_ActStop <= 0)
		{
			if (player.m_PosX >= m_PosX)
			{
				m_Girl = m_WlkMotionR[m_WlkIndex];
				m_PosX += m_Speed;
			}
			if(player.m_PosX <= m_PosX)
			{
				m_Girl = m_WlkMotionL[m_WlkIndex];
				m_PosX -= m_Speed;
			}
			m_WlkIndex++;
			m_ActStop = m_ActSpeed;
			m_WlkIndex %= m_MotionMax;
		}
	}




	//else if ()//DedMotion
	//{
	//	if (player.m_IsRight == true)
	//	{
	//		m_DedMotionR[m_DedIndex];
	//	}
	//	else
	//	{
	//		m_DedMotionL[m_DedIndex];
	//	}
	//	m_DedIndex++;
	//	m_ActStop = m_ActSpeed;
	//	m_DedIndex %= m_DedMotionMax;
	//}
	
	
}

void Girl::Draw(Player player, Camera camera)
{
	int DrawPosX = camera.ConvertPosXWorldToScreen(m_PosX - 63);
	int DrawPosY = camera.ConvertPosYWorldToScreen(m_PosY);

	DrawGraph(DrawPosX, DrawPosY, m_Girls[m_Girl], TRUE);
}

void Girl::ReleaseTexture()
{
}
