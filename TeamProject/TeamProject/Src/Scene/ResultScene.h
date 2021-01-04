#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "SceneBase.h"

class ResultScene :public SceneBase
{
public:
	ResultScene();
	virtual ~ResultScene();

	virtual void Exec();
	virtual void Draw();
	void InitTexture();
	void ReleaseTexture();

	virtual bool IsEnd() const;

private:
	int m_ClearTex;
	int m_OutTex;
	bool m_Clear;
};

#endif // !RESULT_SCENE_H
