#include"Dragon.h"
#include"DxLib.h"
#include"../Main.h"

enum Motion
{
	Wait,
	Attack
};
Motion motion = Wait;

Dragon::Dragon()
{
	m_PosX = 1000 ;//WindowWidth -500
	m_PosY = WindowHeight - MapChipHeight - 360;
	m_Dragon = 0;
	m_WaitTime = 0;
	m_AttackTime = 0;
}

Dragon::~Dragon()
{
}

void Dragon::InitTexture()
{
	m_Dragones[0] = LoadGraph("Res/Monster/Boss/Dragon.png", TRUE);
	m_Dragones[1] = LoadGraph("Res/Monster/Boss/DragonBress_1.png", TRUE);
	m_Dragones[2] = LoadGraph("Res/Monster/Boss/Dragon_Bress_2.png", TRUE);
	m_Dragones[3] = LoadGraph("Res/Monster/Boss/Dragon_Dead.png", TRUE);
}

void Dragon::Exec()
{
	switch (motion)
	{
	case Wait:
		m_WaitTime++;
		if (m_WaitTime > 120)
		{
			motion = Attack;
			m_WaitTime = 0;
			break;
		}
		else
		{
			m_Dragon = 0;
		}
		break;
	case Attack:
		m_AttackTime++;
		if (m_AttackTime <120 )
		{
			m_Dragon = 1;
		}
		if(m_AttackTime >= 120 && m_AttackTime < 240)
		{
			m_Dragon = 2;
		}
		if (m_AttackTime > 240)
		{
			motion = Wait;
			m_AttackTime = 0;
			m_Dragon = 0;
			break;
		}
		break;
	}
}

void Dragon::Draw()
{
	DrawGraph(m_PosX, m_PosY, m_Dragones[m_Dragon], TRUE);
}
