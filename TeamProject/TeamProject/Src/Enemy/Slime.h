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
	int m_Posx;
	int m_Posy;
	int m_MoveTime;
	int m_ActIndex;
	int m_ActWait;
	int m_ActSpeed;
	static const int m_MotionMax = 3;
	static const int m_SlimeMax = 10;
	int m_Slimes[m_SlimeMax];
	int  m_ActMotionL[m_MotionMax] = { 0,1,2 };
	int  m_ActMotionR[m_MotionMax] = { 4,5,6 };
};

#endif // !SLIME_H

