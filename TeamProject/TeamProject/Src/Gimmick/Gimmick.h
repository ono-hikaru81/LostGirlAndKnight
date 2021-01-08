
#ifndef GIMMICK_H
#define GIMMICK_H

#include "../Function/Camera.h"
#include"../Character/Player.h"

class Gimmick
{
public:
	static const int m_Max = 50;//すべての座標配列の最大値

	int m_BridgeDraw;		//木の画像保存
	float m_Angle[m_Max];
	float m_Radian[m_Max];
	int m_BridgePosX[m_Max];
	int m_BridgePosY[m_Max];
	bool m_IsPush[m_Max];

	int m_Trap[m_Max];
	static const int m_TrapMax = 3;
	int m_Traps[m_TrapMax];			//トラップの画像保存
	int m_TrapMotion[m_TrapMax] = {0,1,2};	//トラップのアニメーション
	int m_TrapPosX[m_Max];
	int	m_TrapPosY[m_Max];
	bool m_TrapHit[m_Max];

	int m_Botton;
	static const int m_BottonMax = 2;
	int m_Bottons[m_BottonMax];	//ボタンの画像保存
	int m_BottonPosX[m_Max];
	int m_BottonPosY[m_Max];
	bool m_BottonHit[m_Max];

	int m_Rock[m_Max];
	static const int m_RockMax = 3;
	int m_Rocks[m_RockMax];
	int m_RockPosX[m_Max];
	int m_RockPosY[m_Max];
	int m_RockHit[m_Max];
	
	int m_BrockTex;
	int m_BrockPosX[m_Max];
	int m_BrockPosY[m_Max];

	bool m_num[m_Max];//仮変数
public:
	Gimmick();
	~Gimmick();

public:
	void InitTexture();
	void ReleaseTexture();

	void BridgeMove(int x_,int y_ ,int number);
	void BridgeDraw(Camera camera, int number);

	void BottonMove(int x1_ ,int y1_ ,int number);
	void BottonDraw(Camera camera,int number);//最終的にbool CheckHit()に移行

	void TrapMove(int x_,int y_ ,int number);
	void TrapDraw(Camera camera, int number);//最終的にbool CheckHit()に移行

	void RockMove(int x_,int y_,int number);
	void RockDraw(Camera camera, int number);

	void BrockExec(int x_, int y_, int number);
	void BrockDraw(Camera camera, int number);

	void GetArray(int ArrayX_[],int ArrayY_[],int BridgeX_[],int BridgeY_[],int TrapX_[],int TrapY_[],int RockX_[], int RockY_[],int BrockX_[], int BrockY_[]);
public:
	bool CheckHit();
	bool BottonCheckHit(int x1_,int y1_,int number);
	bool BridgeCheckHit(int x_, int y_, int number);
	bool TrapCheckHit(int x_, int y_, int number);
	bool RockCheckHit(int x_, int y_, int number);
	bool BrockCheckHit(int x_, int y_, int number);
};



#endif // !GIMMICK_H
