#ifndef SKULL_H
#define SKULL_H

#include "EnemyBase.h"
#include "../Function/Camera.h"

class Skull : public EnemyBase
{
public:
	Skull();
	virtual ~Skull();

	virtual void Exec();
	virtual void Draw(Camera camera, int x_[], int y_[],int number);
	void InitTexture();
	void ReleaseTexture();

	bool CheckHit(float x, float y, float width, float height);

	int m_Skull;
	int m_Posx;
	int m_Posy;
	int m_MoveTime;
	int m_ActIndex;
	int m_ActWait;
	int m_ActSpeed;
	static const int m_MotionMax = 2;
	static const int m_SkullMax = 12;
	int m_Skulls[m_SkullMax];
	int m_ActMotionL[m_MotionMax] = { 1,2 };
	int m_ActMotionR[m_MotionMax] = { 6,7 };
	int m_AttMotionL[m_MotionMax] = { 3,4 };
	int m_AttMotionR[m_MotionMax] = { 8,9 };

};
#endif // !SKULL_H
