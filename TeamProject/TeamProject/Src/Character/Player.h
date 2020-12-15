#ifndef PLAYER_H
#define PLAYER_H

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
	void Draw();

public:
	bool CheckHit(int x,int y,int Width,int Height);

public:
	//�X�e�[�^�X
	int m_Hp;
	int m_Attack;
	int m_Speed;
	int m_Jump;

	//Player���W
	int m_PosX;
	int m_PosY;

	int* m_pPosX;

	// �Ǘ��ϐ�
	int m_RightMotionMAX;
	int m_count;
	int m_MotionCooltime;

	// ���s�m�F
	bool m_StopExec;
	bool m_JumpExec;
	bool m_WalkExec;
	bool m_AttackExec;
	bool m_Instraction;

	// �摜�ۑ�
	int m_StopGraph;
	int m_WalkGraph;
	int m_AttackGraph;
	int m_JumpGraph;
	int m_RightMotion[];
};

#endif // !PLAYER_H
