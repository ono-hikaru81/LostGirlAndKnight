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
};

#endif // !INGAME_SCENE_H
