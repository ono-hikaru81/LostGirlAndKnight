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
#include "../Gimmick/Gimmick.h"
#include "../Enemy/Slime.h"
#include "../Enemy/Skull.h"
#include "../Enemy/Orc.h"
#include "../Enemy/Vampire.h"
#include "../Enemy/Wolfman.h"
#include "../Enemy/Dragon.h"

static Camera camera;
static Girl girl;
static Player player;
static Map map;
static UI ui;
static Gimmick gimmick;
static Slime slime;
static Skull skull;
static Orc orc;
static Vampire vampire;
static Wolfman wolfman;
static Dragon dragon;
static StageID nextStage = StageID_1;

InGameScene::InGameScene()
{
	InitTexture();
	player.InitTexture();
	map.InitTexture();
	girl.InitTexture();
	ui.InitTexture();
	gimmick.InitTexture();
	slime.InitTexture();
	skull.InitTexture();
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
	//gimmick.BottonMove();
	//gimmick.BridgeMove();
	//gimmick.TrapMove();
	//gimmick.RockMove();
	slime.Exec();
	skull.Exec();
	orc.Exec(player.m_PosX);
	wolfman.Exec();


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

void InGameScene::Draw()
{
	int BgPosX = camera.ConvertPosXWorldToScreen(0);
	int BgPosY = camera.ConvertPosYWorldToScreen(0);
	int Bg2PosX = camera.ConvertPosXWorldToScreen(1920);
	int Bg3PosX = camera.ConvertPosXWorldToScreen(3840);
	int Bg4PosX = camera.ConvertPosXWorldToScreen(5760);
	int Bg5PosX = camera.ConvertPosXWorldToScreen(480);


	if (nextStage == StageID_1)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass, TRUE);
		map.Data(One);

		gimmick.BridgeDraw(camera, 2040, 960);
		gimmick.BottonDraw(camera, 2520, 930);
		gimmick.BridgeDraw(camera, 3240, 960);
		gimmick.BottonDraw(camera, 3720, 930);
		slime.Draw(camera, 3840, 770);
	}
	else if (nextStage == StageID_2)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass, TRUE);
		map.Data(Two);

		slime.Draw(camera, 720, 770);
		slime.Draw(camera, 1080, 770);
		gimmick.RockDraw(camera, 1320, 600);
		gimmick.BrockDraw(camera, 2280, 850);
		slime.Draw(camera, 3120, 770);
		gimmick.BrockDraw(camera, 3240, 850);
	}
	else if (nextStage == StageID_3)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass3, TRUE);
		map.Data(Three);

		gimmick.BridgeDraw(camera, 960, 960);
		gimmick.BottonDraw(camera, 1320, 930);
		skull.Draw(camera, 1440, 770);

		slime.Draw(camera, 1920, 770);
		slime.Draw(camera, 2040, 770);
		slime.Draw(camera, 2160, 770);
		slime.Draw(camera, 2280, 770);
		slime.Draw(camera, 2400, 770);
		slime.Draw(camera, 2520, 770);
		slime.Draw(camera, 2740, 770);
		slime.Draw(camera, 2860, 770);
		slime.Draw(camera, 2980, 770);
		slime.Draw(camera, 3100, 770);
		slime.Draw(camera, 3220, 770);
	}
	else if (nextStage == StageID_4)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Grass3, TRUE);
		map.Data(Four);

		gimmick.TrapDraw(camera, 1200, 890);
		skull.Draw(camera, 1440, 770);
		gimmick.TrapDraw(camera, 3360, 410);
		skull.Draw(camera, 3600, 290);
		gimmick.BridgeDraw(camera, 3960, 500);
	}
	else if (nextStage == StageID_5)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg5PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Cave, TRUE);
		map.Data(Five);
	}
	else if (nextStage == StageID_6)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Six);
	}
	else if (nextStage == StageID_7)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Seven);
	}
	else if (nextStage == StageID_8)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Eight);
	}
	else if (nextStage == StageID_9)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Nine);
	}
	else if (nextStage == StageID_10)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Ten);

	}
	else if (nextStage == StageID_11)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Eleven);
	}
	else if (nextStage == StageID_12)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
	
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Twelve);
	}

	ui.Draw();
	map.Draw(camera);
	player.Draw(camera);
	girl.Draw(player,camera);
}

void InGameScene::InitTexture()
{
	Bg_Grass = LoadGraph("Res/bg/Bg2.png");
	Bg_Grass2 = LoadGraph("Res/bg/1.png");
	Bg_Grass3 = LoadGraph("Res/bg/2.png");
	Bg_Forest = LoadGraph("Res/bg/forest.png");
	Bg_Forest2 = LoadGraph("Res/bg/forest goal.png");
	Bg_Forest3 = LoadGraph("Res/bg/forestÅ®city.png");
	Bg_Cave = LoadGraph("Res/bg/seamless cave.png");
	Bg_Cave2 = LoadGraph("Res/bg/cave goal.png");
	Bg_GameClear = LoadGraph("Res/bg/gameclear.png");
	Bg_GameOver = LoadGraph("Res/bg/gameover.png");
}

void InGameScene::ReleaseTexture()
{
	DeleteGraph(Bg_Grass);
	DeleteGraph(Bg_Grass2);
	DeleteGraph(Bg_Grass3);
	DeleteGraph(Bg_Forest);
	DeleteGraph(Bg_Forest2);
	DeleteGraph(Bg_Forest3);
	DeleteGraph(Bg_Cave);
	DeleteGraph(Bg_Cave2);
}

bool InGameScene::IsEnd() const
{
	return (GetKeyStatus(KEY_INPUT_RETURN) == TRUE);
}
