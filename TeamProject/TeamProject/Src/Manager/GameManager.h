#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../StageDifinition.h"
#include "../Singleton.h"

class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	~GameManager();

	void Exec();
	void Draw();

	static void SetNextStage(StageID next_);
	class Map* GetStage();

private:
	class Map* create_NextStage();

private:
	class Map* m_pStage;
	static StageID m_NextStageID;
};

#endif // !GAME_MANAGER_H
