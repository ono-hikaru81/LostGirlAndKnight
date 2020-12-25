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

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 60; x++)
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

int Map::CheckHit(int x_, int y_, int* MoveX, int* MoveY)
{
	int MapHitCheck(float X, float Y,
		float* MoveX, float* MoveY);
	float afX, afY;

	// �ړ��ʂ𑫂�
	afX = x_ + *MoveX;
	afY = y_ + *MoveY;

	// �����蔻��̂���u���b�N�ɓ������Ă��邩�`�F�b�N
	if (GetChipPos(afX, afY) == 1)
	{
		int blx, bty, brx, bby;

		// �������Ă�����ǂ��痣���������s��

		// �u���b�N�̏㉺���E�̍��W���Z�o
		blx = (float)((int)afX / MapChipWidth) * MapChipWidth;        // ���ӂ� X ���W
		brx = (float)((int)afX / MapChipWidth + 1) * MapChipWidth;    // �E�ӂ� X ���W

		bty = (float)((int)afY / MapChipHeight) * MapChipHeight;        // ��ӂ� Y ���W
		bby = (float)((int)afY / MapChipHeight + 1) * MapChipHeight;    // ���ӂ� Y ���W

		// ��ӂɓ������Ă����ꍇ
		if (*MoveY > 0)
		{
			// �ړ��ʂ�␳����
			*MoveY = bty - y_ - 1;

			// ��ӂɓ��������ƕԂ�
			return 3;
		}

		// ���ӂɓ������Ă����ꍇ
		if (*MoveY < 0)
		{
			// �ړ��ʂ�␳����
			*MoveY = bby - y_ + 1;

			// ���ӂɓ��������ƕԂ�
			return 4;
		}

		// ���ӂɓ������Ă����ꍇ
		if (*MoveX > 0)
		{
			// �ړ��ʂ�␳����
			*MoveX = blx - x_ - 1;

			// ���ӂɓ��������ƕԂ�
			return 1;
		}

		// �E�ӂɓ������Ă����ꍇ
		if (*MoveX < 0)
		{
			// �ړ��ʂ�␳����
			*MoveX = brx - x_ + 1;

			// �E�ӂɓ��������ƕԂ�
			return 2;
		}

		// �����ɗ�����K���Ȓl��Ԃ�
		return 4;
	}

	// �ǂ��ɂ�������Ȃ������ƕԂ�
	return 0;
}
