#ifndef SLIME_H
#define SLIME_H

#include"EnemyBase.h"

class Slime : public EnemyBase
{
public:
	Slime();
	virtual~Slime();

	virtual void Exec();
	virtual void Draw();

	bool CheckHit(float x, float y, float width, float height);

	int m_Slime;
	int m_SlimePosx;
	int m_SlimePosy;
	int m_MoveTime;
	int m_WaitTime;
	static const int m_SlimeMax = 12;
	int m_Slimes[m_SlimeMax];
};

#endif // !SLIME_H

