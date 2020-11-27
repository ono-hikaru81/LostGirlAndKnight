#include "DxLib.h"
#include "Bridge.h"
#include"Main.h"

Bridge::Bridge()
{
	m_Angle = 90;
	m_cooltime = 0;
	m_Radian = 0;
	m_cooltime = 0;
}

Bridge::~Bridge()
{
}

void Bridge::Move()
{
	if (0 < m_Angle)
	{
		m_cooltime++;
		if (m_cooltime == 60)
		{
			if (m_Radian != 180)
			{
				m_Radian = 3.14 / 180 * m_Angle;
				m_Angle--;
				m_cooltime = 0;
			}
		}
	}
}

void Bridge::Draw()
{
	m_TreeDraw = LoadGraph("Res/maruta.jpeg");
	DrawRotaGraph2(400.0f, WindowHeight, 680.0f, 84.0f, 0.4f, m_Radian, m_TreeDraw, TRUE);
}

bool Bridge::CheckHit()
{
	return false;
}
