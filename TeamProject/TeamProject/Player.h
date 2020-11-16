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
	float P_Posx;	//Player���W(��l)
	float P_Posy;
	int HP;			//��������
	const float Gravity = 9.8f;
	float Jump;
	bool Jump_exec;
	float Clone_Jump;
};

#endif // !PLAYER_H
