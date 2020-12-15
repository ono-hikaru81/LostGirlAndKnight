#ifndef PLAYER_H
#define PLAYER_H

// =================
// プレイヤークラス
// =================
class Player
{
public:
	Player();
	virtual ~Player();

public:
	void Move();
	void Draw();

public:
	bool CheckHit(int x,int y,int Width,int Height);

public:
	//ステータス
	int m_Hp;
	int m_Attack;
	int m_Speed;
	int m_Jump;

	//Player座標
	int m_PosX;
	int m_PosY;

	int* m_pPosX;

	// 管理変数
	int m_RightMotionMAX;
	int m_count;
	int m_MotionCooltime;

	// 実行確認
	bool m_StopExec;
	bool m_JumpExec;
	bool m_WalkExec;
	bool m_AttackExec;
	bool m_Instraction;

	// 画像保存
	int m_StopGraph;
	int m_WalkGraph;
	int m_AttackGraph;
	int m_JumpGraph;
	int m_RightMotion[];
};

#endif // !PLAYER_H
