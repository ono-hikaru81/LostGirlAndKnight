#include "DxLib.h"
#include "Processing.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Bridge.h"

Player player;
Bridge bridge;

Processing::Processing()
{
}

Processing::~Processing()
{
}

void Processing::Game()
{
	player.Move();
	bridge.Move();
}

void Processing::Draw()
{
	player.Draw();
	bridge.Draw();
}
