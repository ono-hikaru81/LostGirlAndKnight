#include"Dragon.h"
#include"DxLib.h"
#include"../Difinition.h"

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
	m_IsAttack = false;
}

Dragon::~Dragon()
{
	ReleaseTexture();
}

void Dragon::ReleaseTexture()
{
	DeleteGraph(m_Fire);
	for (int i = 0; i < m_DragonMax; i++)
	{
		DeleteGraph(m_Dragones[i]);
	}
}

void Dragon::InitTexture()
{
	m_Dragones[0] = LoadGraph("Res/Monster/Boss/Dragon.png", TRUE);
	m_Dragones[1] = LoadGraph("Res/Monster/Boss/DragonBress_1.png", TRUE);
	m_Dragones[2] = LoadGraph("Res/Monster/Boss/Dragon_Bress_2.png", TRUE);
	m_Dragones[3] = LoadGraph("Res/Monster/Boss/Dragon_Dead.png", TRUE);
	m_Fire = LoadGraph("Res/Effect/Fire.PNG");
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
			m_IsAttack = true;
		}
		if (m_AttackTime > 240)
		{
			m_IsAttack = false;
			motion = Wait;
			m_AttackTime = 0;
			m_Dragon = 0;
			break;
		}
		break;
	}
}

void Dragon::Draw(Camera camera, int x_, int y_)
{

	int DrawX = camera.ConvertPosXWorldToScreen(x_);
	int DrawY = camera.ConvertPosYWorldToScreen(y_);

	DrawGraph(DrawX, DrawY, m_Dragones[m_Dragon], TRUE);
	if (m_IsAttack == true)
	{
		DrawGraph(DrawX +50, DrawY +240, m_Fire, TRUE);
	}

}
