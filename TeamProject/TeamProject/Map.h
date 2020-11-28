#ifndef MAP_H
#define MAP_H

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
	int MaxWidth;
	int MaxHeight;
	int MapChip[][];
};

void DrawMap();

#endif // !MAP_H
