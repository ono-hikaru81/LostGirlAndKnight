#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "SceneBase.h"

class InGameScene :public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Exec();
	virtual void Draw();

	void InitTexture();
	void ReleaseTexture();
	void InitPos();
	virtual bool IsEnd() const;

private:
	int Bg_Grass;
	int Bg_Grass2;
	int Bg_Grass3;
	int Bg_Forest;
	int Bg_Forest2;
	int Bg_Forest3;
	int Bg_Cave;
	int Bg_Cave2;
	int Bg_GameClear;
	int Bg_GameOver;

	static const int m_SlimeNumberMax = 50;
	static const int m_SkullNumberMax = 50;
	static const int m_OrcNumberMax = 50;
	static const int m_BridgeNumberMax = 50;
	static const int m_BottonNumberMax = 50;
	static const int m_RockNumberMax = 50;
	static const int m_BrockNumberMax = 50;
	static const int m_TrapNumberMax = 50;
	int m_PosxSl[m_SlimeNumberMax] = {3840,720,1080,3120,1920,2040,2160,2280,2400,2520,2740,2860,2980,3100,3220, 960,1080,1200,3120, 720,1080,3260,3600,5160 };
	int m_PosySl[m_SlimeNumberMax] = { 770,770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770, 650, 650, 770, 770};
	int m_PosxSk[m_SkullNumberMax] = {1440,1440, 3600,4680,5040,2760,3000,4080,4200,4440,4680,4920,5260,2520,3000,4420,};
	int m_PosySk[m_SkullNumberMax] = { 770, 770,  290, 290,290 , 410, 770, 770, 770, 770, 770, 770, 770, 770, 770, 770,};
	int m_PosxOc[m_OrcNumberMax] = {1920,3000,3120,3480,4320,4560,5760,6000,1320,2040,4200,5280,5520,1320,1560,2040,1200,1440,1680,1920,2160,3260,5160,5520,1320,3960,4320, 720,1080,4800,};
	int m_PosyOc[m_OrcNumberMax] = { 750, 750, 750, 750, 510, 390, 750, 750, 390, 390, 750, 750, 750, 750, 750, 750, 750, 750, 750, 750, 750, 270, 150, 150, 750, 750, 750, 750, 750, 750,};
	int m_PosxBri[m_BridgeNumberMax] = {2040,3240, 960,3960, 840,2400,6120, 840,2400,1800,};
	int m_PosyBri[m_BridgeNumberMax] = { 960, 960, 960, 500, 960, 960, 360, 960, 960, 960,};
	int m_PosxBot[m_BottonNumberMax] = {2530,3720,1320 ,5160 ,6120,2160,2880,1440,2160,3960,1800,2760,6350,1440,2760,2280, };
	int m_PosyBot[m_BottonNumberMax] = { 930, 930, 930 , 450 , 930, 600, 690, 930, 930, 930, 930, 930, 330, 930, 930, 930,};
	int m_PosxRok[m_RockNumberMax]   = {1320,600,6720,3720,6480, };
	int m_PosyRok[m_RockNumberMax]   = { 600,600, 600, 600,   0,};
	int m_PosxBrk[m_BrockNumberMax]  = {2280,3240,1560,2800,2880,3960,4440,3480,6120,6480, };
	int m_PosyBrk[m_BrockNumberMax]  = { 850, 850, 730, 370, 730, 730, 490, 850, 730, 730,};
	int m_PosxTrp[m_TrapNumberMax]   = {1200,3360,3840, };
	int m_PosyTrp[m_TrapNumberMax]   = { 980, 410, 980,};

};

#endif // !INGAME_SCENE_H
