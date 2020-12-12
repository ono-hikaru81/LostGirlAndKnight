#ifndef VAMPIRE_H
#define VAMPIRE_H

#include"EnemyBase.h"

class Vampire : public EnemyBase
{
public:
	Vampire();
	virtual ~Vampire();

	virtual void Exec();
	virtual void Draw();

	bool CheckHit(float x, float y, float width, float height);

	int m_Vampire;
	int m_VampirePosx;
	int m_VampirePosy;
	int m_MoveTime;
	int m_WaitTime;
	static const int m_VampireMax = 12;
	int m_Vampires[m_VampireMax];
};

#endif // !VAMPIRE_H

