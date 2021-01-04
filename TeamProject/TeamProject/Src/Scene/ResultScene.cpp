#include "ResultScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"

ResultScene::ResultScene()
{
	InitTexture();
	m_Clear = true;
}

ResultScene::~ResultScene()
{
}

void ResultScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed)
	{
		SceneManager::SetNextScene(SceneID_Title);
		ReleaseTexture();
	}

	if (GetKeyStatus(KEY_INPUT_1) == InputState::Pushed)
	{
		m_Clear = true;
	}
	else if (GetKeyStatus(KEY_INPUT_2) == InputState::Pushed)
	{
		m_Clear = false;
	}
}

void ResultScene::InitTexture()
{
	m_ClearTex = LoadGraph("Res/bg/gameclear.png");
	m_OutTex = LoadGraph("Res/bg/gameover.png");
}

void ResultScene::Draw()
{
	if (m_Clear == true)
	{
		DrawGraph(0, 0, m_ClearTex, TRUE);
	}
	else if (m_Clear == false)
	{
		DrawGraph(0, 0, m_OutTex, TRUE);
	}
}

void ResultScene::ReleaseTexture()
{
	DeleteGraph(m_ClearTex);
	DeleteGraph(m_OutTex);
}

bool ResultScene::IsEnd() const
{
	return (GetKeyStatus(KEY_INPUT_RETURN) == TRUE);
}
