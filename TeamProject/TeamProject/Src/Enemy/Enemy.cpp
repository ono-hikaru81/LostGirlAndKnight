#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy()
{
	m_SlimeGraph = NULL;
	m_SkullGraph = NULL;
	m_OrcGraph = NULL;
	m_PosX = 1360;
	m_PosY = 540;
	m_SlimeAlive = true;
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
}

void Enemy::Draw()
{
	m_SlimeGraph = LoadGraph("Res/Enemy/slime.png");
	m_SkullGraph = LoadGraph("Res/Enemy/skull.png");
	m_OrcGraph   = LoadGraph("Res/Enemy/orc.png");

	DrawGraph(m_PosX, m_PosY, m_SlimeGraph,TRUE);
}

bool Enemy::CheckHit(float x, float y, float width, float height)
{
	if ((m_PosX >= x && m_PosX <= width) && (m_PosY >= y && m_PosY <= height) ||
		(m_PosX + 120 >= x && m_PosX + 120 <= width) && (m_PosY + 180 >= y && m_PosY + 180 <= height))
	{
		return true;
	}
	else
	{
		return false;
	}
}
