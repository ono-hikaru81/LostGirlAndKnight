#include"Slime.h"
#include"DxLib.h"

#include"Slime.h"
#include"DxLib.h"

Slime::Slime()
{
	m_Slime = 0;
	m_SlimePosx = 500;
	m_SlimePosy = 400;
	m_MoveTime = 0;
	m_WaitTime = 0;
}

Slime::~Slime()
{
}

void Slime::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_SlimePosx++;
		m_Slime = 7;

	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Slime = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_SlimePosx--;
		m_Slime = 1;
	}
	else if (m_MoveTime < 480)
	{
		m_Slime = 0;
	}
	else
	{
		m_MoveTime = 0;
	}
}

void Slime::Draw()
{
	LoadDivGraph("Res/Monster/side/Slime/Slimes.png", m_SlimeMax, 4, 3, 180, 210, m_Slimes, TRUE);

	DrawGraph(m_SlimePosx, m_SlimePosy, m_Slimes[m_Slime], TRUE);
}

bool Slime::CheckHit(float x, float y, float width, float height)
{
	return false;
}
