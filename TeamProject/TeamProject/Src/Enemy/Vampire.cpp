#include"Vampire.h"
#include"DxLib.h"

Vampire::Vampire()
{
	m_Vampire = 0;
	m_VampirePosx = 500;
	m_VampirePosy = 400;
	m_MoveTime = 0;
	m_WaitTime = 0;
}

Vampire::~Vampire()
{
}

void Vampire::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_VampirePosx++;
		m_Vampire = 7;

	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Vampire = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_VampirePosx--;
		m_Vampire = 1;
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

	DrawGraph(m_VampirePosx, m_VampirePosy, m_Vampires[m_Vampire], TRUE);
}

bool Vampire::CheckHit(float x, float y, float width, float height)
{
	return false;
}
