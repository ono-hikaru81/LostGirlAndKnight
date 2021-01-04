#ifndef STAGE_SELECT_SCENE_H
#define STAGE_SELECT_SCENE_H

#include "SceneBase.h"

class StageSelectScene :public SceneBase
{
public:
	StageSelectScene();
	virtual ~StageSelectScene();

	virtual void Exec();
	virtual void InitTexture();
	void Draw();
	void ReleaseTexture();

	virtual bool IsEnd() const;

private:
	int BgTex;
};

#endif // !STAGE_SELECT_SCENE_H
