#include"Orc.h"
#include"DxLib.h"
#include"../Character/Player.h"
#include"../Main.h"

//static Player player;

Orc::Orc()
{
	m_Orc = 0;
	m_PosX = 500;
	m_PosY = WindowHeight - MapChipHeight - 210;
	m_MoveTime = 0;
	m_ActIndex = 0;
	m_ActSpeed = 10;
	m_AttIndex = 0;
	
}

Orc::~Orc()
{
	//loadGraph‚Ì‰ğ•ú
	/*for (int  i = 0; i < m_OrcMax; i++)
	{
		DeleteGraph(m_Orcs[i]);
	}*/
}

void Orc::Exec(Player player)
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_PosX++;
		if (--m_ActWait <= 0)
		{
			m_Orc = m_ActMotionR[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Orc = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_PosX--;
		if (--m_ActWait <= 0)
		{
			m_Orc = m_ActMotionL[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (m_MoveTime < 480)
	{
		m_Orc = 0;
	}
	else
	{
		m_MoveTime = 0;
		m_ActIndex = 0;
	}

	if (m_PosX + 90 > player.m_PosX + 90)
	{
		if (player.m_PosX <= m_PosX + 180)//UŒ‚‚ÌğŒ(‰EŒü‚«)
		{
			if (--m_ActWait <= 0)
			{
				m_Orc = m_AttMotionL[m_AttIndex];
				m_AttIndex++;
				m_ActWait = m_ActSpeed;
				m_AttIndex %= m_AttackMax;
			}

		}
	}
	else
	{
		if (player.m_PosX + 180 >= m_PosX)//UŒ‚‚ÌğŒ(¶Œü‚«)
		{
			if (--m_ActWait <= 0)
			{
				m_Orc = m_AttMotionR[m_AttIndex];
				m_AttIndex++;
				m_ActWait = m_ActSpeed;
				m_AttIndex %= m_AttackMax;
			}
		}
	}
	
	
	
}

void Orc::Draw()
{
	LoadDivGraph("Res/Monster/side/Orc/Orcs.png", m_OrcMax, 4, 3, 180, 210, m_Orcs, TRUE);
	DrawGraph(m_PosX, m_PosY, m_Orcs[m_Orc], TRUE);
}

bool Orc::CheckHit(float x, float y, float width, float height)
{
	return false;
}
