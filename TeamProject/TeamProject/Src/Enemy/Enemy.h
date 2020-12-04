#ifndef ENEMY_H
#define EMEMY_H

// ===============
// エネミークラス
// ===============
class Enemy
{
public:
	// 
	int m_SlimeMax = 0;

	// 位置座標
	int m_PosX;
	int m_PosY;

	// 画像保存
	int m_SlimeGraph;
	int m_SkullGraph;
	int m_OrcGraph;

	// 生きてる？
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
