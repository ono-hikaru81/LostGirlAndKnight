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
	orc.InitTexture();
	wolfman.InitTexture();
	vampire.InitTexture();
	dragon.InitTexture();
	orc.InitTexture();
}

InGameScene::~InGameScene()
{
	ReleaseTexture();
}

void InGameScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	camera.Update(player.m_PosX, player.m_Speed);

	slime.SetPos(m_PosxSl);
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

		gimmick.BridgeDraw(camera,m_PosxBri,m_PosyBri, 0);
		gimmick.BottonDraw(camera,m_PosxBot,m_PosyBot, 0,player);
		gimmick.BridgeDraw(camera,m_PosxBri,m_PosyBri, 1);
		gimmick.BottonDraw(camera,m_PosxBot,m_PosyBot, 1, player);
		slime.Draw(camera, m_PosxSl,m_PosySl,0);
		
	}
	else if (nextStage == StageID_2)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass, TRUE);
		map.Data(Two);

		//slime.Draw(camera,m_PosxSl,m_PosySl, 1);
		//slime.Draw(camera,m_PosxSl,m_PosySl, 2);
		gimmick.RockDraw(camera, m_PosxRok,m_PosyRok, 0);
		gimmick.BrockDraw(camera,m_PosxBrk,m_PosyBrk, 0);
		gimmick.BrockDraw(camera,m_PosxBrk,m_PosyBrk, 1);
		//slime.Draw(camera,m_PosxSl,m_PosySl, 3);
	}
	else if (nextStage == StageID_3)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass3, TRUE);
		map.Data(Three);

		gimmick.BridgeDraw(camera,m_PosxBri,m_PosyBri, 3);
		gimmick.BottonDraw(camera,m_PosxBot,m_PosyBot, 2, player);
		skull.Draw(camera, m_PosxSk, m_PosySk,0);

		//slime.Draw(camera,m_PosxSl,m_PosySl, 4);
		//slime.Draw(camera,m_PosxSl,m_PosySl, 5);
		//slime.Draw(camera,m_PosxSl,m_PosySl, 6);
		//slime.Draw(camera,m_PosxSl,m_PosySl, 7);
		//slime.Draw(camera,m_PosxSl,m_PosySl, 8);
		//slime.Draw(camera,m_PosxSl,m_PosySl, 9);
		//slime.Draw(camera,m_PosxSl,m_PosySl,10);
		//slime.Draw(camera,m_PosxSl,m_PosySl,11);
		//slime.Draw(camera,m_PosxSl,m_PosySl,12);
		//slime.Draw(camera,m_PosxSl,m_PosySl,13);
		//slime.Draw(camera,m_PosxSl,m_PosySl,14);
	}
	else if (nextStage == StageID_4)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Grass3, TRUE);
		map.Data(Four);


		gimmick.TrapDraw(camera, m_PosxTrp, m_PosyTrp, 0);
		skull.Draw(camera, m_PosxSk, m_PosySk, 1);
		gimmick.TrapDraw(camera, m_PosxTrp, m_PosyTrp, 1);
		skull.Draw(camera, m_PosxSk, m_PosySk, 2);
		gimmick.BridgeDraw(camera, m_PosxBri, m_PosyBri, 4);
		skull.Draw(camera, m_PosxSk, m_PosySk, 3);
		skull.Draw(camera, m_PosxSk, m_PosySk, 4);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosxBot,3,player);
	}
	else if (nextStage == StageID_5)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg5PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Cave, TRUE);
		map.Data(Five);

		gimmick.RockDraw(camera, m_PosxRok, m_PosyRok,1);
		slime.Draw(camera,m_PosxSl, m_PosySl, 15);
		slime.Draw(camera,m_PosxSl,m_PosySl,16);
		slime.Draw(camera,m_PosxSl,m_PosySl,17);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 0);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 1);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 2);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 3);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 4);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 5);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 6);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 7);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 4, player);
		gimmick.RockDraw(camera, m_PosxRok,m_PosyRok ,2);
	}
	else if (nextStage == StageID_6)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Six);

		orc.Draw(camera,m_PosxOc, m_PosyOc, 8);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 9);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 5, player);
		skull.Draw(camera, m_PosxSk, m_PosySk, 5);
		gimmick.BottonDraw(camera,m_PosxBot, m_PosyBot, 6, player);
		gimmick.BottonDraw(camera,m_PosxBot, m_PosyBot, 7, player);
		gimmick.BottonDraw(camera,m_PosxBot, m_PosyBot, 8, player);
		slime.Draw(camera, m_PosxSl, m_PosySl, 18);
		gimmick.RockDraw(camera, m_PosxRok, m_PosyRok, 3);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 9, player);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 10);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 11);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 12);
	}
	else if (nextStage == StageID_7)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Seven);

		gimmick.BridgeDraw(camera, m_PosxBri, m_PosyBri, 5);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 13);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 14);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 10, player);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 15);
		gimmick.BridgeDraw(camera, m_PosxBri, m_PosyBri, 6);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 11, player);
		skull.Draw(camera, m_PosxSk, m_PosySk, 6);
		gimmick.TrapDraw(camera, m_PosxTrp, m_PosyTrp, 2);
		skull.Draw(camera, m_PosxSk, m_PosySk, 7);
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
			orc.Draw(camera, m_PosxOc, m_PosyOc, 16);
			orc.Draw(camera, m_PosxOc, m_PosyOc, 17);
			orc.Draw(camera, m_PosxOc, m_PosyOc, 18);
			orc.Draw(camera, m_PosxOc, m_PosyOc, 19);
			orc.Draw(camera, m_PosxOc, m_PosyOc, 20);
		}

		if (player.m_PosX >= 3840 || girl.m_PosX >= 3840)
		{
			skull.Draw(camera, m_PosxSk, m_PosySk, 8);
			skull.Draw(camera, m_PosxSk, m_PosySk, 9);
			skull.Draw(camera, m_PosxSk, m_PosySk, 10);
			skull.Draw(camera, m_PosxSk, m_PosySk, 11);
			skull.Draw(camera, m_PosxSk, m_PosySk, 12);
		}
	}
	else if (nextStage == StageID_9)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Nine);

		slime.Draw(camera, m_PosxSl, m_PosySl, 19);
		slime.Draw(camera, m_PosxSl, m_PosySl, 20);
		gimmick.BrockDraw(camera, m_PosxBrk, m_PosyBrk, 2);
		gimmick.BrockDraw(camera,m_PosxBrk,m_PosyBrk, 3);
		gimmick.BrockDraw(camera,m_PosxBrk,m_PosyBrk, 4);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 21);
		slime.Draw(camera, m_PosxSl, m_PosySl, 21);
		gimmick.BrockDraw(camera,m_PosxBrk,m_PosyBrk, 5);
		gimmick.BrockDraw(camera,m_PosxBrk,m_PosyBrk, 6);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 22);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 23);
		gimmick.BridgeDraw(camera, m_PosxBri, m_PosyBri, 7);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 12, player);
		gimmick.RockDraw(camera, m_PosxRok, m_PosyRok, 4);
	}
	else if (nextStage == StageID_10)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Ten);

		gimmick.BridgeDraw(camera, m_PosxBri, m_PosyBri, 8);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 24);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 13, player);
		gimmick.BridgeDraw(camera, m_PosxBri, m_PosyBri, 9);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 14, player);
		slime.Draw(camera, m_PosxSl, m_PosySl, 22);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 25);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 26);
		vampire.Draw(camera, vampire.m_Posx, vampire.m_Posy);
	}
	else if (nextStage == StageID_11)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(Eleven);

		orc.Draw(camera,m_PosxOc, m_PosyOc, 27);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 28);
		gimmick.BridgeDraw(camera, m_PosxBri, m_PosyBri, 10);
		gimmick.BottonDraw(camera, m_PosxBot, m_PosyBot, 15, player);
		skull.Draw(camera, m_PosxSk, m_PosySk, 13);
		skull.Draw(camera, m_PosxSk, m_PosySk, 14);
		gimmick.BrockDraw(camera, m_PosxBrk, m_PosyBrk, 7);
		skull.Draw(camera, m_PosxSk, m_PosySk, 15);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 29);
		slime.Draw(camera, m_PosxSl, m_PosySl, 23);
		gimmick.BrockDraw(camera,m_PosxBrk,m_PosyBrk, 8);
		gimmick.BrockDraw(camera,m_PosxBrk,m_PosyBrk, 9);
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
