#include"Slime.h"
#include"DxLib.h"
#include"../Scene/InGameScene.h"

InGameScene inGameScene;

Slime::Slime()
{
	for (int i = 0; i < m_NumberMax; i++)
	{
		m_Slime[i] = 0;
		m_MoveTime[i] = 0;
		m_ActIndex[i] = 0;
		m_KnockBack[i] = 17;
		m_Back[i] = 1;

		m_IsAlive[i] = true;
		m_IsAttack[i] = false;
		m_Hit[i] = false;
	}
	
	m_ActSpeed = 15;
	InitTexture();
}

Slime::~Slime()
{
	ReleaseTexture();
}

void Slime::Exec(int x_, int y_, int number)
{
	if (m_Hit[number] == false && m_IsAttack[number] == false)
	{
		m_MoveTime[number]++;
		if (m_MoveTime[number] < 180)
		{
			m_PosX[number]++;
			m_IsRight[number] == true;
			if (--m_ActWait[number] <= 0)
			{
				m_Slime[number] = m_ActMotionR[m_ActIndex[number]];
				m_ActIndex[number]++;
				m_ActWait[number] = m_ActSpeed;
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
			m_IsRight[number] == false;
			if (--m_ActWait[number] <= 0)
			{
				m_Slime[number] = m_ActMotionL[m_ActIndex[number]];
				m_ActIndex[number]++;
				m_ActWait[number] = m_ActSpeed;
				m_ActIndex[number] %= m_MotionMax;
			}
		}
		else if (480 <= m_MoveTime[number] && m_MoveTime[number] < 600)
		{
			m_Slime[number] = 0;
		}
		else
		{
			m_MoveTime[number] = 0;
			m_ActIndex[number] = 0;
		}
	}

	if ((x_+120 > m_PosX[number] && y_ > m_PosY[number]) ||
		(x_+120 > m_PosX[number] && y_ + 180 > m_PosY[number] + 220))
	{
		if ((x_ < m_PosX[number] + 90 && y_ > m_PosY[number]) ||
			(x_ < m_PosX[number] + 90 && y_ + 180 > m_PosY[number] + 220))
		{
			m_IsAttack[number] = true;
			if (--m_ActWait[number] <= 0)
			{
				m_Slime[number] = m_AttMotionL[m_AttIndex[number]];
				m_AttIndex[number]++;
				m_ActWait[number] = m_ActSpeed;
				m_AttIndex[number] %= 2;
			}
		}
		else
		{
			m_IsAttack[number] = false;
		}
	}

	if ((x_ > m_PosX[number] + 91 && y_ > m_PosY[number]) ||
		(x_ > m_PosX[number] + 91 && y_ + 180 > m_PosY[number] + 230))
	{
		if((x_ <m_PosX[number] + 230&& y_ > m_PosY[number]) ||
			(x_< m_PosX[number] +230 && y_ + 180 > m_PosY[number] + 230))
		{
			m_IsAttack[number] = true;
			if (--m_ActWait[number] <= 0)
			{
				m_Slime[number] = m_AttMotionR[m_AttIndex[number]];
				m_AttIndex[number]++;
				m_ActWait[number] = m_ActSpeed;
				m_AttIndex[number] %= 2;
			}
		}
		else
		{
			m_IsAttack[number] = false;
		}
	}

	if (m_IsAlive[number] == true)
	{
		if (CheckHit(x_, y_, number) == true)
			{
				m_Hit[number] = true;
			}
		if (m_Hit[number] == true)
		{
			m_KnockBack[number] -= m_Back[number];
			if (m_KnockBack[number] == 0)
			{
				m_IsAlive[number] = false;
			}
			if (m_IsRight[number] == true)
			{
				m_Slime[number] = 8;
				m_PosX[number] -= m_KnockBack[number];
			}
			if (m_IsRight[number] == false)
			{
				m_Slime[number] = 9;
				m_PosX[number] += m_KnockBack[number];
			}
		}
	}
}

void Slime::Draw(Camera camera,int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(m_PosX[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(m_PosY[number]);

	
	if (m_IsAlive[number] == true)
	{
		DrawGraph(DrawX, DrawY, m_Slimes[m_Slime[number]], TRUE);
	}

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

void Slime::GetSlimeArray(int arrayX_[],int arrayY_[])
{
	for (int i = 0; i < m_NumberMax; i++)
	{
		m_PosX[i] = arrayX_[i];
		m_PosY[i] = arrayY_[i];
	}
}

bool Slime::CheckHit(int x_, int y_,int number)
{
	if ((x_ + 120 > m_PosX[number] && y_ < m_PosY[number]) ||
		(x_ + 120 > m_PosX[number] && y_ + 180 < m_PosY[number] + 220) ||
		(x_ + 50 > m_PosX[number] + 180 && y_ < m_PosY[number]) ||
		(x_ + 50 > m_PosX[number] + 180 && y_ + 180 < m_PosY[number] + 220))
	{
		if ((x_ + 50  < m_PosX[number] && y_ > m_PosY[number] + 220) ||
			(x_ + 120 <  m_PosX[number] + 180 && y_ > m_PosY[number] + 220)||
			(x_ + 50  < m_PosX[number] + 180 && y_ + 180 > m_PosY[number])||
			(x_ + 120 < m_PosX[number] && y_ + 180 > m_PosY[number]))
		{
			return true;
		}
	
	}
	return false;
}