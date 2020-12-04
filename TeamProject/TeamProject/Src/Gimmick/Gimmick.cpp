#include "DxLib.h"
#include "Gimmick.h"
#include"../Main.h"
#include"../Function/Input.h"

Gimmick::Gimmick()
{
	m_BridgeDraw = NULL;
	m_Angle  = 90;
	m_Radian = 0;
	m_ActBotton = 0;
	m_ActTrap   = 0;
	m_BottonExec = false;
	m_TrapExec   = false;
	m_BridgeExec = false;
}

Gimmick::~Gimmick()
{
}

void Gimmick::BridgeMove()
{
	if (0 < m_Angle)
	{
		if (m_Radian <= 90)
		{
			m_Radian = (3.14 / 180 * m_Angle);
			m_Angle--;
			if (m_Angle == 0)
			{
				m_Radian = 0;
			}
		}
	}
}

void Gimmick::BridgeDraw()
{
	m_BridgeDraw = LoadGraph("Res/Gimmick/Bridge.png");
	DrawRotaGraph2(200, 400, 120.0f, 40.0f, 1.2f, m_Radian, m_BridgeDraw, TRUE);
}

void Gimmick::BottonMove()
{
	if (UpdateKeyState() != 0) return;
	//if (m_BottonExec == true)
	if (GetKeyStatus(KEY_INPUT_X) == InputState::Hold)
	{
		m_ActBotton = 1;
	}
	else
	{
		m_ActBotton = 0;
	}
}

void Gimmick::BottonDraw()
{
	LoadDivGraph("Res/Gimmick/Bottons.png", m_BottonMax, 2, 1, 120, 30, m_Bottons);

	DrawGraph(120, 30, m_Bottons[m_ActBotton], TRUE);
	DrawGraph(120, 60, m_Bottons[m_ActBotton], TRUE);
}

void Gimmick::TrapMove()
{
	//if (m_TrapExec == true)
	if (GetKeyStatus(KEY_INPUT_Z) == InputState::Pushed)
	{
		m_TrapExec = true;
	}

	if (m_TrapExec == true)
	{
		m_ActTrap++;
		if (m_ActTrap == 3)
		{
			m_TrapExec = false;
			m_ActTrap = 2;
		}
	}
}

void Gimmick::TrapDraw()
{
	LoadDivGraph("Res/Gimmick/Traps.png",m_TrapMax, 3, 1, 132, 70, m_Traps);

	DrawGraph(300, 70, m_Traps[m_ActTrap], TRUE);
}

bool Gimmick::CheckHit()
{
	return false;
}
