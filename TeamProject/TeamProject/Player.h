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
	float P_Posx;	//Player座標(一人)
	float P_Posy;
	int HP;			//多分いる
	float Gravity;
};

#endif // !PLAYER_H
