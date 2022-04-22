#ifndef ENEMYBASE_H
#define ENEMYBASE_H

// ===============
// エネミークラス
// ===============
class EnemyBase
{
public:
	// 位置座標
	int m_PosX;
	int m_PosY;

	// 生きてる？
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
