#include "DxLib.h"
#include "Processing.h"
#include "Map.h"
#include "Input.h"
#include "Player.h"
#include "Enemy.h"
#include "BlindGirl.h"
#include "Gimmick.h"

Player player;
Enemy enemy;
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
}

void Processing::Draw()
{
	DrawMap();
	player.Draw();
	gimmick.BridgeDraw();
	gimmick.BottonDraw();
	gimmick.TrapDraw();
}
