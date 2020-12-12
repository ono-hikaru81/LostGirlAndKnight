#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"
#include "../Stage/Map.h"
#include "../Character/Player.h"
#include "../Character/BlindGirl.h"
#include "../Enemy/Slime.h"
#include "../Enemy/Skull.h"
#include "../Enemy/Orc.h"
#include "../Enemy/Wolfman.h"
#include "../Enemy/Vampire.h"
#include "../Enemy/Dragon.h"

Map map;

InGameScene::InGameScene()
{

}

InGameScene::~InGameScene()
{

}

void InGameScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed)
	{
		SceneManager::SetNextScene(SceneID_Result);
	}
}

void InGameScene::Draw()
{
	DrawString(20, 20, "InGameScene", GetColor(0, 0, 255));

	map.Data(One);
	map.Draw();
}

bool InGameScene::IsEnd() const
{
	return ( GetKeyStatus(KEY_INPUT_RETURN) == TRUE );
}
