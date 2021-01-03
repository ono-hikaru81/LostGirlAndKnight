#ifndef DRAGON_H
#define DRAGON_H

#include"EnemyBase.h"

class Dragon :public EnemyBase
{
public:
	Dragon();
	virtual ~Dragon();
	void InitTexture();

	virtual void Exec();
	virtual void Draw();

private:
	//�X�e�[�^�X
	int m_PosX;
	int m_PosY;
	
	//�Ǘ��ϐ�
	int m_WaitTime;
	int m_AttackTime;

	//�摜�ۑ�
	static const int m_DragonMax = 4;
	int m_Dragones[m_DragonMax];
	int m_Dragon;
};
#endif // !DRAGON_H

