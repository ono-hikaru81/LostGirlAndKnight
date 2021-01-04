#include"Wolfman.h"
#include"DxLib.h"

Wolfman::Wolfman()
{
	m_Wolfman = 0;
	m_Posx = 6000;
	m_Posy = 470;
	m_MoveTime = 0;
	m_ActIndex = 0;
	m_ActSpeed = 10;

	InitTexture();
}

Wolfman::~Wolfman()
{
	ReleaseTexture();
}

void Wolfman::Exec()
{
	m_MoveTime++;
	if (m_MoveTime < 180)
	{
		m_PosX++;
		if (--m_ActWait <= 0)
		{
			m_Wolfman = m_ActMotionR[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (180 <= m_MoveTime && m_MoveTime < 240)
	{
		m_Wolfman = 5;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 420)
	{
		m_PosX--;
		if (--m_ActWait <= 0)
		{
			m_Wolfman = m_ActMotionL[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
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

void Wolfman::Draw(Camera camera, int x_, int y_)
{
	int DrawPosX = camera.ConvertPosXWorldToScreen(x_);
	int DrawPosY = camera.ConvertPosYWorldToScreen(y_);

	DrawGraph(DrawPosX, DrawPosY, m_Wolfmans[m_Wolfman], TRUE);
}

void Wolfman::InitTexture()
{
	LoadDivGraph("Res/Monster/Mid/Wolfman/Wolfman.png", m_WolfmanMax, 4, 3, 220, 270, m_Wolfmans, TRUE);
}

void Wolfman::ReleaseTexture()
{
	for (int i = 0; i < m_WolfmanMax; i++)
	{
		DeleteGraph(m_Wolfmans[i]);
	}
}

bool Wolfman::CheckHit(float x, float y, float width, float height)
{
	return false;
}
