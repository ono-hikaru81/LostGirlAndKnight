
#ifndef INPUTKEY_H
#define INPUTKEY_H

enum InputState
{
	Nohold,
	Pushed,
	Hold,
	Releasad,
};

bool IsKeyHold(int Key);
bool IsKeyPushed(int Key);
bool IsKeyReleased(int Key);


#endif // !INPUTKEY_H
