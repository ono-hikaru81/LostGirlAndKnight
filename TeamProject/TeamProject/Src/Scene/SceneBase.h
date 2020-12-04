#ifndef SCENE_BASE_H
#define SCENE_BASE_H

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void Exec() = 0;
	virtual void Draw() = 0;

	virtual bool IsEnd() const = 0;

protected:
	int m_Step;
};

#endif // !SCENE_BASE_H

