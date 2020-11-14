#ifndef PLAYER_H
#define PLAYER_H

#include "Base.h"

// =================
// プレイヤークラス
// =================
class Player:public Base
{
public:
	Player();
	virtual ~Player();

public:
	void Move();
	void Draw();

public:
	bool CheckHit();
};

#endif // !PLAYER_H
