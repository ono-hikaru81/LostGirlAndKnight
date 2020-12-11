#include"Wolfman.h"
#include"DxLib.h"

Wolfman::Wolfman()
{
	m_Wolfman = 0;
	m_WolfmanPosx = 500;
	m_WolfmanPosy = 400;
	m_MoveTime = 0;
	m_WaitTime = 0;
}

Wolfman::~Wolfman()
{
}

void Wolfman::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_WolfmanPosx++;
		m_Wolfman = 7;

	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Wolfman = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_WolfmanPosx--;
		m_Wolfman = 1;
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

	DrawGraph(m_WolfmanPosx, m_WolfmanPosy, m_Wolfmans[m_Wolfman], TRUE);
}

bool Wolfman::CheckHit(float x, float y, float width, float height)
{
	return false;
}
