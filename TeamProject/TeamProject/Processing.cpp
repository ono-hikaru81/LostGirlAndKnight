#include "DxLib.h"
#include "Processing.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

Player player;

Processing::Processing()
{
}

Processing::~Processing()
{
}

void Processing::Game()
{
	player.Move();
}

void Processing::Draw()
{
	player.Draw();
}
