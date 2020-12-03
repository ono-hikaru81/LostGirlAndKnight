#include "TitleScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Exec()
{
	m_Step++;
	if ( m_Step >= 120 )
	{
		SceneManager::SetNextScene( SceneID_StageSelect );
	}
}

void TitleScene::Draw()
{
	DrawString(20, 20, "TitleScene", GetColor(255, 0, 0));
}

bool TitleScene::IsEnd() const
{
	return ( m_Step >= 120 );
}
