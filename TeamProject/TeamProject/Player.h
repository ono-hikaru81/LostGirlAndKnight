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
	bool CheckHit(int x,int y,int Width,int Height);

public://メンバ変数
	int m_HP;			//多分いる
	int m_stop;			//止まる
	int m_walk;			//歩く
	int m_attack;		//攻撃
	int m_Jump;			//ジャンプ
	int m_RightMotionMAX;
	int m_count;
	int m_MotionCooltime;
	float m_PlayerPosx;	//Player座標(一人)
	float m_PlayerPosy;
	float m_Gravity;
	bool m_jump_exec;	//ジャンプ中
	bool m_stop_exec;	//止まる中
	bool m_walk_exec;	//歩く中
	bool m_attacl_exec;	//攻撃中
	int m_RightMotion[];
};

#endif // !PLAYER_H
