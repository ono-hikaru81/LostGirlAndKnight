#ifndef PLAYER_H
#define PLAYER_H

#include "../Function/Camera.h"
#include "../Stage/Map.h"

// =================
// プレイヤークラス
// =================
class Player
{
public:
	Player();
	virtual ~Player();

public:
	int GetPosX();
	int GetPosY();
	int GetCenterPosX();
	int GetCenterPosY();
	void Move();
	void Draw(Camera camera);
	void InitTexture();
	void ReleaseTexture();
	void AdjustToMapChipEdgePosition(EdgeType contact_edge_, int contact_pos_);

public:
	bool CheckHit(int x, int y, int Width, int Height);

public:
	//ステータス
	int m_Hp;
	int m_Attack;
	int m_Speed;
	int m_JumpVelocity;

	//Player座標
	int m_PosX;
	int m_PosY;
	int m_PrevPosX;
	int m_PrevPosY;
	int m_CenterPosX;
	int m_CenterPosY;

	// 管理変数
	int m_Player;
	int m_m_Time;
	int m_MotionCooltime;
	int m_ActStop;
	int m_ActSpeed;
	int m_WaitIndex;
	int m_ActIndex;
	int m_AttIndex;
	int m_DeiIndex;

	//--各Motionの最大値--
	static const int m_AttMotionMax = 7;
	static const int m_MotionMax = 4;
	static const int m_DeiMotionMax = 3;
	static const int m_PlayerMax = 32;
	static const int m_JumpMotionMax = 1;

	//----左向き---
	int m_WaiMotionL[m_MotionMax] = { 0, 1, 0, 2 };
	int m_WlkMotionL[m_MotionMax] = { 3, 5, 4, 5 };
	int m_AttMotionL[m_AttMotionMax] = { 7, 8, 9,10,11,10, 9 };
	int m_DeiMotionL[m_DeiMotionMax] = { 13,14,15 };

	//----右向き---
	int m_WaiMotionR[m_MotionMax] = { 16,17,16,18 };
	int m_WlkMotionR[m_MotionMax] = { 19,21,20,21 };
	int m_AttMotionR[m_AttMotionMax] = { 23,24,25,26,27,26,25 };
	int m_DeiMotionR[m_DeiMotionMax] = { 29,30,31 };

	// 実行確認
	bool m_IsMove;
	bool m_IsRight;
	bool m_IsFloatingAir;

	// 画像保存
	int m_Players[m_PlayerMax];
};

#endif // !PLAYER_H
