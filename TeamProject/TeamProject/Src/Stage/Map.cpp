#include "DxLib.h"
#include "Map.h"
#include "../Character/Player.h"

Map::Map()
{
	Number = Stage::One;
}

Map::~Map()
{
}

void Map::Data()
{
	MapChip[2];

	LoadDivGraph("Res/MapChip/MapChip.png", 3, 3, 1, MapChipWidth, MapChipHeight, MapChip);

	switch (Number)
	{
	case Stage::One:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info1[y][x];
			}
		}

		break;
	case Stage::Two:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info2[y][x];
			}
		}

		break;
	case Stage::Three:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info3[y][x];
			}
		}

		break;
	case Stage::Four:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info4[y][x];
			}
		}

		break;
	case Stage::Five:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info5[y][x];
			}
		}

		break;
	case Stage::Six:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info6[y][x];
			}
		}

		break;
	case Stage::Seven:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info7[y][x];
			}
		}

		break;
	case Stage::Eight:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info8[y][x];
			}
		}

		break;
	case Stage::Nine:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info9[y][x];
			}
		}

		break;
	case Stage::Ten:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info10[y][x];
			}
		}

		break;
	case Stage::Eleven:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info11[y][x];
			}
		}

		break;
	case Stage::Twelve:
		
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info12[y][x];
			}
		}

		break;
	};
}

void Map::Draw()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			DrawGraph(x * MapChipWidth, y * MapChipHeight, MapChip[Info[y][x]], FALSE);
		}
	}
}

void DrawMap()
{
	int MapChip[3];

	LoadDivGraph("Res/MapChip/MapChip.png", 3, 3, 1, MapChipWidth, MapChipHeight, MapChip);
	char TestMap[9][60] =
	{
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			DrawGraph(x * MapChipWidth, y * MapChipHeight, MapChip[TestMap[y][x]], FALSE);
		}
	}
}