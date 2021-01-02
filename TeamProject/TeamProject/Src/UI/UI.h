#ifndef UI_H
#define UI_H

#include "../Character/Player.h"
#include "../Character/BlindGirl.h"

const int g_PlayerHpMax = 10;
const int g_GirlHpMax = 2;

class UI
{
public:
	UI();
	~UI();

	void Update();
	void Draw();
	void InitTexture();
	void ReleaseTexture();

private:
	int m_HpTex;
	int m_HpTexSize;
	static int m_PlayerHp[g_PlayerHpMax];
	static int m_GirlHp[g_GirlHpMax];
};

#endif // !UI_H
