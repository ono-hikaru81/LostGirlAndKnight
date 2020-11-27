#include "DxLib.h"
#include "Processing.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "BlindGirl.h"

Processing::Processing()
{
}

Processing::~Processing()
{
}

void Processing::Game()
{
	girl.Move();
}

void Processing::Draw()
{
	girl.Draw();
}
