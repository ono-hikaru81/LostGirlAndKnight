#ifndef INPUT_H
#define INPUT_H

enum InputState
{
	Invalid = -1,
	NoHold,		// ������Ă��Ȃ����
	Pushed,		// �����ꂽ�u��
	Hold,		// ������Ă�����
	Released	// �����ꂽ�u��
};

// �L�[�̓��͏����X�V����
int UpdateKeyState();

bool IsPushed(InputState state);

// �L�[�̓��͏�Ԃ��擾����
InputState GetKeyStatus(int key);

// �L�[���̖͂����A�L���؂�ւ�
void AlterKeyInputEnable(int key);

#endif // !INPUT_H
