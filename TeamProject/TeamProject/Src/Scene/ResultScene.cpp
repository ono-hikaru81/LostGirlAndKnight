#include "ResultScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"

ResultScene::ResultScene()
{

}

ResultScene::~ResultScene()
{

}

void ResultScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Title);
	}
}

void ResultScene::InitTexture()
{
}

void ResultScene::Draw()
{
	DrawString(20, 20, "ResultScene", GetColor(255, 255, 0));
}

void ResultScene::ReleaseTexture()
{
}

bool ResultScene::IsEnd() const
{
	return (m_Step >= 120);
}
