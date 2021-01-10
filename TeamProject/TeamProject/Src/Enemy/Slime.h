#ifndef SLIME_H
#define SLIME_H

#include"EnemyBase.h"
#include "../Function/Camera.h"
#include"../Scene/InGameScene.h"

class Slime : public EnemyBase
{
public:
	Slime();
	virtual~Slime();

	virtual void Exec(int x_,int y_,int number);
	virtual void Draw(Camera camera,int number);

	void InitTexture();
	void ReleaseTexture();
	void GetSlimeArray(int arrayX_[],int arrayY_[]);
	bool CheckHit(int x_, int y_,int number);
	
	static const int m_SlimeMax = 10;
	static const int m_MotionMax = 3;
	static const int m_NumberMax = 50;

	bool m_Hit[m_NumberMax];
	bool m_IsRight[m_NumberMax];
	bool m_IsAlive[m_NumberMax];
	bool m_IsAttack[m_NumberMax];
	int m_Back[m_NumberMax];
	int m_KnockBack[m_NumberMax];
	int m_ActSpeed;
	int m_PosX[m_NumberMax];
	int m_PosY[m_NumberMax];
	int m_Slime[m_NumberMax];
	int m_Slimes[m_SlimeMax];
	int m_MoveTime[m_NumberMax];
	int m_ActIndex[m_NumberMax];
	int m_ActWait [m_NumberMax];
	int m_AttIndex[m_NumberMax];
	int m_AttMotionL[2] = {0,3};
	int m_AttMotionR[2] = {4,7};
	int m_ActMotionL[m_MotionMax] = { 0,1,2 };
	int m_ActMotionR[m_MotionMax] = { 4,5,6 };

};

#endif // !SLIME_H

