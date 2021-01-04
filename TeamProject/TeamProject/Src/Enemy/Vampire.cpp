#include"Vampire.h"
#include"DxLib.h"

Vampire::Vampire()
{
	m_Vampire = 0;
	m_Posx = 6360;
	m_Posy = 570;
	m_MoveTime = 0;
	m_ActIndex = 0;
	m_ActSpeed = 10;

	InitTexture();
}

Vampire::~Vampire()
{
	ReleaseTexture();
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

void Vampire::Draw(Camera camera, int x_, int y_)
{
	int DrawPosX = camera.ConvertPosXWorldToScreen(x_);
	int DrawPosY = camera.ConvertPosYWorldToScreen(y_);

	DrawGraph(DrawPosX, DrawPosY, m_Vampires[m_Vampire], TRUE);
}

void Vampire::InitTexture()
{
	LoadDivGraph("Res/Monster/Mid/Vampire/Vampires.png", m_VampireMax, 4, 3, 220, 270, m_Vampires, TRUE);
}

void Vampire::ReleaseTexture()
{
	for (int i = 0; i < m_VampireMax; i++)
	{
		DeleteGraph(m_Vampires[i]);
	}
}

bool Vampire::CheckHit(float x, float y, float width, float height)
{
	return false;
}
