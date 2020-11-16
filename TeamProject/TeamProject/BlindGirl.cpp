#include "DxLib.h"
#include "BlindGirl.h"
#include <time.h>

Girl::Girl()
{
	m_timer = 0.0f;	
	m_girlposx = 100.0f;
	m_girlposy = 450.0f;
	m_speed = 4.0f;
	m_gravity = 0.0f;
	m_floating  = false;
}

Girl::~Girl()
{
}

void Girl::Move()
{
	if (CheckHitKey(KEY_INPUT_LEFT) && m_girlposx >= 15.0f)
	{
		m_girlposx -= m_speed;

		if (CheckHitKey(KEY_INPUT_UP) && m_girlposy >= 450.0f)
		{
			m_gravity = -5.0f;
			m_floating = true;
		}
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) && m_girlposx <= 625.0f)
	{
		m_girlposx += m_speed;

		if (CheckHitKey(KEY_INPUT_UP) && m_girlposy >= 450.0f)
		{
			m_gravity = -5.0f;
			m_floating = true;
		}
	}
	else if (CheckHitKey(KEY_INPUT_UP) && m_girlposy >= 450.0f)
	{
		m_gravity = -5.0f;
		m_floating = true;
	}
	if (m_floating == true)
	{
		m_girlposy += m_gravity;
		m_gravity += 0.2f;
		if (m_girlposy >= 450.0f)
		{
			m_floating = false;
			m_gravity = 0.0f;
		}
	}
	
}

void Girl::Draw()
{
	m_walk = LoadGraph("Res/Girl/girl_walk1.png");
	DrawRotaGraph(m_girlposx, m_girlposy, 0.3, 0.0, m_walk, TRUE);
}
