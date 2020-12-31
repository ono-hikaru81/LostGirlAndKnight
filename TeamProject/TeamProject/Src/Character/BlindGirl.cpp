#include "DxLib.h"
#include "BlindGirl.h"
#include "../Main.h"
#include "../Character/Player.h"
#include"../Function/Input.h"

Player player;

Girl::Girl()
{
	// ステータス
	m_Hp = 2;
	m_Speed = 10;
	m_Jump = 0;

	//位置座標 
	m_PosX = player.m_PosX - 63;
	m_PosY = player.m_PosY;

	// 管理変数
	m_Girl = 0;
	m_count = 0;
	m_ActSpeed = 20;
	m_WaitIndex = 0;
	m_WlkIndex = 0;
	m_DedIndex = 0;
	m_ActStop = m_ActSpeed;

	// 実行確認
	m_StopExec = true;
	m_WalkExec = false;
	m_JumpExec = false;

	// 画像保存
	
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
	if (player.m_WaitExec == true)
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
	else if (player.m_WalkExec == true)
	{
		if (--m_ActStop <= 0)
		{
			if (player.m_IsRight == true)
			{
				m_Girl = m_WlkMotionR[m_WlkIndex];
				m_PosX += m_Speed;
			}
			else
			{
				m_Girl = m_WlkMotionL[m_WlkIndex];
				m_PosX -= m_Speed;
			}
			m_WlkIndex++;
			m_ActStop = m_ActSpeed;
			m_WlkIndex %= m_MotionMax;
		}
	}
	else if (player.m_JumpExec == true)
	{
		if (player.m_IsRight == true)
		{
			m_Girl = 7;
			m_Jump = -20;
		}
		else
		{
			m_Girl = 18;
			m_Jump = -20;
		}
		m_PosY += m_Jump;
		m_Jump += 1;
		if (m_PosY >= WindowHeight - MapChipHeight - 180)//重力加速
		{
			m_Jump = 0;
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

void Girl::Draw(Player player)
{
	DrawGraph(player.m_PosX - 63, player.m_PosY, m_Girls[m_Girl], TRUE);
}

void Girl::ReleaseTexture()
{
}
