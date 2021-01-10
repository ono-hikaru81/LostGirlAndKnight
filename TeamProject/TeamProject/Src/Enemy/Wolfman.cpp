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
	m_AttIndex = 0;
	m_KnockBack = 17;
	m_Back = 1;
	m_Hit = false;
	m_IsAttack = false;
	m_IsAlive = true;
	InitTexture();
}

Wolfman::~Wolfman()
{
	ReleaseTexture();
}

void Wolfman::Exec(int x_, int y_ )
{
	if (m_Hit == false && m_IsAttack == false)
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
			m_Wolfman = 4;
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
	
	if ((x_ + 120 > m_PosX && y_ > m_PosY) ||
		(x_ + 120 > m_PosX && y_ + 180 > m_PosY + 270))
	{
		if ((x_ < m_PosX + 110 && y_ > m_PosY) ||
			(x_ < m_PosX + 110 && y_ + 180 > m_PosY + 270))
		{
			m_IsAttack = true;
			if (--m_ActWait <= 0)
			{
				m_Wolfman = m_AttMotionL[m_AttIndex];
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
				m_Wolfman = m_AttMotionR[m_AttIndex];
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
				m_Wolfman = 8;
				m_PosX -= m_KnockBack;
			}
			if (m_IsRight == false)
			{
				m_Wolfman = 9;
				m_PosX += m_KnockBack;
			}
		}
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

bool Wolfman::CheckHit(int x_,int y_)
{
	if ((x_ + 120 > m_PosX && y_ < m_PosY) ||
		(x_ + 120 > m_PosX && y_ + 180 < m_PosY + 270) ||
		(x_ + 50 > m_PosX + 220 && y_ < m_PosY) ||
		(x_ + 50 > m_PosX + 220 && y_ + 180 < m_PosY + 270))
	{
		if ((x_ + 50 < m_PosX && y_ > m_PosY + 270) ||
			(x_ + 120 < m_PosX + 220 && y_ > m_PosY+ 270) ||
			(x_ + 50 < m_PosX+ 220 && y_ + 180 > m_PosY) ||
			(x_ + 120 < m_PosX && y_ + 180 > m_PosY))
		{
			return true;
		}

	}
	return false;
}
