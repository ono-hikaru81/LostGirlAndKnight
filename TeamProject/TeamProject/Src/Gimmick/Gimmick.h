
#ifndef GIMMICK_H
#define GIMMICK_H

class Gimmick
{
public:
	int m_BridgeDraw;		//�؂̉摜�ۑ�
	float m_Angle;
	float m_Radian;
	bool m_BridgeExec;

	int m_Trap;
	static const int m_TrapMax = 3;
	int m_Traps[m_TrapMax];			//�g���b�v�̉摜�ۑ�
	int m_TrapMotion[m_TrapMax] = {0,1,2};	//�g���b�v�̃A�j���[�V����
	bool m_TrapExec;

	int m_Botton;
	static const int m_BottonMax = 2;
	int m_Bottons[m_BottonMax];	//�{�^���̉摜�ۑ�
	bool m_BottonExec;

	int m_Rock;
	static const int m_RockMax = 3;
	int m_Rocks[m_RockMax];
	int m_Hitm_Time;
	


public:
	Gimmick();
	~Gimmick();

public:
	void BridgeMove();
	void BridgeDraw();

	void BottonMove();
	void BottonDraw();//�ŏI�I��bool CheckHit()�Ɉڍs

	void TrapMove();
	void TrapDraw();//�ŏI�I��bool CheckHit()�Ɉڍs

	void RockMove();
	void RockDraw();

public:
	bool CheckHit();
};



#endif // !GIMMICK_H
