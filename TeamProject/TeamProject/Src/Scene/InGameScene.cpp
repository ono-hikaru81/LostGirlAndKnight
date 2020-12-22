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
#include "../Gimmick/Gimmick.h"

static Player player;
static Girl girl;
static Slime slime;
static Skull skull;
static Orc orc;
static Wolfman wolfman;
static Vampire vampire;
static Dragon dragon;
static Gimmick gimmick;
static Map map;
static StageID nextStage = StageID_1;

InGameScene::InGameScene()
{
	static Slime Slimes[50];
	static Skull Skulls[50];
	static Orc Orcs[50];
	static Gimmick Bridges[50];
	static Gimmick Botton[50];
	static Gimmick Traps[50];
}

InGameScene::~InGameScene()
{

}

void InGameScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	player.Move();
	girl.Move();
	slime.Exec();
	skull.Exec();
	orc.Exec(player.m_PosX);
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
	else if (GetKeyStatus(KEY_INPUT_F3) == InputState::Pushed)
	{
		nextStage = StageID_12;
	}

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed)
	{
		SceneManager::SetNextScene(SceneID_Result);
	}

	if (GetKeyStatus(KEY_INPUT_D))
	{
		map.Speed += 240;
	}
	else if (GetKeyStatus(KEY_INPUT_A))
	{
		map.Speed -= 120;
	}
}

void InGameScene::Draw()
{
	DrawString(20, 20, "InGameScene", GetColor(0, 0, 255));
	int Bg = LoadGraph("Res/bg/1.png");

	if (nextStage == StageID_1)
	{
		DrawGraph(0, 0, Bg, TRUE);
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
		wolfman.Draw();
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
		vampire.Draw();
	}
	else if (nextStage == StageID_12)
	{
		DrawGraph(0, 0, Bg, TRUE);
		map.Data(Twelve);
		dragon.Draw();
	}

	map.Draw();
}

bool InGameScene::IsEnd() const
{
	return ( GetKeyStatus(KEY_INPUT_RETURN) == TRUE );
}
