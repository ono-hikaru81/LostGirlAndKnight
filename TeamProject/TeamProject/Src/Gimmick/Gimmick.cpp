#include "DxLib.h"
#include "Gimmick.h"
#include"../Main.h"
#include"../Function/Input.h"
#include"../Character/Player.h"

Gimmick::Gimmick()
{
	m_BridgeDraw = NULL;
	m_Botton = 0;
		
	for (int i = 0; i < m_Max; i++)
	{
		m_Angle[i] = 90;
		m_Radian[i] = 1.5;
		m_RockHit[i] = 0;
		m_Trap[i] = 0;
		m_Rock[i] = 0;

		m_BottonHit[i] = false;
		m_IsPush[i] = false;
		m_TrapHit[i] = false;
	}
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

void Gimmick::BridgeMove(int x_,int y_,int number)
{
	if (m_IsPush[number] == true)
	{
		if (0 < m_Angle[number])
		{
			if (m_Radian[number] <= 90)
			{
				m_Radian[number] = (3.14 / 180 * m_Angle[number]);
				m_Angle[number]--;
				if (m_Angle[number] == 0)
				{
					BridgeCheckHit(x_, y_, number);
					m_Radian[number] = 0;
				}
			}
		}
	}
}

void Gimmick::BridgeDraw(Camera camera,int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(m_BridgePosX[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(m_BridgePosY[number]);
	
	DrawRotaGraph2(DrawX, DrawY, 120, 40, 1.2f, m_Radian[number], m_BridgeDraw, TRUE);
}

void Gimmick::BottonMove(int x1_, int y1_,int number)
{
	bool IsHit = false;
	if (BottonCheckHit(x1_,y1_,number) == true)
	{
		IsHit = true;
		m_IsPush[number] = true;
		m_BottonHit[number] = true;
	}
	else
	{
		IsHit = false;
	}
	//if (GetKeyStatus(KEY_INPUT_X) == InputState::Hold)
	if (IsHit == true)
	{
		m_Botton = 1;
	}
	else
	{
		m_Botton = 0;
	}
}

void Gimmick::BottonDraw(Camera camera,int number)
{

	int DrawX = camera.ConvertPosXWorldToScreen(m_BottonPosX[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(m_BottonPosY[number]);

	DrawFormatString(200, 500, GetColor(0, 255, 255), "%d,%d", m_BottonPosX[0], m_BottonPosY[0]);
	DrawFormatString(200, 600, GetColor(0, 255, 255), "%d,%d", m_BottonPosX[1], m_BottonPosY[1]);
	if (m_BottonHit[number] == true)
	{
		DrawGraph(DrawX, DrawY, m_Bottons[1], TRUE);
	}
	else
	{
		DrawGraph(DrawX, DrawY, m_Bottons[0], TRUE);
	}
	
}

void Gimmick::TrapMove(int x_,int y_ ,int number)
{
	if (TrapCheckHit(x_,y_ ,number)==true)
	{
		m_TrapHit[number] = true;
	}

	if (m_TrapHit[number] == true)
	{
		m_Trap[number]++;
		if (m_Trap[number] == 3)
		{
			m_Trap[number] = 2;
		}
	}
}

void Gimmick::TrapDraw(Camera camera, int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(m_TrapPosX[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(m_TrapPosY[number]);

	DrawGraph(DrawX, DrawY, m_Traps[m_Trap[number]], TRUE);
}

void Gimmick::RockMove(int x_, int y_, int number)
{
	//UŒ‚‚ðŽó‚¯‚é
	if (RockCheckHit(x_, y_, number) == true)
	{
		if (m_Rock[number] <= 2)
		{
			m_Rock[number]++;
		}
	}
}

void Gimmick::RockDraw(Camera camera, int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(m_RockPosX[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(m_RockPosY[number]);

	DrawGraph(DrawX, DrawY, m_Rocks[m_Rock[number]],TRUE);
}

void Gimmick::BrockExec(int x_, int y_, int number)
{
	if (BrockCheckHit(x_, y_, number) == true)
	{
		m_num[number] = true;
	}
	else
	{
		m_num[number] = false;
	}
}

void Gimmick::BrockDraw(Camera camera, int number)
{
	int DrawX = camera.ConvertPosXWorldToScreen(m_BrockPosX[number]);
	int DrawY = camera.ConvertPosYWorldToScreen(m_BrockPosY[number]);

	DrawGraph(DrawX, DrawY, m_BrockTex, TRUE);
	if (m_num[number] == true)
	{
		DrawString(DrawX, DrawY, "Hit", GetColor(255, 0, 0));
	}
	else
	{
		DrawString(DrawX, DrawY, "NoHit", GetColor(255, 0, 0));
	}
}

void Gimmick::GetArray(int BottonX_[], int BottonY_[], int BridgeX_[], int BridgeY_[], int TrapX_[], int TrapY_[], int RockX_[], int RockY_[], int BrockX_[], int BrockY_[])
{
	for (int i = 0; i < m_Max; i++)
	{
		m_BottonPosX[i] = BottonX_[i];
		m_BottonPosY[i] = BottonY_[i];
		m_BridgePosX[i] = BridgeX_[i];
		m_BridgePosY[i] = BridgeY_[i];
		m_TrapPosX[i] = TrapX_[i];
		m_TrapPosY[i] = TrapY_[i];
		m_RockPosX[i] = RockX_[i];
		m_RockPosY[i] = RockY_[i];
		m_BrockPosX[i] = BrockX_[i];
		m_BrockPosY[i] = BrockY_[i];
	}
	
}

bool Gimmick::CheckHit()
{
	return false;
}

bool Gimmick::BottonCheckHit(int x1_,int y1_,int number)
{
	
	if ((x1_ + 120> m_BottonPosX[number] && y1_ < m_BottonPosY[number]) ||
		(x1_ + 120> m_BottonPosX[number] && y1_ + 180 < m_BottonPosY[number]+30)||
		(x1_ + 50 > m_BottonPosX[number] + 120&& y1_ < m_BottonPosY[number]) ||
		(x1_ + 50 > m_BottonPosX[number] + 120 && y1_ +180 < m_BottonPosY[number] +30))
	{
		return true;
	}
	return false;
}

bool Gimmick::BridgeCheckHit(int x_, int y_, int number)
{
	if ((x_ > m_BridgePosX[number] && y_ + 180 < m_BridgePosY[number]) ||
		(x_ + 180 > m_BridgePosX[number] && y_ + 180 < m_BridgePosY[number]))
	{
		return true;
	}
	return false;
}

bool Gimmick::TrapCheckHit(int x_, int y_, int number)
{//70
	if ((x_ +120> m_TrapPosX[number] && y_ < m_TrapPosY[number])||
		(x_ +120> m_TrapPosX[number] && y_ + 180 < m_TrapPosY[number]+70) ||
		(x_ +50 > m_TrapPosX[number] + 132	&&   y_ < m_TrapPosY[number])||
		(x_ +50 > m_TrapPosX[number] + 132 && y_ + 180 < m_TrapPosY[number]+70))
	{
		return true;
	}
	return false;
}

bool Gimmick::RockCheckHit(int x_, int y_, int number)
{
	if ((x_ + 120 > m_RockPosX[number] && y_ < m_RockPosY[number]) ||
		(x_ + 120 > m_RockPosX[number] && y_ + 180 < m_RockPosY[number] + 370) ||
		(x_ +50 > m_RockPosX[number] + 120 && y_ < m_RockPosY[number] ) ||
		(x_ +50 > m_RockPosX[number] + 120 && y_ + 180 < m_RockPosY[number] + 370))
	{
		return true;
	}
	return false;
}

bool Gimmick::BrockCheckHit(int x_, int y_, int number)
{
	if ((x_ + 120> m_BrockPosX[number] && y_< m_BrockPosY[number]) ||
		(x_ + 120> m_BrockPosX[number] && y_ + 180 < m_BrockPosY[number] + 130)||
		(x_ > m_BrockPosX[number] + 120 && y_ < m_BrockPosY[number]) ||
		(x_ > m_BrockPosX[number] + 120 && y_ + 180 < m_BrockPosY[number] + 130))
	{
		 return true;
	}	
	return false;
}
