#include "StageSelectScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"

StageSelectScene::StageSelectScene()
{

}

StageSelectScene::~StageSelectScene()
{

}

void StageSelectScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene( SceneID_InGame );
	}
}

void StageSelectScene::Draw()
{
	DrawString(20, 20, "StageSelectScene", GetColor(0, 255, 0));
}

bool StageSelectScene::IsEnd() const
{
	return (m_Step >= 120);
}