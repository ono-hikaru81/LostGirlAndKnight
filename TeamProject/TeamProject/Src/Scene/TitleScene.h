#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "SceneBase.h"

class TitleScene :public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Exec();
	virtual void InitTexture();
	void Draw();
	void ReleaseTexture();

	virtual bool IsEnd() const;

private:
	int TitleGraph;
};

#endif // !TITLE_SCENE_H
