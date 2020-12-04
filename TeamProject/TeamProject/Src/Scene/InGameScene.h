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

	virtual bool IsEnd() const;
};

#endif // !INGAME_SCENE_H
