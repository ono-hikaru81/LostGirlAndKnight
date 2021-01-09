#include "DxLib.h"
#include "Player.h"
#include "../Main.h"
#include "../Function/Input.h"
#include "../Stage/Map.h"

Player::Player()
{
	//ステータス
	m_Hp = 10;
	m_Attack = 0;
	m_Speed = 8;
	m_JumpVelocity = 0;

	//Player座標
	m_PosX = 120;
	m_PosY = 700;
	m_CenterPosX = (m_PosX + 180) / 2;
	m_CenterPosY = (m_PosY + 180) / 2;

	// 管理変数
	m_Player = 0;
	m_m_Time = 0;
	m_ActSpeed = 20;
	m_ActIndex = 0;
	m_AttIndex = 0;
	m_MotionCooltime = 0;
	m_WaitIndex = 0;
	m_DeiIndex = 0;
	m_ActStop = m_ActSpeed;

	// 実行確認
	m_IsMove = false;
	m_IsRight = true;
	m_IsFloatingAir = false;
	m_Alive = true;
	m_JumpVelocity = 0;

	InitTexture();
}

Player::~Player()
{

}

int Player::GetPosX()
{
	return m_PosX;
}

int Player::GetPosY()
{
	return m_PosY;
}

int Player::GetCenterPosX()
{
	return m_CenterPosX;
}

int Player::GetCenterPosY()
{
	return m_CenterPosY;
}

void Player::Move()
{
	int NewPosX = m_PosX;
	int NewPosY = m_PosY;

	int Horizontal = 0;
	int Vertical = 0;

	// 左移動
	if (GetKeyStatus(KEY_INPUT_A) == InputState::Hold)
	{
		m_IsRight = false;
		Horizontal -= m_Speed;
		m_IsMove = true;
	}
	// 右移動
	else if (GetKeyStatus(KEY_INPUT_D) == InputState::Hold)
	{
		m_IsRight = true;
		Horizontal += m_Speed;
		m_IsMove = true;
	}
	// ジャンプ処理
	if (GetKeyStatus(KEY_INPUT_W) == InputState::Pushed && m_IsFloatingAir == false)
	{
		m_IsFloatingAir = true;
		m_JumpVelocity = InitialSpeed;
	}

	if (m_IsFloatingAir == true)
	{
		Vertical = (m_PosY - m_PrevPosY) - m_JumpVelocity;
		m_JumpVelocity -= 1;
	}

	if (m_IsFloatingAir == false)
	{
		Vertical = 0;
		m_JumpVelocity = 0;
	}

	Vertical += g_Gravity;

	int RectX = m_PosX + 60;
	int RectY = m_PosY;
	int RectWidth = m_PosX + 120;
	int RectHeight = m_PosY + 180;

	EdgeType ContactEdge = InValid;
	int ContactPos = m_PrevPosY;

	// X軸の判定
	if (g_map.CheckHit(RectX, RectY, RectWidth, RectHeight, Horizontal, 0, ContactEdge, ContactPos) == false)
	{
		m_PosX += Horizontal;
	}
	else
	{
		AdjustToMapChipEdgePosition(ContactEdge, ContactPos);
	}

	// Y軸の判定
	if (g_map.CheckHit(RectX, RectY, RectWidth, RectHeight, 0, Vertical, ContactEdge, ContactPos) == false)
	{
		m_PosY += Vertical;
		m_IsFloatingAir = true;
	}
	else
	{
		AdjustToMapChipEdgePosition(ContactEdge, ContactPos);
	}

	m_PrevPosX = m_PosX;
	m_PrevPosY = m_PosY;

	if (m_PosX < 0 || m_PosY < 0 || m_PosX > FieldWidth || m_PosY > FieldHeight)
	{
		m_Hp = 0;
	}

	// アニメーション
	if (m_IsMove == false)
	{
		if (--m_ActStop <= 0)
		{
			if (m_IsRight == false)
			{
				m_Player = m_WaiMotionL[m_WaitIndex];
			}
			else if (m_IsRight == true)
			{
				m_Player = m_WaiMotionR[m_WaitIndex];
			}
			m_WaitIndex++;
			m_ActStop = m_ActSpeed;
			m_WaitIndex %= m_MotionMax;
		}
	}
	else if (m_IsMove == true)
	{
		if (m_IsRight == false && m_IsFloatingAir == false)
		{
			if (--m_ActStop <= 0)
			{
				m_Player = m_WlkMotionL[m_ActIndex];
			}
		}
		else if (m_IsRight == true && m_IsFloatingAir == false)
		{
			if (--m_ActStop <= 0)
			{
				m_Player = m_WlkMotionR[m_ActIndex];
			}
			m_ActIndex++;
			m_ActStop = m_ActSpeed;
			m_ActIndex %= m_MotionMax;
		}
		else if (m_IsRight == false && m_IsFloatingAir == true)
		{
			m_Player = 12;
		}
		else if (m_IsRight == true && m_IsFloatingAir == true)
		{
			m_Player = 28;
		}
	}

	//攻撃
	if (GetKeyStatus(KEY_INPUT_SPACE) == InputState::Hold)
	{
		if (--m_ActStop <= 0)
		{
			if (m_IsRight == true)
			{
				m_Player = m_AttMotionR[m_AttIndex];
			}
			else
			{
				m_Player = m_AttMotionL[m_AttIndex];
			}
			m_AttIndex++;
			m_ActStop = m_ActSpeed;
			m_AttIndex %= m_AttMotionMax;
		}
	}
	else if (GetKeyStatus(KEY_INPUT_V) == InputState::Hold)
	{
		if (--m_ActStop <= 0)
		{
			if (m_IsRight == true)
			{
				m_Player = m_DeiMotionR[m_DeiIndex];
			}
			else
			{
				m_Player = m_DeiMotionL[m_DeiIndex];
			}
			m_DeiIndex++;
			m_ActStop = m_ActSpeed;
			m_DeiIndex %= m_DeiMotionMax;
		}
	}

	if (m_Hp <= 0 || m_PosY >= 1080)
	{
		m_Alive = false;
	}
}

void Player::Draw(Camera camera)
{
	int DrawPosX = camera.ConvertPosXWorldToScreen(m_PosX);
	int DrawPosY = camera.ConvertPosYWorldToScreen(m_PosY);

	DrawFormatString(200, 700, GetColor(0, 255, 255), "座標[ %d,%d ]", m_PosX, m_PosY);
	DrawBox(DrawPosX + 60, DrawPosY, DrawPosX + 120, DrawPosY + 180, GetColor(200, 200, 200), FALSE);
	DrawGraph(DrawPosX, DrawPosY, m_Players[m_Player], TRUE);

	//ルーズな当たり判定(点描画)
	DrawPixel(DrawPosX, DrawPosY, GetColor(255, 255, 255));				//左上
	DrawPixel(DrawPosX + 180, DrawPosY, GetColor(255, 255, 255));		//右上
	DrawPixel(DrawPosX, DrawPosY + 180, GetColor(255, 255, 255));		//左下
	DrawPixel(DrawPosX + 180, DrawPosY + 180, GetColor(255, 255, 255));	//右下
	

	//タイトな当たり判定(点描画)
	/*DrawPixel(DrawPosX + 50, DrawPosY, GetColor(255, 255, 255));		//左上
	DrawPixel(DrawPosX + 120, DrawPosY, GetColor(255, 255, 255));		//右上
	DrawPixel(DrawPosX + 50, DrawPosY + 180, GetColor(255, 255, 255));	//左下
	DrawPixel(DrawPosX + 120, DrawPosY + 180, GetColor(255, 255, 255));	//右下*/
}

void Player::InitTexture()
{
	LoadDivGraph("Res/Character/Players.png", m_PlayerMax, 4, 8, 180, 180, m_Players);
}

void Player::ReleaseTexture()
{
	for (int i = 0; i < m_PlayerMax; i++)
	{
		DeleteGraph(m_Players[i]);
	}
}

void Player::AdjustToMapChipEdgePosition(EdgeType contact_edge_, int contact_pos_)
{
	switch (contact_edge_)
	{
	case Top:
		m_PosY = contact_pos_;
		m_IsFloatingAir = false;
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

bool Player::CheckHit(int x, int y, int Width, int Height)
{
	if ((m_PosX > x && m_PosX < Width) ||
		(m_PosY > y && m_PosY < Height) ||
		(m_PosX + 120 > x && m_PosX + 120 < Width) ||
		(m_PosY + 180 > x && m_PosY + 180 < Height))
	{
		return true;
	}
	else
	{
		return false;
	}
}
