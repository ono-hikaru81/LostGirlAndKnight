#include "StageSelectScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"

StageSelectScene::StageSelectScene()
{
	SelectGraph = LoadGraph("Res/bg/forest.png");
}

StageSelectScene::~StageSelectScene()
{

}

void StageSelectScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed)
	{
		SceneManager::SetNextScene(SceneID_InGame);
		DeleteGraph(SelectGraph);
	}
}

void StageSelectScene::InitTexture()
{
}

void StageSelectScene::Draw()
{
	DrawGraph(0, 0, SelectGraph, TRUE);
}

void StageSelectScene::ReleaseTexture()
{
}

bool StageSelectScene::IsEnd() const
{
	return (GetKeyStatus(KEY_INPUT_RETURN) == TRUE);
}
