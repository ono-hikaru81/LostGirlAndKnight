#ifndef ENEMY_H
#define EMEMY_H

// ===============
// �G�l�~�[�N���X
// ===============
class Enemy
{
public:
	// 
	int m_SlimeMax = 0;

	// �ʒu���W
	int m_PosX;
	int m_PosY;

	// �摜�ۑ�
	int m_SlimeGraph;
	int m_SkullGraph;
	int m_OrcGraph;

	// �����Ă�H
	bool m_SlimeAlive;
	

public:
	Enemy();
	virtual ~Enemy();

public:
	void Move();
	void Draw();

public:
	bool CheckHit(float x, float y, float width, float height);	
};

struct EnemyType
{
	int m_Slime;
	int m_Skull;
	int m_Orc;
	int m_Werewolf;
	int m_Vampire;
	int m_Doragon;
};

#endif // !ENEMY_H
