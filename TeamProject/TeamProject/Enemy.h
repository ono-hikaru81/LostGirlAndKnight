#ifndef ENEMY_H
#define EMEMY_H

#include "Base.h"

// ===============
// �G�l�~�[�N���X
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
	bool CheckHit();
};

#endif // !ENEMY_H
