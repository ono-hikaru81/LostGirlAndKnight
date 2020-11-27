#ifndef INPUT_H
#define INPUT_H

enum InputState
{
	Invalid = -1,
	NoHold,		// 押されていない状態
	Pushed,		// 押された瞬間
	Hold,		// 押されている状態
	Released	// 離された瞬間
};

// キーの入力情報を更新する
int UpdateKeyState();

bool IsPushed(InputState state);

// キーの入力状態を取得する
InputState GetKeyStatus(int key);

// キー入力の無効、有効切り替え
void AlterKeyInputEnable(int key);

#endif // !INPUT_H
