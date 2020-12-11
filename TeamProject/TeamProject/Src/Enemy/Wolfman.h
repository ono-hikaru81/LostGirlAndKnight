#ifndef WOLFMAN_H
#define WOLFMAN_H

#include"EnemyBase.h"

class Wolfman : public EnemyBase
{
	Wolfman();
	virtual ~Wolfman();

	virtual void Exec();
	virtual void Draw();

	bool CheckHit(float x, float y, float width, float height);

	int m_Wolfman;
	int m_WolfmanPosx;
	int m_WolfmanPosy;
	int m_MoveTime;
	int m_WaitTime;
	static const int m_WolfmanMax = 12;
	int m_Wolfmans[m_WolfmanMax];
};
#endif // !WOLFMAN_H
