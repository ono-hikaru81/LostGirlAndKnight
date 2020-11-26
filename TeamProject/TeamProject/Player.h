#ifndef PLAYER_H
#define PLAYER_H

#include "Base.h"

// =================
// �v���C���[�N���X
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

public://�����o�ϐ�
	int m_HP;			//��������
	int m_stop;			//�~�܂�
	int m_walk;			//����
	int m_attack;		//�U��
	int m_Jump;			//�W�����v
	int m_RightMotionMAX;
	int m_count;
	int m_MotionCooltime;
	float m_PlayerPosx;	//Player���W(��l)
	float m_PlayerPosy;
	float m_Gravity;
	bool m_jump_exec;	//�W�����v��
	bool m_stop_exec;	//�~�܂钆
	bool m_walk_exec;	//������
	bool m_attacl_exec;	//�U����
	int m_RightMotion[];
};

#endif // !PLAYER_H
