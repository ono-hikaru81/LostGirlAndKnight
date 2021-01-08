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
	virtual void Draw(Camera camera ,int x_[] ,int y_[],int number);

	void InitTexture();
	void ReleaseTexture();
	void GetSlimeArray(int array_[]);
	bool CheckHit(float x, float y,int number);
	
	static const int m_SlimeNumberMax = 50;
	int m_PosX[m_SlimeNumberMax];
	int m_PosY[m_SlimeNumberMax];
	int m_Slime[m_SlimeNumberMax];
	int m_MoveTime[m_SlimeNumberMax];
	int m_ActIndex[m_SlimeNumberMax];
	int m_ActWait [m_SlimeNumberMax];
	int m_ActSpeed;
	static const int m_MotionMax = 3;
	static const int m_SlimeMax = 10;
	int m_Slimes[m_SlimeMax];
	int  m_ActMotionL[m_MotionMax] = { 0,1,2 };
	int  m_ActMotionR[m_MotionMax] = { 4,5,6 };

};

#endif // !SLIME_H

