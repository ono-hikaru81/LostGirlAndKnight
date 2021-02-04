#include "DxLib.h"
#include "BlindGirl.h"
#include "../Difinition.h"
#include "../Character/Player.h"
#include"../Function/Input.h"
#include "../Stage/Map.h"

static Player player;

Girl::Girl()
{
	// ステータス
	m_Hp = 2;
	m_Speed = 8;
	m_JumpVelocity = 0;

	//位置座標 
	m_PosX = 120;
	m_PosY = 770;
	m_CenterPosX = (m_PosX + 180) / 2;
	m_CenterPosY = (m_PosY + 180) / 2;

	// 管理変数
	m_Girl = 0;
	m_ActSpeed = 20;
	m_WaitIndex = 0;
	m_WlkIndex = 0;
	m_DedIndex = 0;
	m_ActStop = m_ActSpeed;

	// 実行確認
	m_StopExec = true;
	m_WalkExec = false;
	m_JumpExec = false;

	m_CurrentAction = ActionType::Wait;
}

Girl::~Girl()
{
}

void Girl::InitTexture()
{
	LoadDivGraph("Res/Character/Girls.png", m_GirlMax,5,5,180,180,m_Girls);
}

void Girl::Move(Player player)
{
	int NewPosX = m_PosX;
	int NewPosY = m_PosY;

	int Horizontal = 0;
	int Vertical = 0;

	if (GetKeyStatus(KEY_INPUT_S) == InputState::Pushed)
	{
		if (m_CurrentAction == ActionType::Move)
		{
			m_CurrentAction = ActionType::Wait;
		}
		else if (m_CurrentAction == ActionType::Wait)
		{
			m_CurrentAction = ActionType::Move;
		}
	}

	//if (player.m_IsFloatingAir == true)
	//{
	//	m_JumpVelocity = -20;
	//	m_PosY += m_JumpVelocity;
	//	m_JumpVelocity += 1;
	//	if (player.m_IsRight == true)
	//	{
	//		m_Girl = 7;	
	//	}
	//	else
	//	{
	//		m_Girl = 18;
	//	}
	//	if (m_PosY >= WindowHeight - MapChipHeight - 180)//重力加速
	//	{
	//		m_JumpVelocity = 0;
	//	}
	//}

	if (m_CurrentAction == ActionType::Wait)
	{
		if (--m_ActStop <= 0)
		{
			if (player.m_IsRight == true)
			{
				m_Girl = m_WatMotionR[m_WaitIndex];
			}
			else
			{
				m_Girl = m_WatMotionL[m_WaitIndex];
			}
			m_WaitIndex++;
			m_ActStop = m_ActSpeed;
			m_WaitIndex %= m_MotionMax;
		}
	}
	else if (m_CurrentAction == ActionType::Move)
	{
		if (--m_ActStop <= 0)
		{
			if (player.m_PosX >= m_PosX)
			{
				m_Girl = m_WlkMotionR[m_WlkIndex];
				Horizontal += m_Speed;
			}
			else if(player.m_PosX <= m_PosX)
			{
				m_Girl = m_WlkMotionL[m_WlkIndex];
				Horizontal -= m_Speed;
			}
			m_WlkIndex++;
			m_ActStop = m_ActSpeed;
			m_WlkIndex %= m_MotionMax;
		}
	}

	Vertical += g_Gravity;

	int RectX = m_PosX + 60;
	int RectY = m_PosY;
	int RectWidth = m_PosX + 120;
	int RectHeight = m_PosY + 180;

	EdgeType ContactEdge = InValid;
	int ContactPosX = m_PrevPosX;
	int ContactPosY = m_PrevPosY;

	// X軸の判定
	if (g_map.CheckHit(RectX, RectY, RectWidth, RectHeight, Horizontal, 0, ContactEdge, ContactPosX) == false)
	{
		m_PosX += Horizontal;
	}
	else
	{
		AdjustToMapChipEdgePosition(ContactEdge, ContactPosX);
	}

	// Y軸の判定
	if (g_map.CheckHit(RectX, RectY, RectWidth, RectHeight, 0, Vertical, ContactEdge, ContactPosY) == false)
	{
		m_PosY += Vertical;
//		m_IsFloatingAir = true;
	}
	else
	{
		AdjustToMapChipEdgePosition(ContactEdge, ContactPosY);
	}

	m_PrevPosX = m_PosX;
	m_PrevPosY = m_PosY;

	//else if ()//DedMotion
	//{
	//	if (player.m_IsRight == true)
	//	{
	//		m_DedMotionR[m_DedIndex];
	//	}
	//	else
	//	{
	//		m_DedMotionL[m_DedIndex];
	//	}
	//	m_DedIndex++;
	//	m_ActStop = m_ActSpeed;
	//	m_DedIndex %= m_DedMotionMax;
	//}


}

void Girl::Draw(Player player, Camera camera)
{
	int DrawPosX = camera.ConvertPosXWorldToScreen(m_PosX - 63);
	int DrawPosY = camera.ConvertPosYWorldToScreen(m_PosY);

	DrawGraph(DrawPosX, DrawPosY, m_Girls[m_Girl], TRUE);
}

void Girl::ReleaseTexture()
{
	for (int i = 0; i < m_GirlMax; i++)
	{
		DeleteGraph(m_Girls[i]);
	}
}

void Girl::AdjustToMapChipEdgePosition(EdgeType contact_edge_, int contact_pos_)
{
	switch (contact_edge_)
	{
	case Top:
		m_PosY = contact_pos_;
//		m_IsFloatingAir = false;
		break;
	case Left:
		m_PosX = contact_pos_;
		break;
	case Right:
		m_PosX = contact_pos_;
		break;
	case Bottom:
		m_PosY = contact_pos_;
		break;
	}
}

