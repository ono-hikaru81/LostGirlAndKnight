#include"Slime.h"
#include"DxLib.h"
#include"../Scene/InGameScene.h"

InGameScene inGameScene;

Slime::Slime()
{
	m_Slime = 0;
	m_MoveTime = 0;
	m_ActIndex = 0;
	m_ActSpeed = 10;
	InitTexture();
	posx = 0;
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
		posx++;
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
		m_Slime = 4;
	}
	else if (240 <= m_MoveTime && m_MoveTime < 400)
	{
		posx--;
		if (--m_ActWait <= 0)
		{
			m_Slime = m_ActMotionL[m_ActIndex];
			m_ActIndex++;
			m_ActWait = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
	}
	else if (m_MoveTime < 460)
	{
		m_Slime = 0;
	}
	else
	{
		m_MoveTime = 0;
	}
	
}

void Slime::Draw(Camera camera, int x_[], int y_[],int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(x_[number])+ posx;
	int DrawY = camera.ConvertPosYWorldToScreen(y_[number]);

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

void Slime::SetPos(int Posx[])
{
	for (int i = 0; i < m_SlimeNumberMax; i++)
	{
		m_PosX[i] = Posx[i];
	}
}

bool Slime::CheckHit(float x, float y, float width, float height)
{
	return false;
}
