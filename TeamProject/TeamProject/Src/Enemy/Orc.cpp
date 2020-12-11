#include"Orc.h"
#include"DxLib.h"

Orc::Orc()
{
	m_Orc = 0;
	m_OrcPosx = 500;
	m_OrcPosy = 400;
	m_MoveTime = 0;
	m_WaitTime = 0;
}

Orc::~Orc()
{
}

void Orc::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_OrcPosx++;
		m_Orc = 7;

	}
	else if(180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Orc = 5;
	}
	else if(240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_OrcPosx--;
		m_Orc = 1;	
	}
	else if (m_MoveTime < 480)
	{
		m_Orc = 0;	
	}
	else
	{
		m_MoveTime = 0;
	}
}

void Orc::Draw()
{
	LoadDivGraph("Res/Monster/side/Orc/Orcs.png", m_OrcMax, 4, 3, 180, 210, m_Orcs,TRUE);
	
	DrawGraph(m_OrcPosx, m_OrcPosy, m_Orcs[m_Orc], TRUE);
}

bool Orc::CheckHit(float x, float y, float width, float height)
{
	return false;
}
