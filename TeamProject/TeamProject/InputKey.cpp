#include"DxLib.h"
#include"InputKey.h"

InputState KeyState[256];

InputState UpdateInputState(bool is_push, InputState state);

InputState UpdateInputState(bool is_push, InputState state)
{
	if (is_push == true)
	{
		if (state == InputState::Nohold)
		{
			return InputState::Pushed;
		}
		else if (state == InputState::Hold || state == InputState::Pushed)
		{
			return InputState::Hold;
		}
	}
	else
	{
		if (state == InputState::Hold || state == InputState::Pushed)
		{
			return InputState::Releasad;
		}
	}
}

bool IsKeyHold(int Key)
{
	if (Key < 0 || Key > 256)
	{
		return false;
	}
	return KeyState[256] == InputState::Hold ? true : false;
}

bool IsKeyPushed(int Key)
{
	if (Key < 0 || Key > 256)
	{
		return false;
	}
	else if (KeyState[Key] == InputState::Pushed)
	{
		return false;
	}
}

bool IsKeyReleased(int Key)
{
	if (Key < 0 || Key > 256)
	{
		return false;
	}
	else if (KeyState[Key] == InputState::Releasad)
	{
		return false;
	}
}
