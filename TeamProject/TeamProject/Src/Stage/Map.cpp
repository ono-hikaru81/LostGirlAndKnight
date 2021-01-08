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

void Map::Data(StageID number_)
{
	MapChip[5];

	switch (number_)
	{
	case StageID::StageID_1:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info1[y][x];
			}
		}

		break;
	case StageID::StageID_2:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info2[y][x];
			}
		}

		break;
	case StageID::StageID_3:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info3[y][x];
			}
		}

		break;
	case StageID::StageID_4:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info4[y][x];
			}
		}

		break;
	case StageID::StageID_5:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info5[y][x];
			}
		}

		break;
	case StageID::StageID_6:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info6[y][x];
			}
		}

		break;
	case StageID::StageID_7:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info7[y][x];
			}
		}

		break;
	case StageID::StageID_8:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info8[y][x];
			}
		}

		break;
	case StageID::StageID_9:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info9[y][x];
			}
		}

		break;
	case StageID::StageID_10:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info10[y][x];
			}
		}

		break;
	case StageID::StageID_11:

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 60; x++)
			{
				Info[y][x] = Info11[y][x];
			}
		}

		break;
	case StageID::StageID_12:

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

void Map::Draw(Camera camera)
{
	for (int y = 0; y < MaxMapHeight; y++)
	{
		for (int x = 0; x < MaxMapWidth; x++)
		{
			if (MapChip[Info[y][x]] == 6)
			{
				continue;
			}

			int DrawPosX = camera.ConvertPosXWorldToScreen(x * MapChipWidth);
			int DrawPosY = camera.ConvertPosYWorldToScreen(y * MapChipHeight);

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

void Map::GetContactParameter(EdgeType edge_, int chip_id_x_, int chip_id_y_, EdgeType& contact_edge_, int& contact_pos_)
{
	int ChipPosX = chip_id_x_ * MapChipWidth;
	int ChipPosY = chip_id_y_ * MapChipHeight;

	switch (edge_)
	{
	case Left:
		contact_edge_ = EdgeType::Right;
		contact_pos_ = ChipPosX + MapChipWidth;
		break;
	case Right:
		contact_edge_ = EdgeType::Left;
		contact_pos_ = ChipPosY;
		break;
	case Top:
		contact_edge_ = EdgeType::Bottom;
		contact_pos_ = ChipPosY + MapChipHeight;
		break;
	case Bottom:
		contact_edge_ = EdgeType::Top;
		contact_pos_ = ChipPosY;
		break;
	}
}

bool Map::CheckHit(int left_, int top_, int right_, int bottom_, int vector_x_, int vector_y_, EdgeType& contact_egde_, int contact_edge_pos_)
{
	StageID number_ = StageID_1;

	Data(number_);

	int RectLeft = left_;
	int RectTop = top_;
	int RectBottom = bottom_;
	int RectRight = right_;

	RectLeft += vector_x_;
	RectTop += vector_y_;
	RectBottom += vector_y_;
	RectRight += vector_x_;

	RectRight -= 1;
	RectBottom -= 1;

	int WidthRangeIDs[]
	{
		(int)(RectLeft / MapChipWidth),
		(int)(RectRight / MapChipWidth)
	};

	int HeightRangeIDs[]
	{
		(int)(RectTop / MapChipHeight),
		(int)(RectBottom / MapChipHeight)
	};

	const int MaxRangeIDs[]
	{
		MaxMapHeight - 1,
		MaxMapWidth - 1,
	};

	for (int i = 0; i < 2; i++)
	{
		Clamp(&HeightRangeIDs[i], 0, MaxRangeIDs[0]);
		Clamp(&WidthRangeIDs[i], 0, MaxRangeIDs[1]);
	}

	const int start = 0;
	const int end = 1;

	int EdgeListX[(int)EdgeType::Max][2]
	{
		{
			int(WidthRangeIDs[start]), int(WidthRangeIDs[start])
		},
		{
			int(WidthRangeIDs[end]), int(WidthRangeIDs[end])
		},
		{
			int(WidthRangeIDs[start]), int(WidthRangeIDs[end])
		},
		{
			int(WidthRangeIDs[start]), int(WidthRangeIDs[end])
		},
	};

	int EdgeListY[(int)EdgeType::Max][2]
	{
		{
			int(HeightRangeIDs[start]), int(HeightRangeIDs[end])
		},
		{
			int(HeightRangeIDs[start]), int(HeightRangeIDs[end])
		},
		{
			int(HeightRangeIDs[start]), int(HeightRangeIDs[start])
		},
		{
			int(HeightRangeIDs[end]), int(HeightRangeIDs[end])
		},
	};

	bool IsUseEdgeList[(int)EdgeType::Max]
	{
		vector_x_ < 0 ? true : false,
		vector_x_ > 0 ? true : false,
		vector_y_ < 0 ? true : false,
		vector_y_ > 0 ? true : false,
	};

	for (int i = 0; i < (int)EdgeType::Max; i++)
	{
		if (IsUseEdgeList[i] == false)
		{
			continue;
		}

		for (int y = EdgeListY[i][start]; y <= EdgeListY[i][end]; y++)
		{
			for (int x = EdgeListX[i][start]; x <= EdgeListX[i][start]; x++)
			{
				if (Info1[y][x] == 0 || Info1[y][x] == 2)
				{
					GetContactParameter((EdgeType)i, x, y, contact_egde_, contact_edge_pos_);

					return true;
				}
			}
		}
	}

	return false;
}
