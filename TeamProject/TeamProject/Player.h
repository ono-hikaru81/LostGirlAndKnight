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
	int m_HP;			//多分いる
	int m_stop;			//止まる
	int m_walk;			//歩く
	int m_attack;		//攻撃
	int m_Jump;			//ジャンプ
	float m_PlayerPosx;	//Player座標(一人)
	float m_PlayerPosy;
	float m_Gravity;
	bool m_Jump_exec;
	bool m_stop_exec;
	bool m_walk_exec;
	bool m_attacl_exec;
};

#endif // !PLAYER_H
