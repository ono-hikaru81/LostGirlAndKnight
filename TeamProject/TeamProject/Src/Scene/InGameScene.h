#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "SceneBase.h"

enum StageID
{
	StageID_1,
	StageID_2,
	StageID_3,
	StageID_4,
	StageID_5,
	StageID_6,
	StageID_7,
	StageID_8,
	StageID_9,
	StageID_10,
	StageID_11,
	StageID_12,

	StageID_Max,
	StageID_InValid
};

class InGameScene :public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool IsEnd() const;

private:
	int i;
	int WorldMapPosX;
	int WorldMapPosY;
	int ScreenMapPosX;
	int ScreenMapPosY;
};

#endif // !INGAME_SCENE_H
