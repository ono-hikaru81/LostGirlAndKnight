#ifndef SKULL_H
#define SKULL_H

#include "EnemyBase.h"
#include "../Function/Camera.h"

class Skull : public EnemyBase
{
public:
	Skull();
	virtual ~Skull();

	virtual void Exec(int x_,int y_,int number);
	virtual void Draw(Camera camera,int number);
	void InitTexture();
	void ReleaseTexture();
	void GetSkullArray(int arrayX_[], int arrayY_[]);
	bool CheckHit(int x_,int y_ ,int number);

	static const int m_MotionMax = 2;
	static const int m_SkullMax = 12;
	static const int m_NumberMax = 50;

	bool m_Hit[m_NumberMax];
	bool m_IsRight[m_NumberMax];
	bool m_IsAlive[m_NumberMax];
	bool m_IsAttack[m_NumberMax];

	int m_ActSpeed;
	int m_Skull[m_NumberMax];
	int m_PosX[m_NumberMax];
	int m_PosY[m_NumberMax];
	int m_MoveTime[m_NumberMax];
	int m_ActIndex[m_NumberMax];
	int m_AttIndex[m_NumberMax];
	int m_ActWait[m_NumberMax];
	int m_Back[m_NumberMax];
	int m_KnockBack[m_NumberMax];
	int m_Skulls[m_SkullMax];
	int m_ActMotionL[m_MotionMax] = { 1,2 };
	int m_ActMotionR[m_MotionMax] = { 6,7 };
	int m_AttMotionL[m_MotionMax] = { 3,4 };
	int m_AttMotionR[m_MotionMax] = { 8,9 };

};
#endif // !SKULL_H
