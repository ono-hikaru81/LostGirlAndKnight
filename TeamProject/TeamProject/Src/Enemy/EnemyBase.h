#ifndef ENEMYBASE_H
#define ENEMYBASE_H

// ===============
// �G�l�~�[�N���X
// ===============
class EnemyBase
{
public:
	// �ʒu���W
	int m_PosX;
	int m_PosY;

	// �����Ă�H
	bool m_SlimeAlive;

public:
	EnemyBase();
	virtual ~EnemyBase();

public:
	virtual void Move();
	virtual void Draw();

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
