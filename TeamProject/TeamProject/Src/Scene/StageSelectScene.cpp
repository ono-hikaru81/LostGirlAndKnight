#include "StageSelectScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"
#include "../Function/Button.h"

static Button button;

StageSelectScene::StageSelectScene()
{
	SelectGraph = LoadGraph("Res/bg/forest.png");
	button.InitTexture();
}

StageSelectScene::~StageSelectScene()
{
	button.ReleaseTexture();
}

void StageSelectScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	if (GetKeyStatus(KEY_INPUT_SPACE) == InputState::Pushed)
	{
		SceneManager::SetNextScene(SceneID_Title);
		DeleteGraph(SelectGraph);
	}

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
	button.Draw();
	SetFontSize(64);
	DrawString(100, 980, "ENTER‚Å‘I‘ð", GetColor(255, 0, 0));
	SetFontSize(32);
}

void StageSelectScene::ReleaseTexture()
{
}

bool StageSelectScene::IsEnd() const
{
	return (GetKeyStatus(KEY_INPUT_RETURN) == TRUE);
}
