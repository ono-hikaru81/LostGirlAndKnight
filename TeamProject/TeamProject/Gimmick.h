
#ifndef GIMMICK_H
#define GIMMICK_H

class Gimmick
{
public:
	int m_BridgeDraw;		//木の画像保存
	int m_Angle;
	float m_Radian;
	bool m_BridgeExec;

	int m_ActTrap;
	static const int m_TrapMax = 3;
	int m_Traps[m_TrapMax];			//トラップの画像保存
	int m_TrapMotion[m_TrapMax] = {0,1,2};	//トラップのアニメーション
	bool m_TrapExec;

	int m_ActBotton;
	static const int m_BottonMax = 2;
	int m_Bottons[m_BottonMax];	//ボタンの画像保存
	bool m_BottonExec;

public:
	Gimmick();
	~Gimmick();

public:
	void BridgeMove();
	void BridgeDraw();

	void BottonMove();
	void BottonDraw();//最終的にbool CheckHit()に移行

	void TrapMove();
	void TrapDraw();//最終的にbool CheckHit()に移行

public:
	bool CheckHit();
};



#endif // !GIMMICK_H
