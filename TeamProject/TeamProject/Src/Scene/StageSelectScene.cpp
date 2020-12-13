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
	int SelectGraph = LoadGraph("Res/bg/forest.png");

	DrawGraph(0, 0, SelectGraph, TRUE);
}

bool StageSelectScene::IsEnd() const
{
	return ( GetKeyStatus(KEY_INPUT_RETURN) == TRUE );
}