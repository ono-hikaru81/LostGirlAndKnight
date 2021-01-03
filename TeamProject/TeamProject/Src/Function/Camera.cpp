#include "Camera.h"
#include "Input.h"
#include "DxLib.h"
#include "../Main.h"
#include "../Character/Player.h"

static Player player;

Camera::Camera()
{
	m_PosX = WindowHalfWidth;
	m_PosY = WindowHalfHeight;
}

Camera::~Camera()
{
}

void Camera::Update(int x_, int speed_)
{

	if (GetKeyStatus(KEY_INPUT_D) == InputState::Hold && x_ >= WindowHalfWidth)
	{
		m_PosX += speed_;
	}
	else if (GetKeyStatus(KEY_INPUT_A) == InputState::Hold && x_ <= FieldWidth - WindowHalfWidth)
	{
		m_PosX -= speed_;
	}

	if (m_PosX <= WindowHalfWidth)
	{
		m_PosX = WindowHalfWidth;
	}
	else if (m_PosX >= FieldWidth - WindowHalfWidth)
	{
		m_PosX = FieldWidth - WindowHalfWidth;
	}

	if (m_PosY <= WindowHalfHeight)
	{
		m_PosY = WindowHalfHeight;
	}
	else if (m_PosY >= FieldHeight - WindowHalfHeight)
	{
		m_PosY = FieldHeight - WindowHalfHeight;
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
