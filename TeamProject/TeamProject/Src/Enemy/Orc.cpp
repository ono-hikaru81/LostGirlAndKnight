#include"Orc.h"
#include"DxLib.h"
#include"../Character/Player.h"
#include"../Difinition.h"

//static Player player;

Orc::Orc()
{
	for (int i = 0; i <m_NumberMax ; i++)
	{
		m_Orc[i] = 0;
		m_MoveTime[i] = 0;
		m_ActIndex[i] = 0;
		m_AttIndex[i] = 0;
		m_KnockBack[i] = 17;
		m_Back[i] = 1;

		m_IsAlive[i] = true;
		m_IsAttack[i] = false;
		m_Hit[i] = false;
	}
	
	m_ActSpeed = 15;
	InitTexture();
}

Orc::~Orc()
{
	ReleaseTexture();
}

void Orc::InitTexture()
{
	LoadDivGraph("Res/Monster/side/Orc/Orcs.png", m_OrcMax, 4, 3, 180, 210, m_Orcs, TRUE);
}

void Orc::ReleaseTexture()
{
	for (int  i = 0; i < m_OrcMax; i++)
	{
		DeleteGraph(m_Orcs[i]);
	}
}

void Orc::GetOrcArray(int arrayX_[], int arrayY_[])
{
	for (int i = 0; i < m_NumberMax; i++)
	{
		m_PosX[i] = arrayX_[i];
		m_PosY[i] = arrayY_[i];
	}
}

void Orc::Exec(int x_,int y_ ,int number)
{
	if (m_Hit[number] == false && m_IsAttack[number] == false)
	{
		m_MoveTime[number]++;
		if (m_MoveTime[number] < 180)
		{
			m_PosX[number]++;
			if (--m_ActWait[number] <= 0)
			{
				m_Orc[number] = m_ActMotionR[m_ActIndex[number]];
				m_ActIndex[number]++;
				m_ActWait[number] = m_ActSpeed;
				m_ActIndex[number] %= m_MotionMax;
			}
		}
		else if (180 <= m_MoveTime[number] && m_MoveTime[number] < 240)
		{
			m_Orc[number] = 5;
		}
		else if (240 <= m_MoveTime[number] && m_MoveTime[number] < 420)
		{
			m_PosX[number]--;
			if (--m_ActWait[number] <= 0)
			{
				m_Orc[number] = m_ActMotionL[m_ActIndex[number]];
				m_ActIndex[number]++;
				m_ActWait[number] = m_ActSpeed;
				m_ActIndex[number] %= m_MotionMax;
			}
		}
		else if (m_MoveTime[number] < 420 && m_MoveTime[number] < 480)
		{
			m_Orc[number] = 0;
		}
		else
		{
			m_MoveTime[number] = 0;
			m_ActIndex[number] = 0;
		}
	}

	if ((x_ + 120 > m_PosX[number] && y_ > m_PosY[number]) ||
		(x_ + 120 > m_PosX[number] && y_ + 180 > m_PosY[number] + 220))
	{
		if ((x_ < m_PosX[number] + 90 && y_ > m_PosY[number]) ||
			(x_ < m_PosX[number] + 90 && y_ + 180 > m_PosY[number] + 220))
		{
			m_IsAttack[number] = true;
			if (--m_ActWait[number] <= 0)
			{
				m_Orc[number] = m_AttMotionL[m_AttIndex[number]];
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
		if ((x_ <m_PosX[number] + 230 && y_ > m_PosY[number]) ||
			(x_< m_PosX[number] + 230 && y_ + 180 > m_PosY[number] + 230))
		{
			m_IsAttack[number] = true;
			if (--m_ActWait[number] <= 0)
			{
				m_Orc[number] = m_AttMotionR[m_AttIndex[number]];
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
				m_Orc[number] = 8;
				m_PosX[number] -= m_KnockBack[number];
			}
			if (m_IsRight[number] == false)
			{
				m_Orc[number] = 9;
				m_PosX[number] += m_KnockBack[number];
			}
		}
	}

}

void Orc::Draw(Camera camera,int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(m_PosX[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(m_PosY[number]);

	DrawGraph(DrawX, DrawY, m_Orcs[m_Orc[number]], TRUE);
}

bool Orc::CheckHit(int x_, int y_, int number)
{
	if ((x_ + 120 > m_PosX[number] && y_ < m_PosY[number]) ||
		(x_ + 120 > m_PosX[number] && y_ + 180 < m_PosY[number] + 220) ||
		(x_ + 50 > m_PosX[number] + 180 && y_ < m_PosY[number]) ||
		(x_ + 50 > m_PosX[number] + 180 && y_ + 180 < m_PosY[number] + 220))
	{
		if ((x_ + 50 < m_PosX[number] && y_ > m_PosY[number] + 220) ||
			(x_ + 120 < m_PosX[number] + 180 && y_ > m_PosY[number] + 220) ||
			(x_ + 50 < m_PosX[number] + 180 && y_ + 180 > m_PosY[number]) ||
			(x_ + 120 < m_PosX[number] && y_ + 180 > m_PosY[number]))
		{
			return true;
		}

	}
	return false;
}
