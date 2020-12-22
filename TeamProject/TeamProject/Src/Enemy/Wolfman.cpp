#include"Wolfman.h"
#include"DxLib.h"

Wolfman::Wolfman()
{
	m_Wolfman = 0;
	m_Posx = 500;
	m_Posy = 400;
	m_MoveTime = 0;
	m_ActIndex = 0;
	m_ActSpeed = 10;
}

Wolfman::~Wolfman()
{
}

void Wolfman::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_PosX++;
		if (--m_ActWait <= 0)
		{
			m_Wolfman = m_ActMotionR[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Wolfman = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_PosX--;
		if (--m_ActWait <= 0)
		{
			m_Wolfman = m_ActMotionL[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (m_MoveTime < 480)
	{
		m_Wolfman = 0;
	}
	else
	{
		m_MoveTime = 0;
	}
}

void Wolfman::Draw()
{
	LoadDivGraph("Res/Monster/side/Wolfman/Wolfmans.png", m_WolfmanMax, 4, 3, 180, 210, m_Wolfmans, TRUE);

	DrawGraph(m_Posx, m_Posy, m_Wolfmans[m_Wolfman], TRUE);
}

bool Wolfman::CheckHit(float x, float y, float width, float height)
{
	return false;
}
