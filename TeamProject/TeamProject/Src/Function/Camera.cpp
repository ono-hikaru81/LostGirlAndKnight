#include "Camera.h"
#include "../Function/Input.h"
#include "DxLib.h"
#include "../Main.h"
#include "../Character/Player.h"

Camera::Camera()
{
	m_PosX = WindowWidth / 2;
	m_PosY = WindowHeight / 2;
}

Camera::~Camera()
{
}

void Camera::Update()
{
	if (GetKeyStatus(KEY_INPUT_D) == InputState::Hold)
	{
		m_PosX += 4;
	}
	else if (GetKeyStatus(KEY_INPUT_D) == InputState::Hold)
	{
		m_PosY -= 4;
	}

	if (m_PosX <= WindowHalfWidth)
	{
		m_PosX = WindowHalfWidth;
	}
	else if (m_PosX >= WindowWidth - WindowHalfWidth)
	{
		m_PosX = WindowWidth - WindowHalfWidth;
	}

	if (m_PosY <= WindowHalfHeight)
	{
		m_PosY = WindowHalfHeight;
	}
	else if (m_PosY >= WindowHeight - WindowHalfHeight)
	{
		m_PosY = WindowHeight - WindowHalfHeight;
	}
}

int Camera::ConvertPosXWorldToScreen(int x_)
{
	int OriginScreenPosX = m_PosX - WindowWidth / 2;

	int ScreenPosX = x_ - OriginScreenPosX;

	return ScreenPosX;
}

int Camera::ConvertPosYWorldToScreen(int y_)
{
	int OriginScreenPosY = m_PosY - WindowHeight / 2;

	int ScreenPosY = y_ - OriginScreenPosY;

	return ScreenPosY;
}
