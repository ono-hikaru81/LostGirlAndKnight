#include "StageSelectScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"
#include "../Function/Button.h"

static Button button;

StageSelectScene::StageSelectScene()
{
	InitTexture();
	button.InitTexture();
}

StageSelectScene::~StageSelectScene()
{

}

void StageSelectScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	button.Update();

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed)
	{
		SceneManager::SetNextScene(SceneID_InGame);
		ReleaseTexture();
	}
}

void StageSelectScene::InitTexture()
{
	BgTex = LoadGraph("Res/bg/forest.png");
}

void StageSelectScene::Draw()
{
	DrawGraph(0, 0, BgTex, TRUE);
	button.Draw();
	SetFontSize(64);
	DrawString(100, 980, "ENTER‚Å‘I‘ð", GetColor(255, 0, 0));
	SetFontSize(32);
}

void StageSelectScene::ReleaseTexture()
{
	DeleteGraph(BgTex);
	button.ReleaseTexture();
}

bool StageSelectScene::IsEnd() const
{
	return (GetKeyStatus(KEY_INPUT_RETURN) == TRUE);
}
