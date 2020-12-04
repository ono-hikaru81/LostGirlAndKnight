#include "Input.h"
#include "DxLib.h"

InputState KeyState[256];

InputState UpdateInputState(bool isPressed, InputState inputState)
{
	if (inputState == InputState::Invalid)return InputState::Invalid;

	if (isPressed)
	{
		if (inputState == InputState::NoHold)
		{
			return InputState::Pushed;
		}
		else if (inputState == InputState::Pushed || inputState == InputState::Hold)
		{
			return InputState::Hold;
		}
	}
	else
	{
		if (inputState == InputState::Pushed || inputState == InputState::Hold)
		{
			return InputState::Released;
		}
	}

	return InputState::NoHold;
}

int UpdateKeyState()
{
	char currentKeyState[256];

	if (GetHitKeyStateAll(currentKeyState) != 0)
	{
		return -1;
	}

	for (int i = 0; i < 256; i++)
	{
		KeyState[i] = UpdateInputState(currentKeyState[i], KeyState[i]);
	}

	return 0;
}

bool IsPushed(InputState state)
{
	return(state == Pushed);
}

InputState GetKeyStatus(int keyCode)
{
	return KeyState[keyCode];
}

void AlterKeyInputEnable(int keyCode)
{
	KeyState[keyCode] = (KeyState[keyCode] == InputState::Invalid) ? InputState::NoHold : InputState::Invalid;
}

