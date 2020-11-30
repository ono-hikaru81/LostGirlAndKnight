#include "DxLib.h"
#include "Gimmick.h"
#include"Main.h"

Gimmick::Gimmick()
{
	m_TreeDraw = NULL;
	m_Angle = 90;
	m_cooltime = 0;
	m_Radian = 0;
	m_cooltime = 0;
}

Gimmick::~Gimmick()
{
}

void Gimmick::BridgeMove()
{
	if (0 < m_Angle)
	{
		m_cooltime++;
		if (m_cooltime == 1)
		{
			if (m_Radian <= 90)
			{
				m_Radian = (3.14 / 180 * m_Angle);
				m_Angle--;
				m_cooltime = 0;
				if (m_Angle == 0)
				{
					m_Radian = 0;
				}
			}
		}
	}
}

void Gimmick::BridgeDraw()
{
	m_TreeDraw = LoadGraph("Res/maruta.jpeg");
	DrawRotaGraph2(400.0f, WindowHeight, 680.0f, 84.0f, 0.4f, m_Radian, m_TreeDraw, TRUE);
}

bool Gimmick::CheckHit()
{
	return false;
}
