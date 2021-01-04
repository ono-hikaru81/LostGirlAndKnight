#include "DxLib.h"
#include "Gimmick.h"
#include"../Main.h"
#include"../Function/Input.h"
#include"../Character/Player.h"

Gimmick::Gimmick()
{
	m_BridgeDraw = NULL;
	m_Angle  = 90;
	m_Radian = 1.5;
	m_Botton = 0;
	m_Trap   = 0;
	m_Rock   = 0;
	m_Hitm_Time = 0;
	m_BottonExec = false;
	m_TrapExec   = false;
	m_IsPush = false;

	InitTexture();
}

Gimmick::~Gimmick()
{
	ReleaseTexture();
}

void Gimmick::InitTexture()
{
	m_BridgeDraw = LoadGraph("Res/Gimmick/Bridge.png");
	m_BrockTex = LoadGraph("Res/MapChip/Brock.png");
	LoadDivGraph("Res/Gimmick/Bottons.png", m_BottonMax, 2, 1, 120, 30, m_Bottons);
	LoadDivGraph("Res/Gimmick/Traps.png", m_TrapMax, 3, 1, 132, 70, m_Traps);
	LoadDivGraph("Res/MapChip/Rocks.png", m_RockMax, 3, 1, 120, 360, m_Rocks);
}

void Gimmick::ReleaseTexture()
{
	DeleteGraph(m_BridgeDraw);
	DeleteGraph(m_BrockTex);

	for (int i = 0; i < 2; i++)
	{
		DeleteGraph(m_Bottons[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(m_Traps[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(m_Rocks[i]);
	}
}

void Gimmick::BridgeMove()
{

	if (m_IsPush == true)
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
}

void Gimmick::BridgeDraw(Camera camera, int x_[], int y_[], int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(x_[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(y_[number]);

	DrawRotaGraph2(DrawX, DrawY, 120, 40, 1.2f, m_Radian, m_BridgeDraw, TRUE);
}

void Gimmick::BottonMove()
{
	//if (m_BottonExec == true)
	if (GetKeyStatus(KEY_INPUT_X) == InputState::Hold)
	{
		m_Botton = 1;
	}
	else
	{
		m_Botton = 0;
	}
}

void Gimmick::BottonDraw(Camera camera, int x_[], int y_[], int number,Player player)
{
	int DrawX = camera.ConvertPosXWorldToScreen(x_[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(y_[number]);
	BottonCheckHit(player, x_[number], x_[number]);
	DrawGraph(DrawX, DrawY, m_Bottons[m_Botton], TRUE);
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
		m_Trap++;
		if (m_Trap == 3)
		{
			m_TrapExec = false;
			m_Trap = 2;
		}
	}
}

void Gimmick::TrapDraw(Camera camera, int x_[], int y_[], int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(x_[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(y_[number]);

	DrawGraph(DrawX, DrawY, m_Traps[m_Trap], TRUE);
}

void Gimmick::RockMove()
{
	//UŒ‚‚ðŽó‚¯‚é
	if (GetKeyStatus(KEY_INPUT_C) == InputState::Hold)
	{
		m_Hitm_Time++;
		m_Rock = m_Rocks[m_Hitm_Time];
	}

}

void Gimmick::RockDraw(Camera camera, int x_[], int y_[], int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(x_[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(y_[number]);

	DrawGraph(DrawX, DrawY, m_Rocks[m_Rock],TRUE);
}

void Gimmick::BrockExec()
{
}

void Gimmick::BrockDraw(Camera camera, int x_[], int y_[], int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(x_[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(y_[number]);

	DrawGraph(DrawX, DrawY, m_BrockTex, TRUE);
}

bool Gimmick::CheckHit()
{
	return false;
}

bool Gimmick::BottonCheckHit(Player player,int x_, int y_)
{
	if((player.m_PosX > x_&& y_< player.m_PosY-180))
	return false;
}
