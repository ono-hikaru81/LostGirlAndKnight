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
	float m_PlayerPosx;	//Player���W(��l)
	float m_PlayerPosy;
	int m_HP;			//��������
	float m_Gravity;
	float m_Jump;
	bool m_Jump_exec;
};

#endif // !PLAYER_H
