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
	bool CheckHit();

public://�����o�ϐ�
	int m_HP;			//��������
	int m_stop;			//�~�܂�
	int m_walk;			//����
	int m_attack;		//�U��
	int m_Jump;			//�W�����v
	float m_PlayerPosx;	//Player���W(��l)
	float m_PlayerPosy;
	float m_Gravity;
	bool m_Jump_exec;
	bool m_stop_exec;
	bool m_walk_exec;
	bool m_attacl_exec;
};

#endif // !PLAYER_H
