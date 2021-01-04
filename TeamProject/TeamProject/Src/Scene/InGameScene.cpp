﻿#include "InGameScene.h"
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
	orc.InitTexture();
	wolfman.InitTexture();
	vampire.InitTexture();
	dragon.InitTexture();
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
	girl.Move(player);
	
	gimmick.BottonMove();
	gimmick.BridgeMove();
	gimmick.TrapMove();
	gimmick.RockMove();
	slime.Exec();
	skull.Exec();
	orc.Exec(player);
	wolfman.Exec();
	vampire.Exec();

	dragon.Exec();

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

	if (nextStage == StageID_1)
	{
		if (player.m_PosX + 180 >= 4200)
		{
			nextStage = StageID_2;
			InitPos();
		}
	}
	else if (nextStage == StageID_2)
	{
		if (player.m_PosX + 180 >= 4200)
		{
			nextStage = StageID_3;
			InitPos();
		}
	}
	else if (nextStage == StageID_3)
	{
		if (player.m_PosX + 180 >= 3960)
		{
			nextStage = StageID_4;
			InitPos();
		}
	}
	else if (nextStage == StageID_4)
	{
		if (player.m_PosX + 180 >= 5760)
		{
			nextStage = StageID_5;
			InitPos();
		}
	}
	else if (nextStage == StageID_5)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_6;
			InitPos();
		}
	}
	else if (nextStage == StageID_6)
	{
		if (player.m_PosX + 180 >= 6120)
		{
			nextStage = StageID_7;
			InitPos();
		}
	}
	else if (nextStage == StageID_7)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_8;
			InitPos();
		}
	}
	else if (nextStage == StageID_8)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_9;
			InitPos();
		}
	}
	else if (nextStage == StageID_9)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_10;
			InitPos();
		}
	}
	else if (nextStage == StageID_10)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_11;
			InitPos();
		}
	}
	else if (nextStage == StageID_11)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_12;
			InitPos();
		}
	}
	else if (nextStage == StageID_12)
	{
		if (player.m_PosX + 180 >= 4400)
		{
			SceneManager::SetNextScene(SceneID_Result);
		}
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
		skull.Draw(camera, 4680, 290);
		skull.Draw(camera, 5040, 290);
		gimmick.BottonDraw(camera, 5160, 450);
	}
	else if (nextStage == StageID_5)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg5PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Cave, TRUE);
		map.Data(Five);

		gimmick.RockDraw(camera, 600, 600);
		slime.Draw(camera, 960, 770);
		slime.Draw(camera, 1080, 770);
		slime.Draw(camera, 1200, 770);
		orc.Draw(camera, 1920, 750);
		orc.Draw(camera, 3000, 750);
		orc.Draw(camera, 3120, 750);
		orc.Draw(camera, 3480, 750);
		orc.Draw(camera, 4320, 510);
		orc.Draw(camera, 4560, 390);
		orc.Draw(camera, 5760, 750);
		orc.Draw(camera, 6000, 750);
		gimmick.BottonDraw(camera, 6120, 930);
		gimmick.RockDraw(camera, 6720, 600);
	}
	else if (nextStage == StageID_6)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Six);

		orc.Draw(camera, 1320, 390);
		orc.Draw(camera, 2040, 390);
		gimmick.BottonDraw(camera, 2160, 600);
		skull.Draw(camera, 2760, 410);
		gimmick.BottonDraw(camera, 2880, 690);
		gimmick.BottonDraw(camera, 1440, 930);
		gimmick.BottonDraw(camera, 2160, 930);
		slime.Draw(camera, 3120, 770);
		gimmick.RockDraw(camera, 3720, 600);
		gimmick.BottonDraw(camera, 3960, 930);
		orc.Draw(camera, 4200, 750);
		orc.Draw(camera, 5280, 750);
		orc.Draw(camera, 5520, 750);
	}
	else if (nextStage == StageID_7)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Seven);

		gimmick.BridgeDraw(camera, 840, 960);
		orc.Draw(camera, 1320, 750);
		orc.Draw(camera, 1560, 750);
		gimmick.BottonDraw(camera, 1800, 930);
		orc.Draw(camera, 2040, 750);
		gimmick.BridgeDraw(camera, 2400, 960);
		gimmick.BottonDraw(camera, 2760, 930);
		skull.Draw(camera, 3000, 770);
		gimmick.TrapDraw(camera, 3840, 890);
		skull.Draw(camera, 4080, 770);
		wolfman.Draw(camera, wolfman.m_Posx, wolfman.m_Posy);
	}
	else if (nextStage == StageID_8)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Eight);

		if (player.m_PosX >= 960 || girl.m_PosX >= 960)
		{
			orc.Draw(camera, 1200, 750);
			orc.Draw(camera, 1440, 750);
			orc.Draw(camera, 1680, 750);
			orc.Draw(camera, 1920, 750);
			orc.Draw(camera, 2160, 750);
		}

		if (player.m_PosX >= 3840 || girl.m_PosX >= 3840)
		{
			skull.Draw(camera, 4200, 770);
			skull.Draw(camera, 4440, 770);
			skull.Draw(camera, 4680, 770);
			skull.Draw(camera, 4920, 770);
			skull.Draw(camera, 5160, 770);
		}
	}
	else if (nextStage == StageID_9)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Nine);

		slime.Draw(camera, 720, 770);
		slime.Draw(camera, 1080, 650);
		gimmick.BrockDraw(camera, 1560, 730);
		gimmick.BrockDraw(camera, 2880, 370);
		gimmick.BrockDraw(camera, 2880, 730);
		orc.Draw(camera, 3260, 270);
		slime.Draw(camera, 3240, 650);
		gimmick.BrockDraw(camera, 3960, 730);
		gimmick.BrockDraw(camera, 4440, 490);
		orc.Draw(camera, 5160, 150);
		orc.Draw(camera, 5520, 150);
		gimmick.BridgeDraw(camera, 6120, 360);
		gimmick.BottonDraw(camera, 6360, 330);
		gimmick.RockDraw(camera, 6480, 0);
	}
	else if (nextStage == StageID_10)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Ten);

		gimmick.BridgeDraw(camera, 840, 960);
		orc.Draw(camera, 1320, 750);
		gimmick.BottonDraw(camera, 1440, 930);
		gimmick.BridgeDraw(camera, 2400, 960);
		gimmick.BottonDraw(camera, 2760, 930);
		slime.Draw(camera, 3600, 770);
		orc.Draw(camera, 3960, 750);
		orc.Draw(camera, 4320, 750);
		vampire.Draw(camera, vampire.m_Posx, vampire.m_Posy);
	}
	else if (nextStage == StageID_11)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Eleven);

		orc.Draw(camera, 720, 750);
		orc.Draw(camera, 1080, 750);
		gimmick.BridgeDraw(camera, 1800, 960);
		gimmick.BottonDraw(camera, 2280, 930);
		skull.Draw(camera, 2520, 770);
		skull.Draw(camera, 3000, 770);
		gimmick.BrockDraw(camera, 3480, 850);
		skull.Draw(camera, 4420, 770);
		orc.Draw(camera, 4800, 750);
		slime.Draw(camera, 5160, 770);
		gimmick.BrockDraw(camera, 6120, 730);
		gimmick.BrockDraw(camera, 6480, 730);
	}
	else if (nextStage == StageID_12)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Twelve);

		dragon.Draw(camera, 2400, 360);
	}

	map.Draw(camera);
	ui.Draw();
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
	Bg_Forest3 = LoadGraph("Res/bg/forest��city.png");
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

void InGameScene::InitPos()
{
	player.m_PosX = 143;
	player.m_PosY = 780;
	camera.m_PosX = WindowHalfWidth;
	camera.m_PosY = WindowHalfHeight;
}

bool InGameScene::IsEnd() const
{
	return (GetKeyStatus(KEY_INPUT_RETURN) == TRUE);
}
