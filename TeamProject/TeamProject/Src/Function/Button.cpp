#include "Button.h"
#include "DxLib.h"
#include "../StageDifinition.h"
#include "Input.h"

Button::Button()
{
	Number1 = NULL;
	Number2 = NULL;
	Number3 = NULL;
	Number4 = NULL;
	Number5 = NULL;
	Number6 = NULL;
	Number7 = NULL;
	Number8 = NULL;
	Number9 = NULL;
	Number10 = NULL;
	Number11 = NULL;
	Number12 = NULL;

	TextureSizeX = 360;
	TextureSizeY = 360;

	SelectNum = 0;

	InitTexture();
}

Button::~Button()
{
	ReleaseTexture();
}

// メニュー項目の表示に必要な構造体を用意する
typedef struct
{
	int x, y;       // 座標格納用変数
} MenuElement_t;

// メニュー項目要素を5つ作る
MenuElement_t MenuElement[12] =
{
		{   96,   0},
		{  552,   0},
		{ 1008,   0},
		{ 1464,   0},
		{   96, 260},
		{  552, 260},
		{ 1008, 260},
		{ 1464, 260},
		{   96, 520},
		{  552, 520},
		{ 1008, 520},
		{ 1464, 520},
};

void Button::Update()
{
	if (GetKeyStatus(KEY_INPUT_RIGHT) == InputState::Pushed)
	{
		SelectNum = (SelectNum + 1) % 12; // 現在の選択項目を一つ右にずらす(ループする)
	}
	else if (GetKeyStatus(KEY_INPUT_LEFT) == InputState::Pushed)
	{
		SelectNum = (SelectNum + 11) % 12; // 現在の選択項目を一つ左にずらす(逆ループする)
	}

	if (GetKeyStatus(KEY_INPUT_RIGHT) == InputState::Pushed || GetKeyStatus(KEY_INPUT_LEFT) == InputState::Pushed)
	{
		for (int i = 0; i < 12; i++)
		{
			if (i == SelectNum)
			{
				MenuElement[i].x = MenuElement[i].x + 50;
			}
		}
	}
}

void Button::Draw()
{
	for (int i = 0; i < 12; i++)
	{
		DrawGraph(MenuElement[0].x,  MenuElement[0].y, Number1, TRUE);
		DrawGraph(MenuElement[1].x,  MenuElement[1].y, Number2, TRUE);
		DrawGraph(MenuElement[2].x,  MenuElement[2].y, Number3, TRUE);
		DrawGraph(MenuElement[3].x,  MenuElement[3].y, Number4, TRUE);
		DrawGraph(MenuElement[4].x,  MenuElement[4].y, Number5, TRUE);
		DrawGraph(MenuElement[5].x,  MenuElement[5].y, Number6, TRUE);
		DrawGraph(MenuElement[6].x,  MenuElement[6].y, Number7, TRUE);
		DrawGraph(MenuElement[7].x,  MenuElement[7].y, Number8, TRUE);
		DrawGraph(MenuElement[8].x,  MenuElement[8].y, Number9, TRUE);
		DrawGraph(MenuElement[9].x,  MenuElement[9].y, Number10, TRUE);
		DrawGraph(MenuElement[10].x, MenuElement[10].y, Number11, TRUE);
		DrawGraph(MenuElement[11].x, MenuElement[11].y, Number12, TRUE);
	}
}

void Button::InitTexture()
{
	Number1 = LoadGraph("Res/UI/1看板.png");
	Number2 = LoadGraph("Res/UI/2看板.png");
	Number3 = LoadGraph("Res/UI/3看板.png");
	Number4 = LoadGraph("Res/UI/4看板.png");
	Number5 = LoadGraph("Res/UI/5看板.png");
	Number6 = LoadGraph("Res/UI/6看板.png");
	Number7 = LoadGraph("Res/UI/7看板.png");
	Number8 = LoadGraph("Res/UI/8看板.png");
	Number9 = LoadGraph("Res/UI/9看板.png");
	Number10 = LoadGraph("Res/UI/10看板.png");
	Number11 = LoadGraph("Res/UI/11看板.png");
	Number12 = LoadGraph("Res/UI/12看板.png");
}

void Button::ReleaseTexture()
{
	DeleteGraph(Number1);
	DeleteGraph(Number2);
	DeleteGraph(Number3);
	DeleteGraph(Number4);
	DeleteGraph(Number5);
	DeleteGraph(Number6);
	DeleteGraph(Number7);
	DeleteGraph(Number8);
	DeleteGraph(Number9);
	DeleteGraph(Number10);
	DeleteGraph(Number11);
	DeleteGraph(Number12);
}
