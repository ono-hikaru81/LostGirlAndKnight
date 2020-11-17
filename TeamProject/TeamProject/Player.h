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
	float m_PlayerPosx;	//Player座標(一人)
	float m_PlayerPosy;
	int m_HP;			//多分いる
	float m_Gravity;
	float m_Jump;
	bool m_Jump_exec;
};

#endif // !PLAYER_H
