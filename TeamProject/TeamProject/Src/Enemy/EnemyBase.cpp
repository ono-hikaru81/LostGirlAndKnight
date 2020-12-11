#include "DxLib.h"
#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
	
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Move()
{
}

void EnemyBase::Draw()
{
	
}

bool EnemyBase::CheckHit(float x, float y, float width, float height)
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
