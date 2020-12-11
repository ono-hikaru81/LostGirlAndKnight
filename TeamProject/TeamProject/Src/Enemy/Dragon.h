#ifndef DRAGON_H
#define DRAGON_H

#include"EnemyBase.h"

class Dragon :public EnemyBase
{
public:
	Dragon();
	virtual ~Dragon();

	virtual void Exec();
	virtual void Draw();
};
#endif // !DRAGON_H

