#include <stdio.h>
#include "DxLib.h"
#include "Difinition.h"
#include "../Src/Character/Player.h"
#include "Manager/SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ＤＸライブラリ初期化処理
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
//	SetGraphMode(WindowWidth, WindowHeight, 32);
	SetGraphMode(1800, 1800, 32);
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
	SceneManager* pSceneMng = new SceneManager();

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

		pSceneMng->Exec();

		pSceneMng->Draw();
		
		// =====================================================================
		// ＤＸライブラリを使う上で、モニターへゲーム画面を表示するためのお約束
		// 必ずループの最後で呼び出す
		// =====================================================================
		ScreenFlip();
	}
	delete pSceneMng;
	pSceneMng = nullptr;

	DxLib_End();			// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}