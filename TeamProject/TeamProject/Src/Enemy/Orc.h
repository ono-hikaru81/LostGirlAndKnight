#ifndef ORC_H
#define ORC_H

#include"EnemyBase.h"
#include "../Character/Player.h"
#include "../Function/Camera.h"

class Orc : public EnemyBase
{
public:
	Orc();
	virtual ~Orc();

	void InitTexture();
	void ReleaseTexture();
	virtual void Exec(Player player);
	virtual void Draw(Camera camera, int x_, int y_);

	bool CheckHit(float x, float y, float width, float height);

private:
	int m_Orc;
	int m_PosX;
	int m_PosY;
	int m_MoveTime;
	int m_ActIndex;
	int m_ActWait;
	int m_ActSpeed;
	int m_AttIndex;
	static const int m_OrcMax = 12;
	static const int m_MotionMax = 4;
	static const int m_AttackMax = 2;
	int m_Orcs[m_OrcMax];
	int m_ActMotionL[m_MotionMax] = { 1,0,2,0 };
	int m_ActMotionR[m_MotionMax] = { 6,5,7,5 };
	int m_AttMotionL[m_AttackMax] = { 3,4 };
	int m_AttMotionR[m_AttackMax] = { 8,9 };
	
};

#endif // !ORC_H

