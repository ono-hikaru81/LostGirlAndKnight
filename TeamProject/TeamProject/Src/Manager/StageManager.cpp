#include "StageManager.h"
#include "../Stage/StageBase.h"
#include "../Stage/Stage1.h"

StageID StageManager::m_NextStageID = StageID_InValid;

StageManager::StageManager()
	:m_pStage(nullptr)
{
	SetNextStage(StageID_1);
	m_pStage = create_NextStage();
}

StageManager::~StageManager()
{
	delete m_pStage;
	m_pStage = nullptr;
}

void StageManager::Exec()
{
	if (m_pStage == nullptr) { return; }
	m_pStage->Exec();
	if (m_pStage->IsEnd())
	{
		delete m_pStage;
		m_pStage = create_NextStage();
	}
}

void StageManager::Draw()
{
	if (m_pStage == nullptr) { return; }
	m_pStage->Draw();
}

void StageManager::SetNextStage(StageID next_)
{
	m_NextStageID = next_;
}

StageBase* StageManager::create_NextStage()
{
	StageBase* next = nullptr;
	switch (m_NextStageID)
	{
	case StageID_1: next = new Stage1(); break;
	}
	return next;
}
