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
	float Gravity;
};

#endif // !PLAYER_H
