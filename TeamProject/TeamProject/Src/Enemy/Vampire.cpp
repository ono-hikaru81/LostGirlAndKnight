#include"Vampire.h"
#include"DxLib.h"

Vampire::Vampire()
{
	m_Vampire = 0;
	m_Posx = 500;
	m_Posy = 400;
	m_MoveTime = 0;
}

Vampire::~Vampire()
{
}

void Vampire::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_PosX++;
		if (--m_ActWait <= 0)
		{
			m_Vampire = m_ActMotionR[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Vampire = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_PosX--;
		if (--m_ActWait <= 0)
		{
			m_Vampire = m_ActMotionL[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (m_MoveTime < 480)
	{
		m_Vampire = 0;
	}
	else
	{
		m_MoveTime = 0;
	}
}

void Vampire::Draw()
{
	LoadDivGraph("Res/Monster/side/Vampire/Vampires.png", m_VampireMax, 4, 3, 180, 210, m_Vampires, TRUE);

	DrawGraph(m_Posx, m_Posy, m_Vampires[m_Vampire], TRUE);
}

bool Vampire::CheckHit(float x, float y, float width, float height)
{
	return false;
}
