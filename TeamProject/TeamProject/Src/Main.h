#ifndef MAIN_H
#define MAIN_H

// =====================
// �E�B���h�E�c���A����
// =====================
const int WindowWidth  = 1920;	// 1920
const int WindowHeight = 1080;	// 1080
const int WindowHalfWidth = WindowWidth / 2;
const int WindowHalfHeight = WindowHeight / 2;

// =====================
// �}�b�v�`�b�v�c���A����
// =====================
const int MapChipWidth  = 120;
const int MapChipHeight = 120;

// =====================
// �}�b�v�c���A����
// =====================
const int MaxMapWidth = 60;
const int MaxMapHeight = 9;

// =====================
// �t�B�[���h�T�C�Y�c���A����
// =====================
const int FieldWidth = MapChipWidth * MaxMapWidth;
const int FieldHeight = MapChipHeight * MaxMapHeight;

// �d��
static int g_Gravity = 1;

#endif // !MAIN_H
