#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "SceneBase.h"

class InGameScene :public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Exec();
	virtual void InitTexture();
	virtual void Draw();
	virtual void ReleaseTexture();

	virtual bool IsEnd() const;

private:
	int Bg;
	int i;

	int BgPosX;
	int BgPosY;
};

#endif // !INGAME_SCENE_H
