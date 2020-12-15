#ifndef WOLFMAN_H
#define WOLFMAN_H

#include"EnemyBase.h"

class Wolfman : public EnemyBase
{
public:
	Wolfman();
	virtual ~Wolfman();

	virtual void Exec();
	virtual void Draw();

	bool CheckHit(float x, float y, float width, float height);

	int m_Wolfman;
	int m_Posx;
	int m_Posy;
	int m_MoveTime;
	int m_ActIndex;
	int m_ActWait;
	int m_ActSpeed;
	static const int m_MotionMax = 4;
	static const int m_WolfmanMax = 12;
	int m_Wolfmans[m_WolfmanMax];
	int  m_ActMotionL[m_MotionMax] = { 1,0,2,0 };
	int  m_ActMotionR[m_MotionMax] = { 6,5,7,5 };
};
#endif // !WOLFMAN_H
