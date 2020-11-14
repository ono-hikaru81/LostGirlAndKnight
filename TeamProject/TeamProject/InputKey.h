
#ifndef INPUTKEY_H
#define INPUTKEY_H

enum InputState
{
	Nohold,
	Pushed,
	Hold,
	Releasad,
};

bool InputGetKey(int Key);
bool InputGetKeyUp(int Key);
bool InputGetKeyDown(int Key);


#endif // !INPUTKEY_H
