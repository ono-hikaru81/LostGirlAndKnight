#ifndef BLINDGIRL
#define BLINDGIRL

class Girl
{
public:
	// �X�e�[�^�X
	int m_Hp;
	int m_Speed;

	// �ʒu���W
	int m_PosX;
	int m_PosY;

	// �Ǘ��ϐ�
	int m_count;

	// ���s�m�F
	bool m_StopExec;
	bool m_WalkExec;
	bool m_JumpExec;

private:
	// �摜�ۑ�
	int m_WaitGraph;
	int m_WalkGraph;
	int m_JumpGraph;

public:
	Girl();
	virtual ~Girl();

public:
	void Move();
	void Draw();
};

#endif // !BLINDGIRL
