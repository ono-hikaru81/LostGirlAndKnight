#ifndef MAP_H
#define MAP_H

#include "Main.h"

class Map
{
public:
	Map();
	~Map();

public:
	void Data();
	void Draw();

public:
	int m_PosX;
	int m_PosY;
	int Info[MaxMapHeight][MaxMapWidth];
	int Number;
	int MapChip[3];
};

enum Stage
{
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Eleven,
	Twelve
};

void DrawMap();

#endif // !MAP_H
