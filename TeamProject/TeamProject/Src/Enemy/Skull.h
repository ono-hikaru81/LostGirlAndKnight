#ifndef SKULL_H
#define SKULL_H

#include "EnemyBase.h"

class Skull : public EnemyBase
{
public:
	Skull();
	virtual ~Skull();

	virtual void Exec();
	virtual void Draw();

	bool CheckHit(float x, float y, float width, float height);

	int m_Skull;
	int m_SkullPosx;
	int m_SkullPosy;
	int m_MoveTime;
	int m_WaitTime;
	static const int m_SkullMax = 12;
	int m_Skulls[m_SkullMax];

};
#endif // !SKULL_H
