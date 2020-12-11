#ifndef ORC_H
#define ORC_H

#include"EnemyBase.h"

class Orc : public EnemyBase
{
public:
	Orc();
	virtual ~Orc();

	virtual void Exec();
	virtual void Draw();

	bool CheckHit(float x, float y, float width, float height);

	int m_Orc;
	int m_OrcPosx;
	int m_OrcPosy;
	int m_MoveTime;
	int m_WaitTime;
	static const int m_OrcMax = 12;
	int m_Orcs[m_OrcMax];


};

#endif // !ORC_H

