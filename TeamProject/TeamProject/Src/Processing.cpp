#include "DxLib.h"
#include "Processing.h"
#include "../Src/Stage/Map.h"
#include "../Src/Function/Input.h"
#include "../Src/Character/Player.h"
#include "../Src/Enemy/Orc.h"
#include "../Src/Character/BlindGirl.h"
#include "../Src/Gimmick/Gimmick.h"

Player player;
Orc orc;
Girl girl;
Gimmick gimmick;

Processing::Processing()
{
}

Processing::~Processing()
{
}

void Processing::Game()
{
	player.Move();
	gimmick.BridgeMove();
	gimmick.BottonMove();
	gimmick.TrapMove();
	orc.Exec();
}

void Processing::Draw()
{
	DrawMap();
	player.Draw();
	gimmick.BridgeDraw();
	gimmick.BottonDraw();
	gimmick.TrapDraw();
	orc.Draw();
}
