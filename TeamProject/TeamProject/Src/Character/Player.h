#ifndef PLAYER_H
#define PLAYER_H

#include "../Function/Camera.h"

// =================
// �v���C���[�N���X
// =================
class Player
{
public:
	Player();
	virtual ~Player();

public:
	void Move();
	void InitTexture();
	void Draw(Camera camera);
	void ReleaseTexture();

public:
	bool CheckHit(int x, int y, int Width, int Height);

public:
	//�X�e�[�^�X
	int m_Hp;
	int m_Attack;
	int m_Speed;
	int m_Jump;

	//Player���W
	int m_PosX;
	int m_PosY;

	// �Ǘ��ϐ�
	int m_Player;
	int m_count;
	int m_MotionCooltime;
	int m_ActStop;
	int m_ActSpeed;
	int m_WaitIndex;
	int m_ActIndex;
	int m_AttIndex;
	int m_DeiIndex;

	//--�eMotion�̍ő�l--
	static const int m_AttMotionMax = 7;
	static const int m_MotionMax = 4;
	static const int m_DeiMotionMax = 3;
	static const int m_PlayerMax = 32;
	//----������---
	int m_WaiMotionL[m_MotionMax] = { 0, 1, 2, 1 };
	int m_WlkMotionL[m_MotionMax] = { 3, 5, 4, 5 };
	int m_AttMotionL[m_AttMotionMax] = { 7, 8, 9,10,11,10, 9 };
	int m_DeiMotionL[m_DeiMotionMax] = { 13,14,15 };
	//----�E����---
	int m_WaiMotionR[m_MotionMax] = { 16,17,16,18 };
	int m_WlkMotionR[m_MotionMax] = { 19,21,20,21 };
	int m_AttMotionR[m_AttMotionMax] = { 23,24,25,26,27,26,25 };
	int m_DeiMotionR[m_DeiMotionMax] = { 29,30,31 };

	// ���s�m�F
	bool m_JumpExec;
	bool m_DeiExec;
	bool m_IsRight;

	// �摜�ۑ�
	int m_DrawPlayer;
	int m_Players[m_PlayerMax];
};

#endif // !PLAYER_H
