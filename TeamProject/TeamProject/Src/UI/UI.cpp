#include "UI.h"
#include "DxLib.h"

UI::UI()
{
	InitTexture();

	m_HpTexSize = 120;
}

UI::~UI()
{
	ReleaseTexture();
}

void UI::Update()
{

}

void UI::Draw()
{
	for (int i = 0; i < g_PlayerHpMax; i++)
	{
		DrawGraph(m_HpTexSize * i, m_HpTexSize * 0, m_HpTex, TRUE);
	}
	
	for (int i = 0; i < g_GirlHpMax; i++)
	{
		DrawGraph(m_HpTexSize * i, m_HpTexSize * 1, m_HpTex, TRUE);
	}
}

void UI::InitTexture()
{
	m_HpTex =LoadGraph("Res/UI/Hp.png");
}

void UI::ReleaseTexture()
{
	DeleteGraph(m_HpTex);
}
