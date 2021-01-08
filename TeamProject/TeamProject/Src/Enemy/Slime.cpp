#include"Slime.h"
#include"DxLib.h"
#include"../Scene/InGameScene.h"

InGameScene inGameScene;

Slime::Slime()
{
	
	for (int i = 0; i < m_SlimeNumberMax; i++)
	{
		m_Slime[i] = 0;
		m_MoveTime[i] = 0;
		m_ActIndex[i] = 0;
		m_PosX[i] = 0;
		m_PosY[i] = 0;
	}
	m_ActSpeed = 10;
	InitTexture();
}

Slime::~Slime()
{
	ReleaseTexture();
}

void Slime::Exec(int x_ ,int y_ ,int number)
{
	m_MoveTime[number]++;
	if (m_MoveTime[number] < 180)
	{
		m_PosX[number]++;
		if (--m_ActWait[number] <= 0)
		{
			m_Slime[number] = m_ActMotionR[m_ActIndex[number]];
			m_ActIndex[number]++;
			m_ActWait[number]= m_ActSpeed;
			m_ActIndex[number] %= m_MotionMax;
		}
	}
	else if (180 <= m_MoveTime[number] && m_MoveTime[number] < 300)
	{
		m_Slime[number] = 4;
	}
	else if (300 <= m_MoveTime[number] && m_MoveTime[number] < 480)
	{
		m_PosX[number]--;
		if (--m_ActWait[number] <= 0)
		{
			m_Slime[number] = m_ActMotionL[m_ActIndex[number]];
			m_ActIndex[number]++;
			m_ActWait[number] = m_ActSpeed;
			m_ActIndex[number] %= m_MotionMax;
		}
	}
	else if (m_MoveTime[number] < 600)
	{
		m_Slime[number] = 0;
	}
	else
	{
		m_MoveTime[number] = 0;
	}
	
}

void Slime::Draw(Camera camera, int x_[], int y_[],int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(x_[number])+ m_PosX[number];
	int DrawY = camera.ConvertPosYWorldToScreen(y_[number]);

	DrawPixel(DrawX, DrawY, GetColor(255, 255, 255));				//¶ã
	DrawPixel(DrawX + 180, DrawY, GetColor(255, 255, 255));			//‰Eã
	DrawPixel(DrawX, DrawY + 210, GetColor(255, 255, 255));		//¶‰º
	DrawPixel(DrawX + 180, DrawY + 210, GetColor(255, 255, 255));	//‰E‰º

	DrawGraph(DrawX, DrawY, m_Slimes[m_Slime[number]], TRUE);
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

void Slime::GetSlimeArray(int array_[])
{
	for (int i = 0; i < m_SlimeNumberMax; i++)
	{
		m_PosX[i] = array_[i];
	}
}

bool Slime::CheckHit(float x, float y,int number)
{
	if ((x + 120 > m_PosX[number] && y < m_PosY[number]) ||
		(x + 120 > m_PosX[number] && y + 180 < m_PosY[number] + 130) ||
		(x > m_PosX[number] + 120 && y < m_PosY[number]) ||
		(x > m_PosX[number] + 120 && y + 180 < m_PosY[number] + 130))
	{

	}
	return false;
}
