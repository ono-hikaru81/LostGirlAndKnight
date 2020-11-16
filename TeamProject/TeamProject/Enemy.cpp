#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
}

void Enemy::Draw()
{
	m_slime = LoadGraph("Res/Enemy/slime.png");
	m_skull = LoadGraph("Res/Enemy/skull.png");
	m_orc = LoadGraph("Res/Enemy/orc.png");

//	LoadGraphScreen(0, 0, "Res/Enemy/slime.png", TRUE);

	DrawRotaGraph(200, 200, 0.1, 0.0, m_slime,TRUE);
	DrawRotaGraph(300, 200, 0.15, 0.0, m_skull,TRUE);
	DrawRotaGraph(400, 200, 0.3, 0.0, m_orc,TRUE);
}

bool Enemy::CheckHit(float x, float y, float width, float height)
{
	/*if ()
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
}
