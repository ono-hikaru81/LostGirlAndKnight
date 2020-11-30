#include <stdio.h>
#include "DxLib.h"
#include "Main.h"
#include "Processing.h"
#include"Player.h"

Processing processing;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ＤＸライブラリ初期化処理
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(FALSE);
	SetGraphMode(WindowWidth, WindowHeight, 32);
	SetBackgroundColor(0, 0, 120);
	SetMainWindowText("井本組のゲーム");
	if (DxLib_Init() == -1)
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// ===============
	// 各種初期化処理
	// ===============

	// =============================
	// 以下、毎フレーム更新する処理
	// =============================
	
	

	// =============
	// メインループ
	// =============
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ＤＸライブラリを使う上で、１フレーム分の処理を始めるためのお約束
		// ----------------------------------------------------
		ClearDrawScreen();
		clsDx();

		// =================
		// 処理関数呼び出し
		// =================
		processing.Game();

		processing.Draw();
		
		// =====================================================================
		// ＤＸライブラリを使う上で、モニターへゲーム画面を表示するためのお約束
		// 必ずループの最後で呼び出す
		// =====================================================================
		ScreenFlip();
	}

	WaitKey();				// キー入力待ち

	DxLib_End();			// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}