#include "DxLib.h"
#include "Map.h"
#include "../Character/Player.h"

Map::Map()
{
	Speed = 0;
}

Map::~Map()
{
}

void Map::Data(Stage number_)
{
	MapChip[5];
	LoadDivGraph("Res/MapChip/MapChip.png", 6, 3, 3, MapChipWidth, MapChipHeight, MapChip);

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

void Map::ConvertPos()
{
	for (int x = 0; x <= 60; x++)
	{
		for (int y = 0; y <= 9; y++)
		{
			m_PosX = x * 120;
			m_PosY = y * 120;

			int SizeX = m_PosX / 120;
			int SizeY = m_PosY / 120;

			Info[SizeY][SizeX];
		}
	}
}

void Map::Draw()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			DrawGraph(x * MapChipWidth - Speed, y * MapChipHeight, MapChip[Info[y][x]], FALSE);
		}
	}
}

bool Map::CheckHit(int x_, int y_, int width_, int height_)
{
	if ((m_PosX >= x_ && m_PosX <= width_) && (m_PosY >= y_ && m_PosY <= height_) ||
		(m_PosX + 120 >= x_ && m_PosX + 120 <= width_) && (m_PosY + 120 >= y_ && m_PosY + 120 <= height_))
	{
		return true;
	}
	else
	{
		return false;
	}
}
