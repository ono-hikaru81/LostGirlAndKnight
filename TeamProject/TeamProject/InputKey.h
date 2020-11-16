#ifndef INPUTKEY_H
#define INPUTKEY_H

#include <dinput.h>

enum InputState
{
	NoHold,
	Pushed,
	Hold,
	Released,
};

bool InputInit();
void InputRelease();
void InputUpdate();

bool IsKeyHeld(int key);
bool IsKeyPushed(int key);
bool IsKeyReleased(int key);

#endif // !INPUTKEY_H
