#include "DxLib.h"
#include "Map.h"
#include "../Character/Player.h"

Map::Map()
{
	InitTexture();
}

Map::~Map()
{
	ReleaseTexture();
}

void Map::Data(Stage number_)
{
	MapChip[5];

	switch (number_)
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

int Map::GetChipPos(int x_, int y_)
{
	int ChipX = x_ / MapChipWidth;
	int ChipY = y_ / MapChipHeight;

	if (ChipX >= MaxMapWidth || ChipY >= MaxMapHeight || x_ < 0 || y_ < 0) { return 0; }

	return Info[ChipY][ChipX];
}

void Map::Draw(Camera camera)
{
	int DrawPosX;
	int DrawPosY;

	for (int y = 0; y < MaxMapHeight; y++)
	{
		for (int x = 0; x < MaxMapWidth; x++)
		{
			DrawPosX = camera.ConvertPosXWorldToScreen(x * MapChipWidth);
			DrawPosY = camera.ConvertPosYWorldToScreen(y * MapChipHeight);

			DrawGraph(DrawPosX, DrawPosY, MapChip[Info[y][x]], FALSE);
		}
	}
}

void Map::InitTexture()
{
	LoadDivGraph("Res/MapChip/MapChip.png", 6, 3, 3, MapChipWidth, MapChipHeight, MapChip);
}

void Map::ReleaseTexture()
{
	for (int i = 0; i < g_MapChipNumber; i++)
	{
		DeleteGraph(MapChip[i]);
	}
}

void Map::Clamp(int* value, int min, int max)
{
	if (*value < min)
	{
		*value = min;
	}
	else if (*value > max)
	{
		*value = max;
	}
}

bool Map::CheckHit(int x_, int y_, int width_, int height_)
{
	// サイズ調整
	width_ -= 1;
	height_ -= 1;

	// 矩形のX軸範囲
	int WidthRangeIDs[]
	{
		(int)(x_ / MapChipWidth),
		(int)(width_ / MapChipWidth)
	};

	// 矩形のY軸範囲
	int HeightRangeIDs[]
	{
		(int)(y_ / MapChipHeight),
		(int)(height_ / MapChipHeight)
	};

	// 範囲最大数
	const int MaxRangeIDs[]
	{
		MaxMapHeight - 1,
		MaxMapWidth - 1,
	};

	for (int i = 0; i < 2; i++)
	{
		Clamp(&HeightRangeIDs[i], 0, MaxMapHeight - 1);
		Clamp(&WidthRangeIDs[i], 0, MaxMapWidth - 1);
	}

	const int start = 0;
	const int end = 1;

	for (int i = HeightRangeIDs[start]; i <= HeightRangeIDs[end]; i++)
	{
		for (int j = WidthRangeIDs[start]; j <= WidthRangeIDs[end]; j++)
		{
			if (Info[i][j] == 0)
			{
				// 当たり
				return true;
			}
		}
	}

	// 当たってない
	return false;
}
