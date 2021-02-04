#include "../Manager/GameManager.h"
#include "../Character/Player.h"
#include "../Scene/InGameScene.h"
#include "../Scene/StageSelectScene.h"

StageID GameManager::m_NextStageID = StageID_InValid;

GameManager::GameManager()
	:m_pStage( nullptr )
{
	SetNextStage(StageID_1);
	m_pStage = create_NextStage();
}

GameManager::~GameManager()
{
	delete m_pStage;
	m_pStage = nullptr;
}

void GameManager::Exec()
{
	if (m_pStage == nullptr) { return; }
	m_pStage->Data(m_NextStageID);
	if (m_pStage->IsClear())
	{
		delete m_pStage;
		m_pStage = create_NextStage();
	}
}

void GameManager::Draw()
{
}

void GameManager::SetNextStage(StageID next_)
{
	m_NextStageID = next_;
}

Map* GameManager::GetStage()
{
	Map *map = nullptr;

	return map;
}

Map* GameManager::create_NextStage()
{
	Map* next = nullptr;
	switch (m_NextStageID)
	{
	case StageID_1: next = new Map(); break;
	case StageID_2: next = new Map(); break;
	case StageID_3: next = new Map(); break;
	case StageID_4: next = new Map(); break;
	case StageID_5: next = new Map(); break;
	case StageID_6: next = new Map(); break;
	case StageID_7: next = new Map(); break;
	case StageID_8: next = new Map(); break;
	case StageID_9: next = new Map(); break;
	case StageID_10: next = new Map(); break;
	case StageID_11: next = new Map(); break;
	case StageID_12: next = new Map(); break;
	}
	return next;
}
