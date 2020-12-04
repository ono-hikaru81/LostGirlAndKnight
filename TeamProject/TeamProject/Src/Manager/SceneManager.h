#include "../Difinition.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Exec();
	void Draw();

	static void SetNextScene(SceneID next_);

private:
	class SceneBase* create_NextScene();

private:
	class SceneBase* m_pScene;
	static SceneID m_NextSceneID;
};