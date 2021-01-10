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
	m_AttIndex = 0;
	m_KnockBack = 17;
	m_Back = 1;
	m_Hit == false;
	m_IsAttack == false;
	m_IsAlive = true;
	InitTexture();
}

Vampire::~Vampire()
{
	ReleaseTexture();
}

void Vampire::Exec(int x_,int y_)
{
	if (m_Hit == false && m_IsAttack == false)
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
	
	if ((x_ + 120 > m_PosX && y_ > m_PosY) ||
		(x_ + 120 > m_PosX && y_ + 180 > m_PosY + 270))
	{
		if ((x_ < m_PosX + 110 && y_ > m_PosY) ||
			(x_ < m_PosX + 110 && y_ + 180 > m_PosY + 270))
		{
			m_IsAttack = true;
			if (--m_ActWait <= 0)
			{
				m_Vampire = m_AttMotionL[m_AttIndex];
				m_AttIndex++;
				m_ActWait = m_ActSpeed;
				m_AttIndex %= m_MotionMax;
			}
		}
		else
		{
			m_IsAttack = false;
		}
	}

	if ((x_ > m_PosX + 111 && y_ > m_PosY) ||
		(x_ > m_PosX + 111 && y_ + 180 > m_PosY + 270))
	{
		if ((x_ <m_PosX + 230 && y_ > m_PosY) ||
			(x_< m_PosX + 230 && y_ + 180 > m_PosY + 270))
		{
			m_IsAttack = true;
			if (--m_ActWait <= 0)
			{
				m_Vampire = m_AttMotionR[m_AttIndex];
				m_AttIndex++;
				m_ActWait = m_ActSpeed;
				m_AttIndex %= m_MotionMax;
			}
		}
		else
		{
			m_IsAttack = false;
		}
	}

	if (m_IsAlive == true)
	{
		if (CheckHit(x_, y_) == true)
		{
			m_Hit = true;
		}
		if (m_Hit == true)
		{
			m_KnockBack -= m_Back;
			if (m_KnockBack == 0)
			{
				m_IsAlive = false;
			}
			if (m_IsRight == true)
			{
				m_Vampire = 8;
				m_PosX -= m_KnockBack;
			}
			if (m_IsRight == false)
			{
				m_Vampire = 9;
				m_PosX += m_KnockBack;
			}
		}
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

bool Vampire::CheckHit(int x_,int y_)
{
	if ((x_ + 120 > m_PosX && y_ < m_PosY) ||
		(x_ + 120 > m_PosX && y_ + 180 < m_PosY + 270) ||
		(x_ + 50 > m_PosX + 220 && y_ < m_PosY) ||
		(x_ + 50 > m_PosX + 220 && y_ + 180 < m_PosY + 270))
	{
		if ((x_ + 50 < m_PosX && y_ > m_PosY + 270) ||
			(x_ + 120 < m_PosX + 220 && y_ > m_PosY + 270) ||
			(x_ + 50 < m_PosX + 220 && y_ + 180 > m_PosY) ||
			(x_ + 120 < m_PosX && y_ + 180 > m_PosY))
		{
			return true;
		}

	}
	return false;
}
