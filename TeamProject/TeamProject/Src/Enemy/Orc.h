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

private:
	int m_Orc;
	int m_PosX;
	int m_PosY;
	int m_MoveTime;
	int m_ActIndex;
	int m_ActWait;
	int m_ActSpeed;
	static const int m_OrcMax = 12;
	static const int m_MotionMax = 4;
	int m_Orcs[m_OrcMax];
	int  m_ActMotionL[m_MotionMax] = { 1,0,2,0 };
	int  m_ActMotionR[m_MotionMax] = { 6,5,7,5 };
};

#endif // !ORC_H

