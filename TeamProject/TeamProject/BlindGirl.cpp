#include "DxLib.h"
#include "BlindGirl.h"
#include <time.h>

Girl::Girl()
{
	m_wait = 0;
	m_walk = 0;
	m_jamp = 0;
	m_timer = 0.0f;	
	m_girlposx = 100.0f;
	m_girlposy = 450.0f;
	m_speed = 4.0f;
	m_gravity = 0.0f;
	m_waiting = false;
	m_walking = false;
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
		m_walking = true;

		if (CheckHitKey(KEY_INPUT_UP) && m_girlposy >= 450.0f)
		{
			m_gravity = -5.0f;
			m_floating = true;
		}
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) && m_girlposx <= 625.0f)
	{
		m_girlposx += m_speed;
		m_walking = true;

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
	else
	{
		m_waiting = true;
	}
}

void Girl::Draw()
{
	m_wait = LoadGraph("Res/Girl/taikiB_R.png");
	m_walk = LoadGraph("Res/Girl/girl_walk1.png");
	m_jamp = LoadGraph("Res/Girl/junp_R_B.png");

	if (m_floating == true)
	{
		DrawRotaGraph(m_girlposx, m_girlposy, 0.3, 0.0, m_jamp, TRUE);
	}
	else if (m_walking == true)
	{
		DrawRotaGraph(m_girlposx, m_girlposy, 0.3, 0.0, m_walk, TRUE);
	}
	else if(m_waiting == true)
	{
		DrawRotaGraph(m_girlposx, m_girlposy, 0.3, 0.0, m_wait, TRUE);
	}
}
