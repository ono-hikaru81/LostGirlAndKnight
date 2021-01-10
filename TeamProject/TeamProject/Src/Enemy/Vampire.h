#ifndef VAMPIRE_H
#define VAMPIRE_H

#include"EnemyBase.h"
#include "../Function/Camera.h"

class Vampire : public EnemyBase
{
public:
	Vampire();
	virtual ~Vampire();

	virtual void Exec(int x_,int y_);
	virtual void Draw(Camera camera, int x_, int y_);
	void InitTexture();
	void ReleaseTexture();

	bool CheckHit(int x_,int y_);

	int m_Vampire;
	int m_Posx;
	int m_Posy;
	int m_MoveTime;
	int m_ActIndex;
	int m_ActWait;
	int m_ActSpeed;
	int m_AttIndex;
	int m_KnockBack;
	int m_Back;
	bool m_IsAttack;
	bool m_Hit;
	bool m_IsAlive;
	bool m_IsRight;
	static const int m_MotionMax = 2;
	static const int m_VampireMax = 12;
	int m_Vampires[m_VampireMax];
	int m_ActMotionL[m_MotionMax] = { 1,2 };
	int m_ActMotionR[m_MotionMax] = { 6,7 };
	int m_AttMotionL[m_MotionMax] = { 3,4 };
	int m_AttMotionR[m_MotionMax] = { 8,9 };
};

#endif // !VAMPIRE_H

