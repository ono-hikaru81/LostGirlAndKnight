#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"

InGameScene::InGameScene()
{

}

InGameScene::~InGameScene()
{

}

void InGameScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene( SceneID_Result );
	}
}

void InGameScene::Draw()
{
	DrawString(20, 20, "InGameScene", GetColor(0, 0, 255));
}

bool InGameScene::IsEnd() const
{
	return (m_Step >= 120);
}
