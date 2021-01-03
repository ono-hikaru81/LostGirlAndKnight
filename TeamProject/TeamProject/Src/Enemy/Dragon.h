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
	//ステータス
	int m_PosX;
	int m_PosY;
	
	//管理変数
	int m_WaitTime;
	int m_AttackTime;

	//画像保存
	static const int m_DragonMax = 4;
	int m_Dragones[m_DragonMax];
	int m_Dragon;
};
#endif // !DRAGON_H

