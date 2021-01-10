#ifndef ORC_H
#define ORC_H

#include"EnemyBase.h"
#include "../Character/Player.h"
#include "../Function/Camera.h"
#include"../Scene/InGameScene.h"

class Orc : public EnemyBase
{
public:
	Orc();
	virtual ~Orc();

	virtual void Exec(int x_,int y_,int number);
	virtual void Draw(Camera camera,int number);

	void InitTexture();
	void ReleaseTexture();
	void GetOrcArray(int arrayX_[],int arrayY_[]);
	bool CheckHit(int x_, int y_, int number);

private:
	static const int m_OrcMax = 12;
	static const int m_MotionMax = 4;
	static const int m_AttackMax = 2;
	static const int m_NumberMax = 50;

	bool m_Hit[m_NumberMax];
	bool m_IsRight[m_NumberMax];
	bool m_IsAlive[m_NumberMax];
	bool m_IsAttack[m_NumberMax];
	int m_PosX[m_NumberMax];
	int m_PosY[m_NumberMax];
	int m_MoveTime[m_NumberMax];
	int m_ActIndex[m_NumberMax];
	int m_ActWait[m_NumberMax];
	int m_ActSpeed;
	int m_AttIndex[m_NumberMax];
	int m_Back[m_NumberMax];
	int m_KnockBack[m_NumberMax];
	int m_Orc[m_NumberMax];
	int m_Orcs[m_OrcMax];
	int m_ActMotionL[m_MotionMax] = { 1,0,2,0 };
	int m_ActMotionR[m_MotionMax] = { 6,5,7,5 };
	int m_AttMotionL[m_AttackMax] = { 3,4 };
	int m_AttMotionR[m_AttackMax] = { 8,9 };
	
};

#endif // !ORC_H

