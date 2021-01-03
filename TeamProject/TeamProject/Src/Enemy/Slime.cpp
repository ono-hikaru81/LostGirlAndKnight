#include"Slime.h"
#include"DxLib.h"

Slime::Slime()
{
	m_Slime = 0;
	m_Posx = 500;
	m_Posy = 400;
	m_MoveTime = 0;
	m_ActIndex = 0;
	m_ActSpeed = 10;
	InitTexture();
}

Slime::~Slime()
{
	ReleaseTexture();
}

void Slime::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_PosX++;
		if (--m_ActWait <= 0)
		{
			m_Slime = m_ActMotionR[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Slime = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_PosX--;
		if (--m_ActWait <= 0)
		{
			m_Slime = m_ActMotionL[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
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

void Slime::Draw(Camera camera, int x_, int y_)
{
	int DrawX = camera.ConvertPosXWorldToScreen(x_);
	int DrawY = camera.ConvertPosYWorldToScreen(y_);

	DrawGraph(DrawX, DrawY, m_Slimes[m_Slime], TRUE);
}

void Slime::InitTexture()
{
	LoadDivGraph("Res/Monster/side/Slime/Slimes.png", m_SlimeMax, 4, 3, 180, 210, m_Slimes, TRUE);
}

void Slime::ReleaseTexture()
{
	for (int i = 0; i < 10; i++)
	{
		DeleteGraph(m_Slimes[i]);
	}
}

bool Slime::CheckHit(float x, float y, float width, float height)
{
	return false;
}
