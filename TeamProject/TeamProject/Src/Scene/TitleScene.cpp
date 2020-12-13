#include "TitleScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed)
	{
		SceneManager::SetNextScene(SceneID_StageSelect);
	}
}

void TitleScene::Draw()
{
	int TitleGraph = LoadGraph("Res/bg/title.png");

	DrawGraph(0, 0, TitleGraph, TRUE);

	DrawString(960, 540, "Title", GetColor(255, 0, 0));
	DrawString(960, 980, "PLEASE PUSH ENTER", GetColor(255, 0, 0));
}

bool TitleScene::IsEnd() const
{
	return (GetKeyStatus(KEY_INPUT_RETURN) == TRUE);
}

