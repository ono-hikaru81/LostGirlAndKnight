#ifndef FADE_H
#define FADE_H

//==============================
//�t�F�[�h�N���X
//==============================
class Fade
{
public:
	int m_alpha;
	bool m_isFading;
	int m_fadeType;

public:
	Fade();
	virtual~Fade();
	void Start(enum FadeType fadeType_);			// �t�F�[�h�̎�ނ����߂�
	void Draw();							// ��`��`�悷��֐�
	void Exec(float fadeSpeed_);			// �t�F�[�h���������s
	bool IsFading();						// �t�F�[�h���I��������ǂ���
};

enum FadeType
{
	fadeIn,
	fadeOut
};

enum FadeScene
{
	Wait,
	FadeIn,
	FadeOut
};


#endif // !FADE_H
