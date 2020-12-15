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
	int m_Posx;
	int m_Posy;
	int m_MoveTime;
	int m_ActIndex;
	int m_ActWait;
	int m_ActSpeed;
	static const int m_MotionMax = 4;
	static const int m_VampireMax = 12;
	int m_Vampires[m_VampireMax];
	int  m_ActMotionL[m_MotionMax] = { 1,0,2,0 };
	int  m_ActMotionR[m_MotionMax] = { 6,5,7,5 };
};

#endif // !VAMPIRE_H

