#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"
#include "../Stage/Map.h"
#include "../Character/Player.h"
#include "../Function/Camera.h"
#include "../Character/BlindGirl.h"
#include "../Main.h"
#include "../UI/UI.h"

static Camera camera;
static Girl girl;
static Player player;
static Map map;
static UI ui;
static StageID nextStage = StageID_1;

InGameScene::InGameScene()
{
	InitTexture();
	player.InitTexture();
	map.InitTexture();
	girl.InitTexture();
	ui.InitTexture();

	BgPosX = camera.ConvertPosXWorldToScreen(0);
	BgPosY = camera.ConvertPosYWorldToScreen(0);
}

InGameScene::~InGameScene()
{
	ReleaseTexture();
}

void InGameScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	camera.Update(player.m_PosX, player.m_Speed);

	player.Move();
//	player.CheckColliderToMap(player.m_PosX, player.m_PosY, g_Gravity, player.m_PosX, player.m_PosY, 180.0f, &player.m_JumpExec, map);
	girl.Move(player);
	

	if (GetKeyStatus(KEY_INPUT_1) == InputState::Pushed)
	{
		nextStage = StageID_1;
	}
	else if (GetKeyStatus(KEY_INPUT_2) == InputState::Pushed)
	{
		nextStage = StageID_2;
	}
	else if (GetKeyStatus(KEY_INPUT_3) == InputState::Pushed)
	{
		nextStage = StageID_3;
	}
	else if (GetKeyStatus(KEY_INPUT_4) == InputState::Pushed)
	{
		nextStage = StageID_4;
	}
	else if (GetKeyStatus(KEY_INPUT_5) == InputState::Pushed)
	{
		nextStage = StageID_5;
	}
	else if (GetKeyStatus(KEY_INPUT_6) == InputState::Pushed)
	{
		nextStage = StageID_6;
	}
	else if (GetKeyStatus(KEY_INPUT_7) == InputState::Pushed)
	{
		nextStage = StageID_7;
	}
	else if (GetKeyStatus(KEY_INPUT_8) == InputState::Pushed)
	{
		nextStage = StageID_8;
	}
	else if (GetKeyStatus(KEY_INPUT_9) == InputState::Pushed)
	{
		nextStage = StageID_9;
	}
	else if (GetKeyStatus(KEY_INPUT_F1) == InputState::Pushed)
	{
		nextStage = StageID_10;
	}
	else if (GetKeyStatus(KEY_INPUT_F2) == InputState::Pushed)
	{
		nextStage = StageID_11;
	}
	else if (GetKeyStatus(KEY_INPUT_F3) == InputState::Pushed)
	{
		nextStage = StageID_12;
	}

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed)
	{
		SceneManager::SetNextScene(SceneID_Result);
	}
}

void InGameScene::InitTexture()
{
	Bg = LoadGraph("Res/bg/1.png");
}

void InGameScene::Draw()
{
	if (nextStage == StageID_1)
	{
		DrawGraph(BgPosX, BgPosY, Bg, TRUE);
		map.Data(One);
	}
	else if (nextStage == StageID_2)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Two);
	}
	else if (nextStage == StageID_3)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Three);

	}
	else if (nextStage == StageID_4)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Four);
	}
	else if (nextStage == StageID_5)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Five);
	}
	else if (nextStage == StageID_6)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Six);
	}
	else if (nextStage == StageID_7)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Seven);
	}
	else if (nextStage == StageID_8)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Eight);
	}
	else if (nextStage == StageID_9)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Nine);
	}
	else if (nextStage == StageID_10)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Ten);

	}
	else if (nextStage == StageID_11)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Eleven);
	}
	else if (nextStage == StageID_12)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Twelve);
	}

	ui.Draw();
	map.Draw(camera);
	player.Draw(camera);
	girl.Draw(player,camera);
}

void InGameScene::ReleaseTexture()
{
	DeleteGraph(Bg);
}

bool InGameScene::IsEnd() const
{
	return (GetKeyStatus(KEY_INPUT_RETURN) == TRUE);
}
