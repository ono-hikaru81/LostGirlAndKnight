#ifndef MAIN_H
#define MAIN_H

// =====================
// ウィンドウ縦幅、横幅
// =====================
const int WindowWidth  = 1920;	// 1920
const int WindowHeight = 1080;	// 1080
const int WindowHalfWidth = WindowWidth / 2;
const int WindowHalfHeight = WindowHeight / 2;

// =====================
// マップチップ縦幅、横幅
// =====================
const int MapChipWidth  = 120;
const int MapChipHeight = 120;

// =====================
// マップ縦幅、横幅
// =====================
const int MaxMapWidth = 60;
const int MaxMapHeight = 9;

// =====================
// フィールドサイズ縦幅、横幅
// =====================
const int FieldWidth = MapChipWidth * MaxMapWidth;
const int FieldHeight = MapChipHeight * MaxMapHeight;

// 重力
static int g_Gravity = 1;

#endif // !MAIN_H
