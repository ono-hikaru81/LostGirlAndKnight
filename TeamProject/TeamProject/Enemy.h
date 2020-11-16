#ifndef ENEMY_H
#define EMEMY_H

#include "Base.h"

// ===============
// エネミークラス
// ===============
class Enemy:public Base
{
public:
	Enemy();
	virtual ~Enemy();

public:
	void Move();
	void Draw();

public:
	bool CheckHit(float x, float y, float width, float height);

private:
	int m_slime;
	int m_skull;
	int m_orc;

private:
	float hp;
	float pow;
	float m_speed;
	float m_gravity;
	
};

#endif // !ENEMY_H
