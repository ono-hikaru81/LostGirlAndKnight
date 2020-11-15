#ifndef MAP_H
#define MAP_H

#include "Base.h"

class Map:public Base
{
public:
	Map();
	virtual ~Map();

public:
	void Draw();

public:
	bool CheckHit(int x, int y, int width, int height);

private:
	int m_ground;
	int m_chip[NULL];
};

void DrawMap();

#endif // !MAP_H
