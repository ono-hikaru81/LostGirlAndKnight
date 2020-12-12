#include "StageSelectScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"

StageSelectScene::StageSelectScene()
{

}

StageSelectScene::~StageSelectScene()
{

}

void StageSelectScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed)
	{
		SceneManager::SetNextScene( SceneID_InGame );
	}
}

void StageSelectScene::Draw()
{
	int SelectGraph = LoadGraph("Res/bg/select.png");

	DrawString(20, 20, "StageSelectScene", GetColor(0, 255, 0));
	DrawGraph(0, 0, SelectGraph, TRUE);
}

bool StageSelectScene::IsEnd() const
{
	return ( GetKeyStatus(KEY_INPUT_RETURN) == TRUE );
}