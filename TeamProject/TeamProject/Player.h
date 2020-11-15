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

public://メンバ変数
	float P_Speed = 1.0f;	//仮数値
};

#endif // !PLAYER_H
