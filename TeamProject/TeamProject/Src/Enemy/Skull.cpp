#include"Skull.h"
#include"DxLib.h"

Skull::Skull()
{
	m_Skull = 0;
	m_Posx = 500;
	m_Posy = 400;
	m_MoveTime = 0;
}

Skull::~Skull()
{
}

void Skull::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_PosX++;
		if (--m_ActWait <= 0)
		{
			m_Skull = m_ActMotionR[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Skull = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_PosX--;
		if (--m_ActWait <= 0)
		{
			m_Skull = m_ActMotionL[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (m_MoveTime < 480)
	{
		m_Skull = 0;
	}
	else
	{
		m_MoveTime = 0;
	}
}

void Skull::Draw()
{
	LoadDivGraph("Res/Monster/side/Skull/Skulls.png", m_SkullMax, 4, 3, 180, 210, m_Skulls, TRUE);

	DrawGraph(m_Posx, m_Posy, m_Skulls[m_Skull], TRUE);
}

bool Skull::CheckHit(float x, float y, float width, float height)
{
	return false;
}
