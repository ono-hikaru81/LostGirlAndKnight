#ifndef DRAGON_H
#define DRAGON_H

#include"EnemyBase.h"
#include "../Function/Camera.h"

class Dragon :public EnemyBase
{
public:
	Dragon();
	virtual ~Dragon();

	void ReleaseTexture();
	void InitTexture();
	virtual void Exec();
	virtual void Draw(Camera camera, int x_, int y_);

private:
	//ステータス
	int m_PosX;
	int m_PosY;
	
	//管理変数
	int m_WaitTime;
	int m_AttackTime;
	bool m_IsAttack;
	//画像保存
	static const int m_DragonMax = 4;
	int m_Dragones[m_DragonMax];
	int m_Dragon;
	int m_Fire;
};
#endif // !DRAGON_H

