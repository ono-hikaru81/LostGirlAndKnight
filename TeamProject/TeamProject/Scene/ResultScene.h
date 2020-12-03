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

	virtual bool IsEnd() const;
};

#endif // !RESULT_SCENE_H

